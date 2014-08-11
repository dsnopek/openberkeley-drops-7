<?php

/**
 * @file
 * Migrations for Basic Nodes.
 */

class OpenBerkeleyFaqStarterNodePages extends Migration {
  public function __construct($arguments = array()) {
    parent::__construct($arguments = array());
    $this->description = t('Import FAQ nodes.');
    //$this->dependencies = array('OpenBerkeleyFaqStarterTerms');
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

    $import_path = drupal_get_path('module', 'openberkeley_faq_starter') . '/import/data/';

    // Create a MigrateSource object.
    $this->source = new MigrateSourceCSV($import_path . 'openberkeley_faq_starter.pages.csv', $this->csvcolumns(), array('header_rows' => 1));

    $this->destination = new MigrateDestinationNode('faq');

    $this->addFieldMapping('uid')->defaultValue(1);
    $this->addFieldMapping('status')->defaultValue(1);
    $this->addFieldMapping('language')->defaultValue(LANGUAGE_NONE);
    $this->addFieldMapping('field_featured_status')->defaultValue(0);
    $this->addFieldMapping('title', 'title');
    $this->addFieldMapping('body', 'body');
    $this->addFieldMapping('body:format')->defaultValue('editor');
    $this->addFieldMapping('field_openberkeley_faq_cat', 'category');
    $this->addFieldMapping('field_openberkeley_faq_cat:create_term')
      ->defaultValue(TRUE);
    $this->addFieldMapping('field_detailed_question', 'detailed question');
    $this->addFieldMapping('field_detailed_question:format')->defaultValue('editor');
  }

  protected function csvcolumns() {
    $columns[0] = array('title', 'Title');
    $columns[1] = array('category', 'Category');
    $columns[2] = array('detailed question', 'Detailed Question');
    $columns[3] = array('body', 'Answer');
    return $columns;
  }

  function postRollback() {
    /*
     * Since we are using "lazy" term creation in this migration:
     *   $this->addFieldMapping('field_openberkeley_faq_type:create_term')
     *     ->defaultValue(TRUE);
     * we can't "rollback" the term we created. Instead we delete it if no
     * other nodes are using it.
     */
    $term_name = "Specific";
    $term = taxonomy_get_term_by_name($term_name, 'faqs');
    if (count($term) > 1) {
      drupal_set_message("Multiple $term_name terms in the FAQ_type vocabulary. Aborting clean up of starter content terms.");
      return;
    }
    $term_obj = array_pop($term);
    $tid = $term_obj->tid;
    if (!empty($tid)) {
      $nodeQuery = new EntityFieldQuery();
      $entities = $nodeQuery->entityCondition('entity_type', 'node')
        ->entityCondition('bundle', 'faq')
        ->fieldCondition('field_openberkeley_faq_cat', 'tid', $tid)
        ->execute();
      if (count($entities) == 0) {
        // If no nodes are associated with the General term defined by this
        // starter module, delete the term.
        taxonomy_term_delete($tid);
      }
    }
  }
}
