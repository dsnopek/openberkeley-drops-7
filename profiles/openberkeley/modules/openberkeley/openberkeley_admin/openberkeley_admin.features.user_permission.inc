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

  // Exported permission: 'access backup and migrate'.
  $permissions['access backup and migrate'] = array(
    'name' => 'access backup and migrate',
    'roles' => array(
      'administrator' => 'administrator',
      'builder' => 'builder',
    ),
    'module' => 'backup_migrate',
  );

  // Exported permission: 'access backup files'.
  $permissions['access backup files'] = array(
    'name' => 'access backup files',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'backup_migrate',
  );

  // Exported permission: 'access broken links report'.
  $permissions['access broken links report'] = array(
    'name' => 'access broken links report',
    'roles' => array(
      'administrator' => 'administrator',
      'builder' => 'builder',
      'editor' => 'editor',
    ),
    'module' => 'linkchecker',
  );

  // Exported permission: 'access dashboard administer menus'.
  $permissions['access dashboard administer menus'] = array(
    'name' => 'access dashboard administer menus',
    'roles' => array(
      'administrator' => 'administrator',
      'builder' => 'builder',
    ),
    'module' => 'openberkeley_admin',
  );

  // Exported permission: 'access dashboard administer taxonomy'.
  $permissions['access dashboard administer taxonomy'] = array(
    'name' => 'access dashboard administer taxonomy',
    'roles' => array(
      'administrator' => 'administrator',
      'builder' => 'builder',
      'editor' => 'editor',
    ),
    'module' => 'openberkeley_admin',
  );

  // Exported permission: 'access dashboard backups'.
  $permissions['access dashboard backups'] = array(
    'name' => 'access dashboard backups',
    'roles' => array(
      'administrator' => 'administrator',
      'builder' => 'builder',
    ),
    'module' => 'openberkeley_admin',
  );

  // Exported permission: 'access dashboard categories tab'.
  $permissions['access dashboard categories tab'] = array(
    'name' => 'access dashboard categories tab',
    'roles' => array(
      'administrator' => 'administrator',
      'builder' => 'builder',
      'editor' => 'editor',
    ),
    'module' => 'openberkeley_admin',
  );

  // Exported permission: 'access dashboard content overview'.
  $permissions['access dashboard content overview'] = array(
    'name' => 'access dashboard content overview',
    'roles' => array(
      'administrator' => 'administrator',
      'builder' => 'builder',
      'contributor' => 'contributor',
      'editor' => 'editor',
    ),
    'module' => 'openberkeley_admin',
  );

  // Exported permission: 'access dashboard content tab'.
  $permissions['access dashboard content tab'] = array(
    'name' => 'access dashboard content tab',
    'roles' => array(
      'administrator' => 'administrator',
      'builder' => 'builder',
      'editor' => 'editor',
    ),
    'module' => 'openberkeley_admin',
  );

  // Exported permission: 'access dashboard create content'.
  $permissions['access dashboard create content'] = array(
    'name' => 'access dashboard create content',
    'roles' => array(
      'administrator' => 'administrator',
      'builder' => 'builder',
      'contributor' => 'contributor',
      'editor' => 'editor',
    ),
    'module' => 'openberkeley_admin',
  );

  // Exported permission: 'access dashboard files tab'.
  $permissions['access dashboard files tab'] = array(
    'name' => 'access dashboard files tab',
    'roles' => array(
      'administrator' => 'administrator',
      'builder' => 'builder',
      'editor' => 'editor',
    ),
    'module' => 'openberkeley_admin',
  );

  // Exported permission: 'access dashboard new content'.
  $permissions['access dashboard new content'] = array(
    'name' => 'access dashboard new content',
    'roles' => array(
      'administrator' => 'administrator',
      'builder' => 'builder',
      'contributor' => 'contributor',
      'editor' => 'editor',
    ),
    'module' => 'openberkeley_admin',
  );

  // Exported permission: 'access dashboard new user accounts'.
  $permissions['access dashboard new user accounts'] = array(
    'name' => 'access dashboard new user accounts',
    'roles' => array(
      'administrator' => 'administrator',
      'builder' => 'builder',
      'editor' => 'editor',
    ),
    'module' => 'openberkeley_admin',
  );

  // Exported permission: 'access dashboard other administration'.
  $permissions['access dashboard other administration'] = array(
    'name' => 'access dashboard other administration',
    'roles' => array(
      'administrator' => 'administrator',
      'builder' => 'builder',
    ),
    'module' => 'openberkeley_admin',
  );

  // Exported permission: 'access dashboard unpublished content'.
  $permissions['access dashboard unpublished content'] = array(
    'name' => 'access dashboard unpublished content',
    'roles' => array(
      'administrator' => 'administrator',
      'builder' => 'builder',
      'editor' => 'editor',
    ),
    'module' => 'openberkeley_admin',
  );

  // Exported permission: 'access dashboard url administration'.
  $permissions['access dashboard url administration'] = array(
    'name' => 'access dashboard url administration',
    'roles' => array(
      'administrator' => 'administrator',
      'builder' => 'builder',
    ),
    'module' => 'openberkeley_admin',
  );

  // Exported permission: 'access dashboard user accounts tab'.
  $permissions['access dashboard user accounts tab'] = array(
    'name' => 'access dashboard user accounts tab',
    'roles' => array(
      'administrator' => 'administrator',
      'builder' => 'builder',
    ),
    'module' => 'openberkeley_admin',
  );

  // Exported permission: 'access own broken links report'.
  $permissions['access own broken links report'] = array(
    'name' => 'access own broken links report',
    'roles' => array(
      'administrator' => 'administrator',
      'builder' => 'builder',
      'contributor' => 'contributor',
      'editor' => 'editor',
    ),
    'module' => 'linkchecker',
  );

  // Exported permission: 'administer backup and migrate'.
  $permissions['administer backup and migrate'] = array(
    'name' => 'administer backup and migrate',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'backup_migrate',
  );

  // Exported permission: 'administer linkchecker'.
  $permissions['administer linkchecker'] = array(
    'name' => 'administer linkchecker',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'linkchecker',
  );

  // Exported permission: 'administer openberkeley settings'.
  $permissions['administer openberkeley settings'] = array(
    'name' => 'administer openberkeley settings',
    'roles' => array(
      'administrator' => 'administrator',
      'builder' => 'builder',
    ),
    'module' => 'openberkeley_admin',
  );

  // Exported permission: 'administer spotlight settings'.
  $permissions['administer spotlight settings'] = array(
    'name' => 'administer spotlight settings',
    'roles' => array(
      'administrator' => 'administrator',
      'builder' => 'builder',
    ),
    'module' => 'openberkeley_admin',
  );

  // Exported permission: 'administer total control'.
  $permissions['administer total control'] = array(
    'name' => 'administer total control',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'total_control',
  );

  // Exported permission: 'delete backup files'.
  $permissions['delete backup files'] = array(
    'name' => 'delete backup files',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'backup_migrate',
  );

  // Exported permission: 'display drupal links'.
  $permissions['display drupal links'] = array(
    'name' => 'display drupal links',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'admin_menu',
  );

  // Exported permission: 'edit link settings'.
  $permissions['edit link settings'] = array(
    'name' => 'edit link settings',
    'roles' => array(
      'administrator' => 'administrator',
      'builder' => 'builder',
    ),
    'module' => 'linkchecker',
  );

  // Exported permission: 'execute node_publish_action'.
  $permissions['execute node_publish_action'] = array(
    'name' => 'execute node_publish_action',
    'roles' => array(
      'administrator' => 'administrator',
      'builder' => 'builder',
      'editor' => 'editor',
    ),
    'module' => 'actions_permissions',
  );

  // Exported permission: 'execute node_unpublish_action'.
  $permissions['execute node_unpublish_action'] = array(
    'name' => 'execute node_unpublish_action',
    'roles' => array(
      'administrator' => 'administrator',
      'builder' => 'builder',
      'editor' => 'editor',
    ),
    'module' => 'actions_permissions',
  );

  // Exported permission: 'execute node_unpublish_by_keyword_action'.
  $permissions['execute node_unpublish_by_keyword_action'] = array(
    'name' => 'execute node_unpublish_by_keyword_action',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'actions_permissions',
  );

  // Exported permission: 'execute views_bulk_operations_delete_item'.
  $permissions['execute views_bulk_operations_delete_item'] = array(
    'name' => 'execute views_bulk_operations_delete_item',
    'roles' => array(
      'administrator' => 'administrator',
      'builder' => 'builder',
    ),
    'module' => 'actions_permissions',
  );

  // Exported permission: 'execute views_bulk_operations_delete_revision'.
  $permissions['execute views_bulk_operations_delete_revision'] = array(
    'name' => 'execute views_bulk_operations_delete_revision',
    'roles' => array(
      'administrator' => 'administrator',
      'builder' => 'builder',
    ),
    'module' => 'actions_permissions',
  );

  // Exported permission: 'execute views_bulk_operations_script_action'.
  $permissions['execute views_bulk_operations_script_action'] = array(
    'name' => 'execute views_bulk_operations_script_action',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'actions_permissions',
  );

  // Exported permission: 'execute views_bulk_operations_user_roles_action'.
  $permissions['execute views_bulk_operations_user_roles_action'] = array(
    'name' => 'execute views_bulk_operations_user_roles_action',
    'roles' => array(
      'administrator' => 'administrator',
      'builder' => 'builder',
    ),
    'module' => 'actions_permissions',
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
      'contributor' => 'contributor',
      'editor' => 'editor',
    ),
    'module' => 'total_control',
  );

  // Exported permission: 'perform backup'.
  $permissions['perform backup'] = array(
    'name' => 'perform backup',
    'roles' => array(
      'administrator' => 'administrator',
      'builder' => 'builder',
    ),
    'module' => 'backup_migrate',
  );

  // Exported permission: 'restore from backup'.
  $permissions['restore from backup'] = array(
    'name' => 'restore from backup',
    'roles' => array(
      'administrator' => 'administrator',
      'builder' => 'builder',
    ),
    'module' => 'backup_migrate',
  );

  // Exported permission: 'see contextual messages'.
  $permissions['see contextual messages'] = array(
    'name' => 'see contextual messages',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'linkchecker',
  );

  return $permissions;
}
