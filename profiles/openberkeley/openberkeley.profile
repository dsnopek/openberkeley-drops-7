<?php
/**
 * Implements hook_install_tasks()
 */
function openberkeley_install_tasks(&$install_state) {
  $tasks = array();

  // Add our custom CSS file for the installation process
  // drupal_add_css(drupal_get_path('profile', 'panopoly') . '/panopoly.css');
  // Should we want to style the installer, we'd alter the above
  
  // Add the Panopoly theme selection to the installation process
  require_once(drupal_get_path('module', 'panopoly_theme') . '/panopoly_theme.profile.inc');
  $tasks = $tasks + panopoly_theme_profile_theme_selection_install_task($install_state);

  return $tasks;
}

/**
 * Implements hook_install_tasks_alter()
 */
function openberkeley_install_tasks_alter(&$tasks, $install_state) {
  // Magically go one level deeper in solving years of dependency problems
  require_once(drupal_get_path('module', 'panopoly_core') . '/panopoly_core.profile.inc');
  $tasks['install_load_profile']['function'] = 'panopoly_core_install_load_profile';

  // If we only offer one language, define a callback to set this
  require_once(drupal_get_path('module', 'panopoly_core') . '/panopoly_core.profile.inc');
  if (!(count(install_find_locales($install_state['parameters']['profile'])) > 1)) {
    $tasks['install_select_locale']['function'] = 'panopoly_core_install_locale_selection';
  }

  // Wrap the install_profile_modules task, so we can do some configuration
  // before it starts.
  $tasks['install_profile_modules']['function'] = 'openberkeley_install_profile_modules';
}

/**
 * Wraps install_profile_modules() so we can do some configuration beforehand.
 */
function openberkeley_install_profile_modules(&$install_state) {
  // Give our Features more time to rebuild before timing out. This fixes an
  // issue with installing on Pantheon.
  variable_set('features_restore_time_limit_rebuild', 500);

  // Now, actually install the modules.
  return install_profile_modules($install_state);
}

/**
 * Implements hook_form_FORM_ID_alter()
 */
function openberkeley_form_install_configure_form_alter(&$form, $form_state) {

  // Hide some messages from various modules that are just too chatty.
  drupal_get_messages('status');
  drupal_get_messages('warning');

  // Set reasonable defaults for site configuration form
  $form['admin_account']['account']['name']['#default_value'] = 'ucbadmin';
  $form['admin_account']['account']['name']['#description'] = "<strong><font color=\"red\">For security reasons, do not use a name like 'admin' or 'root' here.</font></strong> (UC Berkeley IST suggests using 'ucbadmin'). " . $form['admin_account']['account']['name']['#description'];
  $form['server_settings']['site_default_country']['#default_value'] = 'US';
  $form['server_settings']['date_default_timezone']['#default_value'] = 'America/Los_Angeles'; // West coast, best coast

  // Add the Pathologic paths stuff from openberkeley_wysiwyg_override.
  openberkeley_wysiwyg_override_form_system_site_information_settings_alter($form, $form_state);
}

/**
 * Implements hook_form_FORM_ID_alter()
 */
function openberkeley_form_panopoly_theme_selection_form_alter(&$form, $form_state) {

  // Create a list of theme options, minus the admin and testing themes
  $themes = array();
  foreach (system_rebuild_theme_data() as $theme) {
    if (!in_array($theme->name, array('test_theme', 'update_test_basetheme', 'update_test_subtheme', 'block_test_theme', 'stark', 'seven'))) {
      if ($theme->name == 'berkeley') {
        $berkeley = theme('image', array('path' => $theme->info['screenshot'])) . '<strong>' . $theme->info['name'] . '</strong><br><p><em>' . $theme->info['description'] . '</em></p><p class="clearfix"></p>';
      }
      else {
        $themes[$theme->name] = theme('image', array('path' => $theme->info['screenshot'])) . '<strong>' . $theme->info['name'] . '</strong><br><p><em>' . $theme->info['description'] . '</em></p><p class="clearfix"></p>';
      }
    }
  }

  // Berkeley theme comes first!
  openberkeley_array_unshift_assoc($themes, 'berkeley', $berkeley);

  $form['theme_wrapper']['theme'] = array(
    '#type' => 'radios',
    '#options' => $themes,
    '#default_value' => 'berkeley',
  );

}

function openberkeley_array_unshift_assoc(&$arr, $key, $val)
{
  $arr = array_reverse($arr, true);
  $arr[$key] = $val;
  $arr = array_reverse($arr, true);
  return $arr;
}
