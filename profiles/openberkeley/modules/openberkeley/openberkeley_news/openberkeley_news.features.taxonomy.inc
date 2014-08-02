<?php
/**
 * @file
 * openberkeley_news.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function openberkeley_news_taxonomy_default_vocabularies() {
  return array(
    'openberkeley_news_type' => array(
      'name' => 'News type',
      'machine_name' => 'openberkeley_news_type',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
  );
}
