<?php
/**
 * @file
 * openberkeley_wysiwyg_override.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function openberkeley_wysiwyg_override_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'use html source button in wysiwyg'.
  $permissions['use html source button in wysiwyg'] = array(
    'name' => 'use html source button in wysiwyg',
    'roles' => array(
      'administrator' => 'administrator',
      'builder' => 'builder',
    ),
    'module' => 'openberkeley_wysiwyg_override',
  );

  // Exported permission: 'use text format panopoly_html_text'.
  $permissions['use text format panopoly_html_text'] = array(
    'name' => 'use text format panopoly_html_text',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'filter',
  );

  // Exported permission: 'use text format panopoly_wysiwyg_text'.
  $permissions['use text format panopoly_wysiwyg_text'] = array(
    'name' => 'use text format panopoly_wysiwyg_text',
    'roles' => array(
      'administrator' => 'administrator',
      'builder' => 'builder',
      'contributor' => 'contributor',
      'editor' => 'editor',
    ),
    'module' => 'filter',
  );

  return $permissions;
}
