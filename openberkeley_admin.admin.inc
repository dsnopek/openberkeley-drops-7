<?php
/**
 * Administer Open Berkeley Settings Page
 */
function openberkeley_admin_openberkeley_settings_page() {
  $item = menu_get_item('admin/config/openberkeley');
  if ($content = system_admin_menu_block($item)) {
    $output = theme('admin_block_content', array('content' => $content));
    // rewrite the url in order to return the user to the Open Berkeley tab on the dashboard.
    $output = preg_replace('/(admin\/config\/openberkeley\/[^"]+)/', "\\1" . '?destination=admin/dashboard/openberkeley', $output);
  }
  else {
    $output = t('You do not have any administrative items.');
  }

  return $output;
}
