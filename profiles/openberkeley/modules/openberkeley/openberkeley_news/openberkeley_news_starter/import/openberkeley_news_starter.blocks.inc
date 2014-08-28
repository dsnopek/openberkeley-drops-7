<?php

/**
 * @file
 * Migrations for Blocks.
 */

class OpenBerkeleyNewsStarterBlocks extends Migration {
  public function __construct($arguments = array()) {
    parent::__construct($arguments = array());
    $this->description = t('Import custom blocks.');
    $this->dependencies = array();

    // Create a map object for tracking the relationships between source rows.
    $this->map = new MigrateSQLMap($this->machineName,
      array(
        'title' => array(
          'type' => 'varchar',
          'length' => 255,
          'not null' => TRUE,
        ),
      ),
      MigrateDestinationCustomBlock::getKeySchema()
    );

    $import_path = drupal_get_path('module', 'openberkeley_news_starter') . '/import/data/';

    // Create a MigrateSource object.
    $this->source = new MigrateSourceCSV($import_path . 'openberkeley_news_starter.blocks.csv', $this->csvcolumns(), array('header_rows' => 1));

    // NOTE: This depends on Dave Reid's patch on issue #2224297.
    $this->destination = new MigrateDestinationCustomBlock();

    $this->addFieldMapping('info', 'title');
    $this->addFieldMapping('body', 'body');
    $this->addFieldMapping('format')->defaultValue('panopoly_wysiwyg_text');
  }

  protected function csvcolumns() {
    $columns[0] = array('title', 'Title');
    $columns[1] = array('body', 'Body');
    return $columns;
  }
}
