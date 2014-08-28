<?php
/**
 * @file
 * openberkeley_theme.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function openberkeley_theme_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'panels_page_allowed_layouts';
  $strongarm->value = 'O:22:"panels_allowed_layouts":4:{s:9:"allow_new";b:1;s:11:"module_name";s:11:"panels_page";s:23:"allowed_layout_settings";a:43:{s:8:"flexible";b:0;s:14:"twocol_stacked";b:0;s:13:"twocol_bricks";b:0;s:6:"twocol";b:0;s:25:"threecol_33_34_33_stacked";b:0;s:17:"threecol_33_34_33";b:0;s:25:"threecol_25_50_25_stacked";b:0;s:17:"threecol_25_50_25";b:0;s:6:"onecol";b:0;s:6:"whelan";b:1;s:12:"webb_flipped";b:1;s:5:"sutro";b:1;s:13:"selby_flipped";b:1;s:5:"selby";b:1;s:4:"pond";b:1;s:15:"moscone_flipped";b:1;s:7:"moscone";b:1;s:8:"mccoppin";b:1;s:15:"hewston_flipped";b:1;s:7:"hewston";b:1;s:6:"harris";b:1;s:5:"geary";b:1;s:12:"burr_flipped";b:1;s:4:"burr";b:1;s:5:"brown";b:1;s:15:"brenham_flipped";b:1;s:7:"brenham";b:1;s:16:"bartlett_flipped";b:1;s:8:"bartlett";b:1;s:17:"sanderson_flipped";b:1;s:9:"sanderson";b:1;s:6:"boxton";b:1;s:22:"bryant_flipped_flipped";b:1;s:6:"bryant";b:1;s:6:"phelan";b:1;s:14:"taylor_flipped";b:1;s:6:"taylor";b:1;s:12:"sutro_double";b:1;s:5:"rolph";b:1;s:4:"webb";b:1;s:10:"responsive";b:1;s:18:"responsive:default";b:0;s:14:"zen_no_wrapper";b:0;}s:10:"form_state";N;}';
  $export['panels_page_allowed_layouts'] = $strongarm;

  return $export;
}
