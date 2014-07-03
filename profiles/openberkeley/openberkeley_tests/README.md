openberkeley_tests
==================

Behat tests for Open Berkeley, including config, features, and step definitions.

Setup
-----

 1. Install Composer

    php -r "eval('?>'.file_get_contents('https://getcomposer.org/installer'));"

 2. Install Behat and dependencies via Composer

    php composer.phar install

 3. Copy behat.template.yml to behat.yml

    mv behat.template.yml behat.yml

 4. Edit behat.yml: change base_url and drush alias parameters to your local values

 5. Download the latest version of Selenium Server from http://docs.seleniumhq.org/download/ to /usr/local/lib

 6. Install PhantomJS:

    brew install phantomjs


Browsers
---------------------

To run Selenium (required for @javascript tests):

java -jar /usr/local/lib/selenium-server-standalone-2.40.0.jar

Since Firefox bombs out on tests involving contenteditable regions,
  we set the default browser to Chrome

To run PhantomJS (required for @headless tests):

phantomjs --webdriver=8643


Running tests
-------------

To run all tests (except headless):

bin/behat

To run all tests except javascript (and headless):

bin/behat --tags=~@javascript

To run headless tests:

bin/behat -p headless

Currently there are no tests tagged @headless.

