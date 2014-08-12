<?php
/**
 * @file
 * openberkeley_admin.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function openberkeley_admin_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function openberkeley_admin_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_views_default_views_alter()
 * - change date format
 * - Add VBO user roles actions, pathauto and panelizer settings
 */

function openberkeley_admin_views_default_views_alter(&$views) {
  if (array_key_exists('control_users', $views)) {
    $handler =& $views['control_users']->display['default']->handler;
    $handler->display->display_options['fields']['login']['custom_date_format'] = 'm/d g:ia';
    $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
          'action::user_block_user_action' => array(
            'selected' => 1,
            'postpone_processing' => 0,
            'skip_confirmation' => 0,
            'override_label' => 0,
            'label' => '',
          ),
          'action::views_bulk_operations_delete_item' => array(
            'selected' => 0,
            'postpone_processing' => 0,
            'skip_confirmation' => 0,
            'override_label' => 0,
            'label' => '',
          ),
          'action::views_bulk_operations_script_action' => array(
            'selected' => 0,
            'postpone_processing' => 0,
            'skip_confirmation' => 0,
            'override_label' => 0,
            'label' => '',
          ),
          'action::views_bulk_operations_modify_action' => array(
            'selected' => 0,
            'postpone_processing' => 0,
            'skip_confirmation' => 0,
            'override_label' => 0,
            'label' => '',
            'settings' => array(
              'show_all_tokens' => 1,
              'display_values' => array(
                '_all_' => '_all_',
              ),
            ),
          ),
          'action::views_bulk_operations_user_roles_action' => array(
            'selected' => 1,
            'postpone_processing' => 0,
            'skip_confirmation' => 0,
            'override_label' => 0,
            'label' => '',
          ),
          'action::views_bulk_operations_argument_selector_action' => array(
            'selected' => 0,
            'skip_confirmation' => 0,
            'override_label' => 0,
            'label' => '',
            'settings' => array(
              'url' => '',
            ),
          ),
          'action::system_send_email_action' => array(
            'selected' => 1,
            'postpone_processing' => 0,
            'skip_confirmation' => 1,
            'override_label' => 0,
            'label' => '',
          ),
          'action::panelizer_set_status_action' => array(
            'selected' => 0,
            'postpone_processing' => 0,
            'skip_confirmation' => 0,
            'override_label' => 0,
            'label' => '',
          ),
          'action::pathauto_user_update_action' => array(
            'selected' => 0,
            'postpone_processing' => 0,
            'skip_confirmation' => 0,
            'override_label' => 0,
            'label' => '',
          ),
        );
  }
}
