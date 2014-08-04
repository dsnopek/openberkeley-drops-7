<?php
/**
 * @file
 * openberkeley_faq.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function openberkeley_faq_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_openberkeley_faq_cat'
  $field_bases['field_openberkeley_faq_cat'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_openberkeley_faq_cat',
    'foreign keys' => array(
      'tid' => array(
        'columns' => array(
          'tid' => 'tid',
        ),
        'table' => 'taxonomy_term_data',
      ),
    ),
    'indexes' => array(
      'tid' => array(
        0 => 'tid',
      ),
    ),
    'locked' => 0,
    'module' => 'taxonomy',
    'settings' => array(
      'allowed_values' => array(
        0 => array(
          'vocabulary' => 'faqs',
          'parent' => 0,
        ),
      ),
    ),
    'translatable' => 0,
    'type' => 'taxonomy_term_reference',
  );

  return $field_bases;
}
