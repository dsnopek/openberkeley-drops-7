<?php
/**
 * @file
 * openberkeley_base.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function openberkeley_base_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: main-menu.
  $menus['main-menu'] = array(
    'menu_name' => 'main-menu',
    'title' => 'Main menu',
    'description' => 'The <em>Main</em> menu is used on many sites to show the major sections of the site, often in a top navigation bar.',
  );
  // Exported menu: menu-footer-menu.
  $menus['menu-footer-menu'] = array(
    'menu_name' => 'menu-footer-menu',
    'title' => 'Footer menu',
    'description' => 'Boilerplate links for the bottom of the page.',
  );
  // Exported menu: menu-quick-links-menu.
  $menus['menu-quick-links-menu'] = array(
    'menu_name' => 'menu-quick-links-menu',
    'title' => 'Quick Links menu',
    'description' => '',
  );
  // Exported menu: menu-secondary-menu.
  $menus['menu-secondary-menu'] = array(
    'menu_name' => 'menu-secondary-menu',
    'title' => 'Secondary Menu',
    'description' => '',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Boilerplate links for the bottom of the page.');
  t('Footer menu');
  t('Main menu');
  t('Quick Links menu');
  t('Secondary Menu');
  t('The <em>Main</em> menu is used on many sites to show the major sections of the site, often in a top navigation bar.');


  return $menus;
}
