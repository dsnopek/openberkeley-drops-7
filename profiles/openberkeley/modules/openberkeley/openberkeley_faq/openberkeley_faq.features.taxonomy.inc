<?php
/**
 * @file
 * openberkeley_faq.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function openberkeley_faq_taxonomy_default_vocabularies() {
  return array(
    'faqs' => array(
      'name' => 'FAQs',
      'machine_name' => 'faqs',
      'description' => 'Categories for Frequently Asked Questions.',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
  );
}
