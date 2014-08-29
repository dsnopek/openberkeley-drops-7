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

# After some period of time, Pantheon rotates the username/password on the
# database, so we need to update your Drush aliases. This depends on having
# installed and authenticated with Terminus:
#
#   https://github.com/pantheon-systems/terminus
#
$DRUSH $DRUSH_OPTS pantheon-aliases

# Clear the code registry and all caches so Drupal can find the new locations
# of all modules.
$DRUSH $DRUSH_OPTS $ALIAS rr

# Run the update functions.
$DRUSH $DRUSH_OPTS $ALIAS updb -y

# And... run them again! When something fails (which happens some percentage of
# the time on Pantheon), running again will re-run those failures.
$DRUSH $DRUSH_OPTS $ALIAS updb -y

# Revert all Features.
$DRUSH $DRUSH_OPTS $ALIAS fra -y

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

