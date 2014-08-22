<?php
/**
 * @file
 * openberkeley_media.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function openberkeley_media_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_file__image';
  $strongarm->value = array(
    'view_modes' => array(
      'teaser' => array(
        'custom_settings' => TRUE,
      ),
      'preview' => array(
        'custom_settings' => TRUE,
      ),
      'width_100' => array(
        'custom_settings' => TRUE,
      ),
      'width_200' => array(
        'custom_settings' => TRUE,
      ),
      'width_300' => array(
        'custom_settings' => TRUE,
      ),
      'width_400' => array(
        'custom_settings' => TRUE,
      ),
      'untouched' => array(
        'custom_settings' => TRUE,
      ),
      'link' => array(
        'custom_settings' => TRUE,
      ),
      'full' => array(
        'custom_settings' => FALSE,
      ),
      'rss' => array(
        'custom_settings' => FALSE,
      ),
      'search_index' => array(
        'custom_settings' => FALSE,
      ),
      'search_result' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(),
      'display' => array(
        'file' => array(
          'default' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
          'width_100' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
          'width_200' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
          'width_300' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
          'width_400' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
          'untouched' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
        ),
      ),
    ),
  );
  $export['field_bundle_settings_file__image'] = $strongarm;

  return $export;
}
