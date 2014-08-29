#!/bin/bash
#
# Run this script on a site that's just had it's code switched from -beta4
# to version 0.1 of Open Berkeley.
#

ALIAS=$1
if [ x$ALIAS = x ]; then
  echo "Must pass a drush alias as the first argument, for example: @mytest.dev"
  exit 1
fi

DRUSH=${DRUSH:-drush}
DRUSH_OPTS=${DRUSH_OPTS:---strict=0}

# New cache tables. There's known issues with clearing caches before a new cache
# table can get created, and we do some magic below to work around them.
NEW_CACHE_TABLES="cache_panels cache_search_api_solr cache_entity_fieldable_panels_pane"

# Pantheon has an 'input screener' on what it allows you to do over SSH, and 
# using 'drush sqlq' runs afoul of it! Here is some hyper-magic to allow us to
# execute SQL on Patheon (and locally).
drush_sqlq() {
  local MYSQL_CONNECT=`$DRUSH $DRUSH_OPTS $ALIAS sql-connect`
  echo "$1" | $MYSQL_CONNECT
}

# After some period of time, Pantheon rotates the username/password on the
# database, so we need to update your Drush aliases. This depends on having
# installed and authenticated with Terminus:
#
#   https://github.com/pantheon-systems/terminus
#
$DRUSH $DRUSH_OPTS pantheon-aliases

# Switch profile from 'panopoly' to 'openberkeley'. Unfortunately, drush won't
# be able to bootstrap Drupal ('drush vset' will error out) so we have to set
# this variable directly in the database.
drush_sqlq "UPDATE variable SET value = 's:12:\"openberkeley\";' WHERE name = 'install_profile'"

# In a moment, we're going to call 'drush rr' which will clear all caches at
# the very end. Unfortunately, this will try to clear some new cache tables that
# haven't been created yet.
for CACHE_TABLE in $NEW_CACHE_TABLES; do
  drush_sqlq "CREATE TABLE $CACHE_TABLE ( cid VARCHAR(255) NOT NULL PRIMARY KEY, data LONGBLOB, expire INT NOT NULL DEFAULT 0, created INT NOT NULL DEFAULT 0, serialized SMALLINT NOT NULL DEFAULT 0 )"
done

# Clear the code registry and all caches so Drupal can find the new locations
# of all modules.
$DRUSH $DRUSH_OPTS $ALIAS rr

# Drop the new cache tables so they can be created for real in the updates.
for CACHE_TABLE in $NEW_CACHE_TABLES; do
  drush_sqlq "DROP TABLE $CACHE_TABLE"
done

# This is necessary to get the openberkely_update_N() functions to run!
drush_sqlq "UPDATE system SET status = 1, schema_version = 0 WHERE name = 'openberkeley'"

# Run the update functions.
$DRUSH $DRUSH_OPTS $ALIAS updb -y

# And... run them again! When something fails (which happens some percentage of
# the time on Pantheon), running again will re-run those failures.
$DRUSH $DRUSH_OPTS $ALIAS updb -y

# Revert all Features.
$DRUSH $DRUSH_OPTS $ALIAS fra -y

# Now that we've upgraded, we can remove the 'mediafield' module - it was used
# by panopoly_widgets in older versions. We need to run cron a couple times to
# get the field actually purged.
$DRUSH $DRUSH_OPTS $ALIAS cron
$DRUSH $DRUSH_OPTS $ALIAS cron
$DRUSH $DRUSH_OPTS $ALIAS dis -y mediafield || (
  echo
  echo "**"
  echo "** ERROR: We were unable to disable 'mediafield' automatically."
  echo "**"
  echo "** You'll have to wait for cron to run a few times, and then disable"
  echo "** it manually yourself."
  echo "**"
  echo
)

# One final cache clear to hopefully fix the issue where /admin/content
# is giving 'Page not found' and any other cache-y issuse.
$DRUSH $DRUSH_OPTS $ALIAS cc all

# Tell the user what to do next.
echo 
echo "**"
echo "** Enabling panopoly_search via Drush fails because it can't contact the"
echo "** SOLR server (it's on the internal Pantheon network)."
echo "**"
echo "** So, you need to:"
echo "**  (1) Login to the site and enable 'Panopoly Search' via the UI."
echo "**  (2) Clear all caches (can be done via UI or drush)."
echo "**  (3) Index all the content (go to: /admin/config/search/search_api)."
echo "**"
echo

