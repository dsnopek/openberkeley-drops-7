<?php
/**
 * @file
 * openberkeley_news.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function openberkeley_news_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'openberkeley_news_archive';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'News';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'News';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '20';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'field_openberkeley_news_pdate',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: External link */
  $handler->display->display_options['fields']['field_openberkeley_news_xlink']['id'] = 'field_openberkeley_news_xlink';
  $handler->display->display_options['fields']['field_openberkeley_news_xlink']['table'] = 'field_data_field_openberkeley_news_xlink';
  $handler->display->display_options['fields']['field_openberkeley_news_xlink']['field'] = 'field_openberkeley_news_xlink';
  $handler->display->display_options['fields']['field_openberkeley_news_xlink']['label'] = '';
  $handler->display->display_options['fields']['field_openberkeley_news_xlink']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_openberkeley_news_xlink']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_openberkeley_news_xlink']['empty'] = 'node/[nid]';
  $handler->display->display_options['fields']['field_openberkeley_news_xlink']['empty_zero'] = TRUE;
  $handler->display->display_options['fields']['field_openberkeley_news_xlink']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_openberkeley_news_xlink']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_openberkeley_news_xlink']['type'] = 'link_plain';
  /* Field: Content: Publication date */
  $handler->display->display_options['fields']['field_openberkeley_news_pdate']['id'] = 'field_openberkeley_news_pdate';
  $handler->display->display_options['fields']['field_openberkeley_news_pdate']['table'] = 'field_data_field_openberkeley_news_pdate';
  $handler->display->display_options['fields']['field_openberkeley_news_pdate']['field'] = 'field_openberkeley_news_pdate';
  $handler->display->display_options['fields']['field_openberkeley_news_pdate']['label'] = '';
  $handler->display->display_options['fields']['field_openberkeley_news_pdate']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_openberkeley_news_pdate']['settings'] = array(
    'format_type' => 'panopoly_day',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['path'] = '[field_openberkeley_news_xlink]';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Source */
  $handler->display->display_options['fields']['field_openberkeley_news_source']['id'] = 'field_openberkeley_news_source';
  $handler->display->display_options['fields']['field_openberkeley_news_source']['table'] = 'field_data_field_openberkeley_news_source';
  $handler->display->display_options['fields']['field_openberkeley_news_source']['field'] = 'field_openberkeley_news_source';
  /* Sort criterion: Content: Publication date (field_openberkeley_news_pdate) */
  $handler->display->display_options['sorts']['field_openberkeley_news_pdate_value']['id'] = 'field_openberkeley_news_pdate_value';
  $handler->display->display_options['sorts']['field_openberkeley_news_pdate_value']['table'] = 'field_data_field_openberkeley_news_pdate';
  $handler->display->display_options['sorts']['field_openberkeley_news_pdate_value']['field'] = 'field_openberkeley_news_pdate_value';
  $handler->display->display_options['sorts']['field_openberkeley_news_pdate_value']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'openberkeley_news_item' => 'openberkeley_news_item',
  );
  /* Filter criterion: Content: Publication date (field_openberkeley_news_pdate) */
  $handler->display->display_options['filters']['field_openberkeley_news_pdate_value']['id'] = 'field_openberkeley_news_pdate_value';
  $handler->display->display_options['filters']['field_openberkeley_news_pdate_value']['table'] = 'field_data_field_openberkeley_news_pdate';
  $handler->display->display_options['filters']['field_openberkeley_news_pdate_value']['field'] = 'field_openberkeley_news_pdate_value';
  $handler->display->display_options['filters']['field_openberkeley_news_pdate_value']['operator'] = '<=';
  $handler->display->display_options['filters']['field_openberkeley_news_pdate_value']['default_date'] = 'today';
  $handler->display->display_options['filters']['field_openberkeley_news_pdate_value']['year_range'] = '-1:+3';

  /* Display: Recent stories */
  $handler = $view->new_display('panel_pane', 'Recent stories', 'panel_pane_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Recent Stories';
  $handler->display->display_options['defaults']['use_more'] = FALSE;
  $handler->display->display_options['use_more'] = TRUE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_always'] = TRUE;
  $handler->display->display_options['defaults']['use_more_text'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'News Archive';
  $handler->display->display_options['defaults']['link_display'] = FALSE;
  $handler->display->display_options['link_display'] = 'custom_url';
  $handler->display->display_options['link_url'] = 'news-archive';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '3';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: External link */
  $handler->display->display_options['fields']['field_openberkeley_news_xlink']['id'] = 'field_openberkeley_news_xlink';
  $handler->display->display_options['fields']['field_openberkeley_news_xlink']['table'] = 'field_data_field_openberkeley_news_xlink';
  $handler->display->display_options['fields']['field_openberkeley_news_xlink']['field'] = 'field_openberkeley_news_xlink';
  $handler->display->display_options['fields']['field_openberkeley_news_xlink']['label'] = '';
  $handler->display->display_options['fields']['field_openberkeley_news_xlink']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_openberkeley_news_xlink']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_openberkeley_news_xlink']['empty'] = 'node/[nid]';
  $handler->display->display_options['fields']['field_openberkeley_news_xlink']['empty_zero'] = TRUE;
  $handler->display->display_options['fields']['field_openberkeley_news_xlink']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_openberkeley_news_xlink']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_openberkeley_news_xlink']['type'] = 'link_plain';
  /* Field: Content: Publication date */
  $handler->display->display_options['fields']['field_openberkeley_news_pdate']['id'] = 'field_openberkeley_news_pdate';
  $handler->display->display_options['fields']['field_openberkeley_news_pdate']['table'] = 'field_data_field_openberkeley_news_pdate';
  $handler->display->display_options['fields']['field_openberkeley_news_pdate']['field'] = 'field_openberkeley_news_pdate';
  $handler->display->display_options['fields']['field_openberkeley_news_pdate']['label'] = '';
  $handler->display->display_options['fields']['field_openberkeley_news_pdate']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_openberkeley_news_pdate']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_openberkeley_news_pdate']['settings'] = array(
    'format_type' => 'panopoly_day',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['path'] = '[field_openberkeley_news_xlink]';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  $handler->display->display_options['allow']['use_pager'] = 0;
  $handler->display->display_options['allow']['items_per_page'] = 'items_per_page';
  $handler->display->display_options['allow']['offset'] = 0;
  $handler->display->display_options['allow']['link_to_view'] = 0;
  $handler->display->display_options['allow']['more_link'] = 'more_link';
  $handler->display->display_options['allow']['path_override'] = 0;
  $handler->display->display_options['allow']['title_override'] = 'title_override';
  $handler->display->display_options['allow']['exposed_form'] = 0;
  $handler->display->display_options['allow']['fields_override'] = 0;

  /* Display: Full listing */
  $handler = $view->new_display('panel_pane', 'Full listing', 'panel_pane_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'field_openberkeley_news_pdate',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'field_openberkeley_news_pdate' => 'field_openberkeley_news_pdate',
    'field_openberkeley_news_source' => 'field_openberkeley_news_source',
  );
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = '<h2>%1</h2>';
  $handler->display->display_options['header']['area']['format'] = 'editor';
  $handler->display->display_options['header']['area']['tokenize'] = TRUE;
  $handler->display->display_options['defaults']['footer'] = FALSE;
  /* Footer: Global: Text area */
  $handler->display->display_options['footer']['area']['id'] = 'area';
  $handler->display->display_options['footer']['area']['table'] = 'views';
  $handler->display->display_options['footer']['area']['field'] = 'area';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: External link */
  $handler->display->display_options['fields']['field_openberkeley_news_xlink']['id'] = 'field_openberkeley_news_xlink';
  $handler->display->display_options['fields']['field_openberkeley_news_xlink']['table'] = 'field_data_field_openberkeley_news_xlink';
  $handler->display->display_options['fields']['field_openberkeley_news_xlink']['field'] = 'field_openberkeley_news_xlink';
  $handler->display->display_options['fields']['field_openberkeley_news_xlink']['label'] = '';
  $handler->display->display_options['fields']['field_openberkeley_news_xlink']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_openberkeley_news_xlink']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_openberkeley_news_xlink']['empty'] = 'node/[nid]';
  $handler->display->display_options['fields']['field_openberkeley_news_xlink']['empty_zero'] = TRUE;
  $handler->display->display_options['fields']['field_openberkeley_news_xlink']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_openberkeley_news_xlink']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_openberkeley_news_xlink']['type'] = 'link_plain';
  /* Field: Content: Source */
  $handler->display->display_options['fields']['field_openberkeley_news_source']['id'] = 'field_openberkeley_news_source';
  $handler->display->display_options['fields']['field_openberkeley_news_source']['table'] = 'field_data_field_openberkeley_news_source';
  $handler->display->display_options['fields']['field_openberkeley_news_source']['field'] = 'field_openberkeley_news_source';
  $handler->display->display_options['fields']['field_openberkeley_news_source']['label'] = '';
  $handler->display->display_options['fields']['field_openberkeley_news_source']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_openberkeley_news_source']['alter']['text'] = '[field_openberkeley_news_source]';
  $handler->display->display_options['fields']['field_openberkeley_news_source']['element_type'] = 'em';
  $handler->display->display_options['fields']['field_openberkeley_news_source']['element_label_colon'] = FALSE;
  /* Field: Content: Publication date */
  $handler->display->display_options['fields']['field_openberkeley_news_pdate']['id'] = 'field_openberkeley_news_pdate';
  $handler->display->display_options['fields']['field_openberkeley_news_pdate']['table'] = 'field_data_field_openberkeley_news_pdate';
  $handler->display->display_options['fields']['field_openberkeley_news_pdate']['field'] = 'field_openberkeley_news_pdate';
  $handler->display->display_options['fields']['field_openberkeley_news_pdate']['label'] = '';
  $handler->display->display_options['fields']['field_openberkeley_news_pdate']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_openberkeley_news_pdate']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_openberkeley_news_pdate']['settings'] = array(
    'format_type' => 'panopoly_day',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['path'] = '[field_openberkeley_news_xlink]';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_type'] = 'strong';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['type'] = 'text_summary_or_trimmed';
  $handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '600',
  );
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: News type (field_openberkeley_news_type) */
  $handler->display->display_options['arguments']['field_openberkeley_news_type_tid']['id'] = 'field_openberkeley_news_type_tid';
  $handler->display->display_options['arguments']['field_openberkeley_news_type_tid']['table'] = 'field_data_field_openberkeley_news_type';
  $handler->display->display_options['arguments']['field_openberkeley_news_type_tid']['field'] = 'field_openberkeley_news_type_tid';
  $handler->display->display_options['arguments']['field_openberkeley_news_type_tid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_openberkeley_news_type_tid']['default_argument_type'] = 'taxonomy_tid';
  $handler->display->display_options['arguments']['field_openberkeley_news_type_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_openberkeley_news_type_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_openberkeley_news_type_tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_openberkeley_news_type_tid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['field_openberkeley_news_type_tid']['validate']['type'] = 'taxonomy_term';
  $handler->display->display_options['arguments']['field_openberkeley_news_type_tid']['validate_options']['vocabularies'] = array(
    'openberkeley_news_type' => 'openberkeley_news_type',
  );
  $handler->display->display_options['arguments']['field_openberkeley_news_type_tid']['validate_options']['type'] = 'convert';
  $handler->display->display_options['arguments']['field_openberkeley_news_type_tid']['validate_options']['transform'] = TRUE;
  $handler->display->display_options['arguments']['field_openberkeley_news_type_tid']['validate']['fail'] = 'ignore';
  $handler->display->display_options['argument_input'] = array(
    'field_openberkeley_news_type_tid' => array(
      'type' => 'panel',
      'context' => 'entity:file.field_file_image_alt_text',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Content: News type (field_openberkeley_news_type)',
    ),
  );

  /* Display: RSS Feed */
  $handler = $view->new_display('feed', 'RSS Feed', 'feed_1');
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['style_plugin'] = 'rss';
  $handler->display->display_options['row_plugin'] = 'rss_fields';
  $handler->display->display_options['row_options']['title_field'] = 'title';
  $handler->display->display_options['row_options']['link_field'] = 'field_openberkeley_news_xlink';
  $handler->display->display_options['row_options']['description_field'] = 'body';
  $handler->display->display_options['row_options']['creator_field'] = 'field_openberkeley_news_byline';
  $handler->display->display_options['row_options']['date_field'] = 'field_openberkeley_news_pdate';
  $handler->display->display_options['row_options']['guid_field_options'] = array(
    'guid_field' => 'uuid',
    'guid_field_is_permalink' => 0,
  );
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Publication date */
  $handler->display->display_options['fields']['field_openberkeley_news_pdate']['id'] = 'field_openberkeley_news_pdate';
  $handler->display->display_options['fields']['field_openberkeley_news_pdate']['table'] = 'field_data_field_openberkeley_news_pdate';
  $handler->display->display_options['fields']['field_openberkeley_news_pdate']['field'] = 'field_openberkeley_news_pdate';
  $handler->display->display_options['fields']['field_openberkeley_news_pdate']['label'] = '';
  $handler->display->display_options['fields']['field_openberkeley_news_pdate']['element_type'] = '0';
  $handler->display->display_options['fields']['field_openberkeley_news_pdate']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_openberkeley_news_pdate']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_openberkeley_news_pdate']['settings'] = array(
    'format_type' => 'panopoly_day',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['path'] = '[field_openberkeley_news_xlink]';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Node UUID */
  $handler->display->display_options['fields']['uuid']['id'] = 'uuid';
  $handler->display->display_options['fields']['uuid']['table'] = 'node';
  $handler->display->display_options['fields']['uuid']['field'] = 'uuid';
  $handler->display->display_options['fields']['uuid']['label'] = '';
  $handler->display->display_options['fields']['uuid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['uuid']['element_label_colon'] = FALSE;
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['label'] = '';
  $handler->display->display_options['fields']['path']['exclude'] = TRUE;
  $handler->display->display_options['fields']['path']['element_label_colon'] = FALSE;
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['type'] = 'text_plain';
  $handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '600',
  );
  /* Field: Content: External link */
  $handler->display->display_options['fields']['field_openberkeley_news_xlink']['id'] = 'field_openberkeley_news_xlink';
  $handler->display->display_options['fields']['field_openberkeley_news_xlink']['table'] = 'field_data_field_openberkeley_news_xlink';
  $handler->display->display_options['fields']['field_openberkeley_news_xlink']['field'] = 'field_openberkeley_news_xlink';
  $handler->display->display_options['fields']['field_openberkeley_news_xlink']['label'] = '';
  $handler->display->display_options['fields']['field_openberkeley_news_xlink']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_openberkeley_news_xlink']['empty'] = '[path]';
  $handler->display->display_options['fields']['field_openberkeley_news_xlink']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_openberkeley_news_xlink']['type'] = 'link_absolute';
  /* Field: Content: Byline */
  $handler->display->display_options['fields']['field_openberkeley_news_byline']['id'] = 'field_openberkeley_news_byline';
  $handler->display->display_options['fields']['field_openberkeley_news_byline']['table'] = 'field_data_field_openberkeley_news_byline';
  $handler->display->display_options['fields']['field_openberkeley_news_byline']['field'] = 'field_openberkeley_news_byline';
  $handler->display->display_options['fields']['field_openberkeley_news_byline']['label'] = '';
  $handler->display->display_options['fields']['field_openberkeley_news_byline']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: News type (field_openberkeley_news_type) */
  $handler->display->display_options['arguments']['field_openberkeley_news_type_tid']['id'] = 'field_openberkeley_news_type_tid';
  $handler->display->display_options['arguments']['field_openberkeley_news_type_tid']['table'] = 'field_data_field_openberkeley_news_type';
  $handler->display->display_options['arguments']['field_openberkeley_news_type_tid']['field'] = 'field_openberkeley_news_type_tid';
  $handler->display->display_options['arguments']['field_openberkeley_news_type_tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_openberkeley_news_type_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_openberkeley_news_type_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_openberkeley_news_type_tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_openberkeley_news_type_tid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['field_openberkeley_news_type_tid']['validate']['type'] = 'taxonomy_term';
  $handler->display->display_options['arguments']['field_openberkeley_news_type_tid']['validate_options']['vocabularies'] = array(
    'openberkeley_news_type' => 'openberkeley_news_type',
  );
  $handler->display->display_options['arguments']['field_openberkeley_news_type_tid']['validate_options']['type'] = 'convert';
  $handler->display->display_options['arguments']['field_openberkeley_news_type_tid']['validate']['fail'] = 'ignore';
  $handler->display->display_options['path'] = 'news-archive/%/feed';
  $export['openberkeley_news_archive'] = $view;

  return $export;
}
