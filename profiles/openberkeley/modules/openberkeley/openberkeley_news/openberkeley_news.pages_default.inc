<?php
/**
 * @file
 * openberkeley_news.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function openberkeley_news_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'openberkeley_news_archive';
  $page->task = 'page';
  $page->admin_title = 'News Archive';
  $page->admin_description = 'Panel with view of news archive.';
  $page->path = 'news-archive/!term';
  $page->access = array();
  $page->menu = array();
  $page->arguments = array(
    'term' => array(
      'id' => 1,
      'identifier' => 'Term string from URL',
      'name' => 'string',
      'settings' => array(
        'use_tail' => 0,
      ),
    ),
  );
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_news_archive_panel_context_2';
  $handler->task = 'page';
  $handler->subtask = 'openberkeley_news_archive';
  $handler->handler = 'panel_context';
  $handler->weight = 1;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'ipe',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
  );
  $display = new panels_display();
  $display->layout = 'boxton';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'contentmain' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'News';
  $display->uuid = '09b13cf7-d986-431d-85e8-4fadaad0aac7';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-6dff47d9-b4df-4598-80c9-4f4f9af44baf';
    $pane->panel = 'contentmain';
    $pane->type = 'views_panes';
    $pane->subtype = 'openberkeley_news_archive-panel_pane_2';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'view_mode' => NULL,
      'widget_title' => '',
      'items_per_page' => NULL,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '6dff47d9-b4df-4598-80c9-4f4f9af44baf';
    $display->content['new-6dff47d9-b4df-4598-80c9-4f4f9af44baf'] = $pane;
    $display->panels['contentmain'][0] = 'new-6dff47d9-b4df-4598-80c9-4f4f9af44baf';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-6dff47d9-b4df-4598-80c9-4f4f9af44baf';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['openberkeley_news_archive'] = $page;

  return $pages;

}
