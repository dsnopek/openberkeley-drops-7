<?php
/**
 * @file
 * openberkeley_faq.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function openberkeley_faq_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'administer faq'.
  $permissions['administer faq'] = array(
    'name' => 'administer faq',
    'roles' => array(
      'administrator' => 'administrator',
      'builder' => 'builder',
    ),
    'module' => 'faq',
  );

  // Exported permission: 'administer faq order'.
  $permissions['administer faq order'] = array(
    'name' => 'administer faq order',
    'roles' => array(
      'administrator' => 'administrator',
      'builder' => 'builder',
      'editor' => 'editor',
    ),
    'module' => 'faq',
  );

  // Exported permission: 'administer panelizer node faq breadcrumbs'.
  $permissions['administer panelizer node faq breadcrumbs'] = array(
    'name' => 'administer panelizer node faq breadcrumbs',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'panelizer',
  );

  // Exported permission: 'administer panelizer node faq content'.
  $permissions['administer panelizer node faq content'] = array(
    'name' => 'administer panelizer node faq content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'panelizer',
  );

  // Exported permission: 'administer panelizer node faq context'.
  $permissions['administer panelizer node faq context'] = array(
    'name' => 'administer panelizer node faq context',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'panelizer',
  );

  // Exported permission: 'administer panelizer node faq defaults'.
  $permissions['administer panelizer node faq defaults'] = array(
    'name' => 'administer panelizer node faq defaults',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'panelizer',
  );

  // Exported permission: 'administer panelizer node faq layout'.
  $permissions['administer panelizer node faq layout'] = array(
    'name' => 'administer panelizer node faq layout',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'panelizer',
  );

  // Exported permission: 'administer panelizer node faq overview'.
  $permissions['administer panelizer node faq overview'] = array(
    'name' => 'administer panelizer node faq overview',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'panelizer',
  );

  // Exported permission: 'administer panelizer node faq settings'.
  $permissions['administer panelizer node faq settings'] = array(
    'name' => 'administer panelizer node faq settings',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'panelizer',
  );

  // Exported permission: 'administer panelizer taxonomy_term faqs breadcrumbs'.
  $permissions['administer panelizer taxonomy_term faqs breadcrumbs'] = array(
    'name' => 'administer panelizer taxonomy_term faqs breadcrumbs',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'panelizer',
  );

  // Exported permission: 'administer panelizer taxonomy_term faqs content'.
  $permissions['administer panelizer taxonomy_term faqs content'] = array(
    'name' => 'administer panelizer taxonomy_term faqs content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'panelizer',
  );

  // Exported permission: 'administer panelizer taxonomy_term faqs context'.
  $permissions['administer panelizer taxonomy_term faqs context'] = array(
    'name' => 'administer panelizer taxonomy_term faqs context',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'panelizer',
  );

  // Exported permission: 'administer panelizer taxonomy_term faqs defaults'.
  $permissions['administer panelizer taxonomy_term faqs defaults'] = array(
    'name' => 'administer panelizer taxonomy_term faqs defaults',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'panelizer',
  );

  // Exported permission: 'administer panelizer taxonomy_term faqs layout'.
  $permissions['administer panelizer taxonomy_term faqs layout'] = array(
    'name' => 'administer panelizer taxonomy_term faqs layout',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'panelizer',
  );

  // Exported permission: 'administer panelizer taxonomy_term faqs overview'.
  $permissions['administer panelizer taxonomy_term faqs overview'] = array(
    'name' => 'administer panelizer taxonomy_term faqs overview',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'panelizer',
  );

  // Exported permission: 'administer panelizer taxonomy_term faqs settings'.
  $permissions['administer panelizer taxonomy_term faqs settings'] = array(
    'name' => 'administer panelizer taxonomy_term faqs settings',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'panelizer',
  );

  // Exported permission: 'create faq content'.
  $permissions['create faq content'] = array(
    'name' => 'create faq content',
    'roles' => array(
      'administrator' => 'administrator',
      'builder' => 'builder',
      'editor' => 'editor',
      'contributor' => 'contributor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any faq content'.
  $permissions['delete any faq content'] = array(
    'name' => 'delete any faq content',
    'roles' => array(
      'administrator' => 'administrator',
      'builder' => 'builder',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own faq content'.
  $permissions['delete own faq content'] = array(
    'name' => 'delete own faq content',
    'roles' => array(
      'administrator' => 'administrator',
      'builder' => 'builder',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete terms in faqs'.
  $permissions['delete terms in faqs'] = array(
    'name' => 'delete terms in faqs',
    'roles' => array(
      'administrator' => 'administrator',
      'builder' => 'builder',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit any faq content'.
  $permissions['edit any faq content'] = array(
    'name' => 'edit any faq content',
    'roles' => array(
      'administrator' => 'administrator',
      'builder' => 'builder',
      'editor' => 'editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own faq content'.
  $permissions['edit own faq content'] = array(
    'name' => 'edit own faq content',
    'roles' => array(
      'administrator' => 'administrator',
      'builder' => 'builder',
      'editor' => 'editor',
      'contributor' => 'contributor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit terms in faqs'.
  $permissions['edit terms in faqs'] = array(
    'name' => 'edit terms in faqs',
    'roles' => array(
      'administrator' => 'administrator',
      'builder' => 'builder',
      'editor' => 'editor',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'view faq page'.
  $permissions['view faq page'] = array(
    'name' => 'view faq page',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'faq',
  );

  return $permissions;
}
