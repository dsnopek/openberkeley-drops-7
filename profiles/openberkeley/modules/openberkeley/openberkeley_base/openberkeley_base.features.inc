<?php
/**
 * @file
 * openberkeley_base.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function openberkeley_base_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "config_perms" && $api == "config_perms") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
