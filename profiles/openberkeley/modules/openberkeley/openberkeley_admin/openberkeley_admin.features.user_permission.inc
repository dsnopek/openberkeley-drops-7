<?php
/**
 * @file
 * openberkeley_admin.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function openberkeley_admin_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'access administration menu'.
  $permissions['access administration menu'] = array(
    'name' => 'access administration menu',
    'roles' => array(
      'administrator' => 'administrator',
      'builder' => 'builder',
      'contributor' => 'contributor',
      'editor' => 'editor',
    ),
    'module' => 'admin_menu',
  );

  // Exported permission: 'administer total control'.
  $permissions['administer total control'] = array(
    'name' => 'administer total control',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'total_control',
  );

  // Exported permission: 'display drupal links'.
  $permissions['display drupal links'] = array(
    'name' => 'display drupal links',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'admin_menu',
  );

  // Exported permission: 'flush caches'.
  $permissions['flush caches'] = array(
    'name' => 'flush caches',
    'roles' => array(
      'administrator' => 'administrator',
      'builder' => 'builder',
    ),
    'module' => 'admin_menu',
  );

  // Exported permission: 'have total control'.
  $permissions['have total control'] = array(
    'name' => 'have total control',
    'roles' => array(
      'administrator' => 'administrator',
      'builder' => 'builder',
    ),
    'module' => 'total_control',
  );

  return $permissions;
}
