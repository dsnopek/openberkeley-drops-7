<?php

/**
 * @file
 * Migrations for Basic Nodes.
 */

class OpenBerkeleyNewsStarterNodePages extends Migration {
  public function __construct($arguments = array()) {
    parent::__construct($arguments = array());
    $this->description = t('Import Content Pages.');
    //$this->dependencies = array('OpenBerkeleyNewsStarterTerms');
    // Create a map object for tracking the relationships between source rows.
    $this->map = new MigrateSQLMap($this->machineName,
      array(
        'title' => array(
          'type' => 'varchar',
          'length' => 255,
          'not null' => TRUE,
        ),
      ),
      MigrateDestinationNode::getKeySchema()
    );

    $import_path = drupal_get_path('module', 'openberkeley_news_starter') . '/import/data/';

    // Create a MigrateSource object.
    $this->source = new MigrateSourceCSV($import_path . 'openberkeley_news_starter.pages.csv', $this->csvcolumns(), array('header_rows' => 1));

    $this->destination = new MigrateDestinationNode('openberkeley_news_item');

    $this->addFieldMapping('uid')->defaultValue(1);
    $this->addFieldMapping('status')->defaultValue(1);
    $this->addFieldMapping('language')->defaultValue(LANGUAGE_NONE);
    $this->addFieldMapping('field_featured_status')->defaultValue(0);
    $this->addFieldMapping('title', 'title');
    $this->addFieldMapping('body', 'body');
    $this->addFieldMapping('body:format')->defaultValue('editor');
    $this->addFieldMapping('field_openberkeley_news_byline', 'byline');
    $this->addFieldMapping('field_openberkeley_news_xlink', 'external link');
    $this->addFieldMapping('field_openberkeley_news_type', 'news type');
    $this->addFieldMapping('field_openberkeley_news_type:create_term')
      ->defaultValue(TRUE);
    $this->addFieldMapping('field_openberkeley_news_source', 'source');
    $this->addFieldMapping('field_openberkeley_news_pdate', 'publication date');
  }

  protected function csvcolumns() {
    $columns[0] = array('title', 'Title');
    $columns[1] = array('body', 'Body');
    $columns[2] = array('byline', 'Byline');
    $columns[3] = array('external link', 'External Link');
    $columns[4] = array('news type', 'News Type');
    $columns[5] = array('source', 'Source');
    $columns[6] = array('publication date', 'Publication Date');
    return $columns;
  }

  function postRollback() {
    /*
     * Since we are using "lazy" term creation in this migration:
     *   $this->addFieldMapping('field_openberkeley_news_type:create_term')
     *     ->defaultValue(TRUE);
     * we can't "rollback" the term we created. Instead we delete it if no
     * other nodes are using it.
     */
    $term_name = "General";
    $term = taxonomy_get_term_by_name($term_name, 'news_type');
    if (count($term) > 1) {
      drupal_set_message("Multiple $term_name terms in the news_type vocabulary. Aborting clean up of starter content terms.");
      return;
    }
    $term_obj = array_pop($term);
    $tid = $term_obj->tid;
    if (!empty($tid)) {
      $nodeQuery = new EntityFieldQuery();
      $entities = $nodeQuery->entityCondition('entity_type', 'node')
        ->entityCondition('bundle', 'openberkeley_news_item')
        ->fieldCondition('field_news_type', 'tid', $tid)
        ->execute();
      if (count($entities) == 0) {
        // If no nodes are associated with the General term defined by this
        // starter module, delete the term.
        taxonomy_term_delete($tid);
      }
    }
  }
}
