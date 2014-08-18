#!/bin/sh
# Script to rebuild the Open Berkeley installation profile
# This command expects to be run within the Open Berkeley profile (./rebuild.sh from profiles/openberkeley)
# To use this command you must have `drush make` and `git` installed.

##############
# FUNCTIONS #
##############
# Always declare bash functions at the top of the script (or before they are called).
function make_tests() {
    test_dirs=( openberkeley_tests/behat/features/panopoly openberkeley_tests/behat/features/bootstrap modules/panopoly/panopoly_test/tests/features modules/panopoly/panopoly_test/tests/features/bootstrap openberkeley_tests/patches )
    for testdir in "${test_dirs[@]}"
    do
      if [ ! -d  "$testdir" ] || [ ! -w "$testdir" ]; then
        echo "ERROR: $testdir doesn't exist or isn't writable. Aborting creation of Open Berkeley tests.\n"
        exit 1
      fi
    done
    cp modules/panopoly/panopoly_test/tests/features/*.feature openberkeley_tests/behat/features/panopoly/
    cp modules/panopoly/panopoly_test/tests/features/bootstrap/PanopolyContext.php openberkeley_tests/behat/features/bootstrap/
    patch_dir=openberkeley_tests/patches
    for file in "$patch_dir"/*
    do
      patch -p3 < "$file"
    done
}

##########
# SCRIPT #
##########

if [ -f openberkeley-prod.make ] || [ -f openberkeley-dev.make ]; then
  echo '   ____                       ____               __          __'
  echo '  / __ \ ____   ___   ____   / __ ) ___   _____ / /__ ___   / /___   __  __'
  echo ' / / / // __ \ / _ \ / __ \ / __  |/ _ \ / ___// //_// _ \ / // _ \ / / / /'
  echo '/ /_/ // /_/ //  __// / / // /_/ //  __// /   / ,<  /  __// //  __// /_/ /'
  echo '\____// .___/ \___//_/ /_//_____/ \___//_/   /_/|_| \___//_/ \___/ \__, /'
  echo '     /_/                                                          /____/'
  echo "\nThis command can be used to rebuild the installation profile in place.\n"
  echo "  [1] Rebuild profile in production mode (openberkeley-prod.make)"
  echo "  [2] Rebuild profile in development mode (openberkeley-dev.make)"
  echo "  [3] Clean and rebuild in development mode (openberkeley-dev.make)"
  # Note: We do NOT want to clean and rebuild production until it uses openberkeley features bc it will remove ucb_cas and subdirectories
  # echo "  [4] Clean and rebuild in production mode (openberkeley-prod.make)"
  # echo "  [5] Check to see if drush is installed"
  echo "\nSelection: \c"
  read SELECTION

  # a space delimited bash array
  cleanup_dirs=( libraries modules themes );

  if [ $SELECTION = "1" ]; then

    echo "Building Open Berkeley install profile in production mode..."
    drush -y make --no-core --contrib-destination=. openberkeley-prod.make

  elif [ $SELECTION = "2" ]; then    

    echo "Building Open Berkeley install profile in development mode..."
    drush -y make --no-core --contrib-destination=. openberkeley-dev.make
    make_tests

  elif [ $SELECTION = "3" ]; then
    echo "Cleaning and rebuilding Open Berkeley install profile in development mode..."

    for dir in "${cleanup_dirs[@]}"
    do
      if [ -d "$dir" ] && [ -w "$dir" ]; then
        echo "Removing $dir..."
        rm -rf $dir/* # pesky dotfiles can thwart us...
        rmdir $dir
      else
        echo "Either not a directory or not writable: $dir"
      fi
    done
    drush -y make --no-core --contrib-destination=. openberkeley-dev.make
    make_tests

  else
   echo "Invalid selection."
  fi
else
  echo 'Could not locate file "openberkeley-prod.make" or "openberkeley-dev.make"'
fi
