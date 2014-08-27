#!/bin/bash
#
# Run this script on a site that's going to be upgraded from -beta4 to
# Open Berkeley 0.1, but run it BEFORE actually updating the code.
#

ALIAS=$1
if [ x$ALIAS = x ]; then
  echo "Must pass a drush alias as the first argument, for example: @mytest.dev"
  exit 1
fi

DRUSH=${DRUSH:-drush}
DRUSH_OPTS=${DRUSH_OPTS:---strict=0}

OLD_MODULES="panopoly_demo panopoly_admin panopoly_pages entity_view_mode better_formats conditional_styles views_slideshow_cycle views_slideshow ucb_openberkeley"

for MODULE in $OLD_MODULES; do
  $DRUSH $DRUSH_OPTS $ALIAS dis -y $MODULE
done

for MODULE in $OLD_MODULES; do
  $DRUSH $DRUSH_OPTS $ALIAS pm-uninstall -y $MODULE
done

