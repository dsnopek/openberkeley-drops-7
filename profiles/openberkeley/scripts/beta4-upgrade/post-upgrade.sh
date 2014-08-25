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

# Pantheon has an 'input screener' on what it allows you to do over SSH, and 
# using 'drush sqlq' runs afoul of it! Here is some hyper-magic to allow us to
# execute SQL on Patheon (and locally).
drush_sqlq() {
  local MYSQL_CONNECT=`$DRUSH $ALIAS sql-connect`
  echo "$1" | $MYSQL_CONNECT
}

# After some period of time, Pantheon rotates the username/password on the
# database, so we need to update your Drush aliases. This depends on having
# installed and authenticated with Terminus:
#
#   https://github.com/pantheon-systems/terminus
#
$DRUSH pantheon-aliases

# Switch profile from 'panopoly' to 'openberkeley'. Unfortunately, drush won't
# be able to bootstrap Drupal ('drush vset' will error out) so we have to set
# this variable directly in the database.
drush_sqlq "UPDATE variable SET value = 's:12:\"openberkeley\";' WHERE name = 'install_profile'"

# In a moment, we're going to call 'drush rr' which will clear all caches at
# the very end. Unfortunately, this will try to clear some new cache tables that
# haven't been created yet.
for CACHE_TABLE in $NEW_CACHE_TABLES; do
  drush_sqlq "CREATE TABLE $CACHE_TABLE ( cid int )"
done

# Clear the code registry and all caches so Drupal can find the new locations
# of all modules.
$DRUSH $ALIAS rr

drush_sqlq "UPDATE system SET status = 1, schema_version = 0 WHERE name = 'openberkeley'"

# Drop the new cache tables so they can be created for real in the updates.
for CACHE_TABLE in $NEW_CACHE_TABLES; do
  drush_sqlq "DROP TABLE $CACHE_TABLE"
done

# Run the update functions.
$DRUSH $ALIAS updb -y

