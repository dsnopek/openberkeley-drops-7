<?php
/**
 * @file
 * openberkeley_admin.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function openberkeley_admin_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: management_total-control-dashboard:admin/config/administration/control
  $menu_links['management_total-control-dashboard:admin/config/administration/control'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/config/administration/control',
    'router_path' => 'admin/config/administration/control',
    'link_title' => 'Total Control Dashboard',
    'options' => array(
      'attributes' => array(
        'title' => 'Adjust dashboard settings.',
      ),
      'identifier' => 'management_total-control-dashboard:admin/config/administration/control',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'management_administration:admin/config/administration',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Total Control Dashboard');


  return $menu_links;
}
