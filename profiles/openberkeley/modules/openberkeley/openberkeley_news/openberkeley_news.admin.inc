<?php
/**
 * Impl
 */
function openberkeley_news_admin_form($form, &$form_state) {
  $form['starter'] = array(
    '#type' => 'fieldset',
    '#title' => t('Starter Content'),
    '#collapsible' => TRUE,
  );

  $form['starter']['openberkeley_news_use_starter_content'] = array(
    '#type' => 'checkbox',
    '#title' => t('Use Starter Content'),
    '#default_value' => variable_get('openberkeley_news_use_starter_content', 1),
    '#description' => ('Unchecking this box disables the starter content that ships with the news feature.'),
  );

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => 'Submit',
  );

  return $form;
}

function openberkeley_news_admin_form_submit($form, &$form_state) {
  variable_set('openberkeley_news_use_starter_content', $form_state['values']['openberkeley_news_use_starter_content']);
  if ($form_state['values']['openberkeley_news_use_starter_content'] == 1) {
    drupal_set_message("Starter content for News has been added.");
    module_enable(array('openberkeley_news_starter'));
  }
  else {
    drupal_set_message("Starter content for News has been removed.");
    module_disable(array('openberkeley_news_starter'));
  }
}