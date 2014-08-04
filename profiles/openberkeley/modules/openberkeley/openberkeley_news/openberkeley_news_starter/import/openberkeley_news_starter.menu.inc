<?php

/**
 * @file
 * Migrations for Menu items.
 */

class OpenBerkeleyNewsStarterMenu extends Migration {
  public function __construct($arguments = array()) {
    parent::__construct($arguments = array());
    $this->description = t('Import menu items.');
    $this->dependencies = array('OpenBerkeleyNewsStarterNodePages');

    // Create a map object for tracking the relationships between source rows.
    $this->map = new MigrateSQLMap($this->machineName,
      array(
        'mlid' => array(
          'type' => 'int',
          'unsigned' => TRUE,
          'not null' => TRUE,
          'description' => 'ID of destination link',
        ),
      ),
      MigrateDestinationMenuLinks::getKeySchema()
    );

    $import_path = drupal_get_path('module', 'openberkeley_news_starter') . '/import/data/';

    // Create a MigrateSource object.
    $this->source = new MigrateSourceCSV($import_path . 'openberkeley_news_starter.menu.csv', $this->csvcolumns(), array('header_rows' => 1));

    $this->destination = new MigrateDestinationMenuLinks();

    $this->addFieldMapping('menu_name', 'menu_name');
    $this->addFieldMapping('plid', 'ref_parent')->sourceMigration($this->getMachineName());
    $this->addFieldMapping('link_path', 'path');
    $this->addFieldMapping('router_path')->defaultValue('node/%');
    $this->addFieldMapping('link_title', 'title');
    $this->addFieldMapping('external')->defaultValue('0');
    $this->addFieldMapping('expanded')->defaultValue('0');
    $this->addFieldMapping('weight','weight');
    $this->addFieldMapping('customized')->defaultValue('1');
    $this->addFieldMapping('has_children')->defaultValue('0');
    $this->addFieldMapping('depth')->defaultValue('1');

    $this->addUnmigratedDestinations(array('module', 'hidden','options','p1', 'p2', 'p3', 'p4', 'p5', 'p6', 'p7', 'p8', 'p9', 'updated'));
  }

  function prepareRow($row) {
    if ($row->path != '<front>' && !preg_match('/https?:\/\//', $row->path)) {
      // Convert the alias to the node path.
      $node_path = drupal_lookup_path('source', $row->path);
      if ($node_path !== FALSE) {
        $row->path = $node_path;
      }
      if (($node_path === FALSE)  && (!drupal_valid_path($row->path))) {
        // if the node path can't be resolved, make sure drupal_valid_path_fails
        // too.  If drupal_valid_path doesn't fail, this might be a path defined
        // at admin/structure/pages. e.g. news-archive is defined there by
        // the news feature.
        return FALSE;
      }
    }
  }

  protected function csvcolumns() {
    $columns[0] = array('mlid', 'Menu link ID');
    $columns[1] = array('menu_name', 'Menu name');
    $columns[2] = array('path', 'Path');
    $columns[3] = array('title', 'Title');
    $columns[4] = array('ref_parent', 'Parent');
    $columns[5] = array('weight', 'Weight');
    return $columns;
  }
}
