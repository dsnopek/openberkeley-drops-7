<?php
/**
 * @file
 * openberkeley_faq.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function openberkeley_faq_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "panelizer" && $api == "panelizer") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
