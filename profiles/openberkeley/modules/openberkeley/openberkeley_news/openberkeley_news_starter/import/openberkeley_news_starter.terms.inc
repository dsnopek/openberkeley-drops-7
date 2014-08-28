<?php

/**
 * @file
 * Migrations for Menu items.
 */

class OpenBerkeleyNewsStarterTerms extends Migration {
  public function __construct($arguments = array()) {
    parent::__construct($arguments = array());
    $this->description = t('Import taxonomy terms.');

    // Create a map object for tracking the relationships between source rows.
    $this->map = new MigrateSQLMap($this->machineName,
      array(
        'tid' => array(
          'type' => 'int',
          'unsigned' => TRUE,
          'not null' => TRUE,
          'description' => 'ID of destination term',
        ),
      ),
      MigrateDestinationTerm::getKeySchema()
    );

    $import_path = drupal_get_path('module', 'openberkeley_news_starter') . '/import/data/';

    // Create a MigrateSource object.
    $this->source = new MigrateSourceCSV($import_path . 'openberkeley_news_starter.terms.csv', NULL, array('header_rows' => 1));

    $language = LANGUAGE_NONE;
    $text_format = 'panopoly_wysiwyg_text';
    $term_options = MigrateDestinationTerm::options($language, $text_format);
    $this->destination = new MigrateDestinationTerm('field_openberkeley_news_type', $term_options);

    $this->addSimpleMappings(array('name', 'description', 'format','weight'));

    $this->addUnmigratedDestinations(array('vid', 'uuid'));
  }
}
