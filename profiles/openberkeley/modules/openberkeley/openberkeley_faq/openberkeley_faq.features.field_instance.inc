<?php
/**
 * @file
 * openberkeley_faq.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function openberkeley_faq_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'node-faq-field_openberkeley_faq_cat'
  $field_instances['node-faq-field_openberkeley_faq_cat'] = array(
    'bundle' => 'faq',
    'default_value' => array(
      0 => array(
        'tid' => 1,
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'taxonomy',
        'settings' => array(),
        'type' => 'taxonomy_term_reference_link',
        'weight' => 3,
      ),
      'featured' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 1,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_openberkeley_faq_cat',
    'label' => 'Category',
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 34,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Category');

  return $field_instances;
}
