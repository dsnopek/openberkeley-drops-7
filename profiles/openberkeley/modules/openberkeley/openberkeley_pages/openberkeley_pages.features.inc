<?php
/**
 * @file
 * openberkeley_pages.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function openberkeley_pages_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
  if ($module == "panelizer" && $api == "panelizer") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function openberkeley_pages_node_info() {
  $items = array(
    'openberkeley_content_page' => array(
      'name' => t('Content Page'),
      'base' => 'node_content',
      'description' => t('An important page to display to users on your site.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'openberkeley_landing_page' => array(
      'name' => t('Landing Page'),
      'base' => 'node_content',
      'description' => t('A primary landing page to display to users on your site.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
