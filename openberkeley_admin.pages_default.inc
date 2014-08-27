<?php
/**
 * @file
 * openberkeley_admin.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function openberkeley_admin_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'dashboard';
  $page->task = 'page';
  $page->admin_title = 'Total Control administrative dashboard';
  $page->admin_description = '';
  $page->path = 'admin/dashboard';
  $page->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'perm',
        'settings' => array(
          'perm' => 'have total control',
        ),
        'context' => 'logged-in-user',
        'not' => FALSE,
      ),
    ),
    'logic' => 'and',
  );
  $page->menu = array(
    'type' => 'normal',
    'title' => 'Dashboard',
    'name' => 'management',
    'weight' => '-100',
    'parent' => array(
      'type' => 'normal',
      'title' => 'Dashboard',
      'name' => 'management',
      'weight' => '0',
    ),
  );
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => TRUE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_dashboard_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'dashboard';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
  );
  $display = new panels_display();
  $display->layout = 'twocol_stacked';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'middle' => NULL,
      'top' => NULL,
      'left' => NULL,
      'right' => NULL,
      'bottom' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Dashboard';
  $display->uuid = 'bd607107-ce15-4deb-bce2-747804ba4837';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-0f419ac0-a9c8-436d-a627-73e442bcda14';
  $pane->panel = 'left';
  $pane->type = 'create';
  $pane->subtype = 'create';
  $pane->shown = TRUE;
  $pane->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'perm',
        'settings' => array(
          'perm' => 'access dashboard create content',
        ),
        'context' => 'logged-in-user',
        'not' => FALSE,
      ),
    ),
  );
  $pane->configuration = array(
    'types' => array(
      'article' => 'article',
      'project' => 'project',
      'page' => 0,
    ),
    'override_title' => 0,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = '';
  $pane->uuid = '0f419ac0-a9c8-436d-a627-73e442bcda14';
  $display->content['new-0f419ac0-a9c8-436d-a627-73e442bcda14'] = $pane;
  $display->panels['left'][0] = 'new-0f419ac0-a9c8-436d-a627-73e442bcda14';
  $pane = new stdClass();
  $pane->pid = 'new-18263b21-be97-4de2-872a-fa9682b3e524';
  $pane->panel = 'left';
  $pane->type = 'overview_content';
  $pane->subtype = 'overview_content';
  $pane->shown = TRUE;
  $pane->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'perm',
        'settings' => array(
          'perm' => 'access dashboard content overview',
        ),
        'context' => 'logged-in-user',
        'not' => FALSE,
      ),
    ),
  );
  $pane->configuration = array(
    'types' => array(
      'article' => 'article',
      'page' => 'page',
      'project' => 'project',
      'video' => 'video',
    ),
    'comments' => array(
      'article' => 'article',
      'page' => 0,
      'project' => 0,
      'video' => 0,
    ),
    'spam' => 0,
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = '';
  $pane->uuid = '18263b21-be97-4de2-872a-fa9682b3e524';
  $display->content['new-18263b21-be97-4de2-872a-fa9682b3e524'] = $pane;
  $display->panels['left'][1] = 'new-18263b21-be97-4de2-872a-fa9682b3e524';
  $pane = new stdClass();
  $pane->pid = 'new-85997bed-3d0f-4c6e-be78-1eb86fc64618';
  $pane->panel = 'left';
  $pane->type = 'views_panes';
  $pane->subtype = 'control_content_panes-pane_tc_new';
  $pane->shown = TRUE;
  $pane->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'perm',
        'settings' => array(
          'perm' => 'access dashboard new content',
        ),
        'context' => 'logged-in-user',
        'not' => FALSE,
      ),
    ),
  );
  $pane->configuration = array(
    'items_per_page' => '10',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = '';
  $pane->uuid = '85997bed-3d0f-4c6e-be78-1eb86fc64618';
  $display->content['new-85997bed-3d0f-4c6e-be78-1eb86fc64618'] = $pane;
  $display->panels['left'][2] = 'new-85997bed-3d0f-4c6e-be78-1eb86fc64618';
  $pane = new stdClass();
  $pane->pid = 'new-884a3a68-05da-4892-b912-3580de3d00a0';
  $pane->panel = 'left';
  $pane->type = 'views_panes';
  $pane->subtype = 'control_content_panes-pane_tc_unpub';
  $pane->shown = TRUE;
  $pane->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'perm',
        'settings' => array(
          'perm' => 'access dashboard unpublished content',
        ),
        'context' => 'logged-in-user',
        'not' => FALSE,
      ),
    ),
  );
  $pane->configuration = array(
    'items_per_page' => '10',
    'override_title' => 0,
    'override_title_text' => '',
    'view_mode' => NULL,
    'widget_title' => 'Unpublished content',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 3;
  $pane->locks = array();
  $pane->uuid = '884a3a68-05da-4892-b912-3580de3d00a0';
  $display->content['new-884a3a68-05da-4892-b912-3580de3d00a0'] = $pane;
  $display->panels['left'][3] = 'new-884a3a68-05da-4892-b912-3580de3d00a0';
  $pane = new stdClass();
  $pane->pid = 'new-fcf2d600-7fc2-4119-bf69-e1c6518d0be8';
  $pane->panel = 'left';
  $pane->type = 'views_panes';
  $pane->subtype = 'control_users_panes-pane_tc_new_users';
  $pane->shown = TRUE;
  $pane->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'perm',
        'settings' => array(
          'perm' => 'access dashboard new user accounts',
        ),
        'context' => 'logged-in-user',
        'not' => FALSE,
      ),
    ),
  );
  $pane->configuration = array(
    'items_per_page' => '10',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 4;
  $pane->locks = array();
  $pane->uuid = 'fcf2d600-7fc2-4119-bf69-e1c6518d0be8';
  $display->content['new-fcf2d600-7fc2-4119-bf69-e1c6518d0be8'] = $pane;
  $display->panels['left'][4] = 'new-fcf2d600-7fc2-4119-bf69-e1c6518d0be8';
  $pane = new stdClass();
  $pane->pid = 'new-a76901d1-8d37-42b8-9033-6eaa893a2da6';
  $pane->panel = 'right';
  $pane->type = 'menus';
  $pane->subtype = 'menus';
  $pane->shown = TRUE;
  $pane->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'perm',
        'settings' => array(
          'perm' => 'access dashboard administer menus',
        ),
        'context' => 'logged-in-user',
        'not' => FALSE,
      ),
    ),
  );
  $pane->configuration = array(
    'item1' => NULL,
    'item2' => NULL,
    'override_title' => 0,
    'override_title_text' => '',
    'menus' => array(
      'menu-footer-menu' => 'menu-footer-menu',
      'main-menu' => 'main-menu',
      'menu-quick-links-menu' => 'menu-quick-links-menu',
      'menu-secondary-menu' => 'menu-secondary-menu',
      'devel' => 0,
      'management' => 0,
      'navigation' => 0,
      'user-menu' => 0,
    ),
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = '';
  $pane->uuid = 'a76901d1-8d37-42b8-9033-6eaa893a2da6';
  $display->content['new-a76901d1-8d37-42b8-9033-6eaa893a2da6'] = $pane;
  $display->panels['right'][0] = 'new-a76901d1-8d37-42b8-9033-6eaa893a2da6';
  $pane = new stdClass();
  $pane->pid = 'new-974b9e64-28f0-45b1-bef5-739c8a29abe8';
  $pane->panel = 'right';
  $pane->type = 'node_types';
  $pane->subtype = 'node_types';
  $pane->shown = FALSE;
  $pane->access = array();
  $pane->configuration = array(
    'types' => array(
      'article' => 'article',
      'page' => 'page',
      'project' => 'project',
      'video' => 'video',
    ),
    'override_title' => 0,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = '';
  $pane->uuid = '974b9e64-28f0-45b1-bef5-739c8a29abe8';
  $display->content['new-974b9e64-28f0-45b1-bef5-739c8a29abe8'] = $pane;
  $display->panels['right'][1] = 'new-974b9e64-28f0-45b1-bef5-739c8a29abe8';
  $pane = new stdClass();
  $pane->pid = 'new-ccf8137a-47c6-453d-a2f4-8c4176006180';
  $pane->panel = 'right';
  $pane->type = 'taxonomy';
  $pane->subtype = 'taxonomy';
  $pane->shown = TRUE;
  $pane->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'perm',
        'settings' => array(
          'perm' => 'access dashboard administer taxonomy',
        ),
        'context' => 'logged-in-user',
        'not' => FALSE,
      ),
    ),
  );
  $pane->configuration = array(
    'vids' => array(
      1 => '1',
      3 => '3',
      2 => '2',
      4 => '4',
      5 => '5',
      6 => '6',
      7 => '7',
      8 => '8',
      9 => '9',
      10 => '10'
    ),
    'override_title' => 0,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = '';
  $pane->uuid = 'ccf8137a-47c6-453d-a2f4-8c4176006180';
  $display->content['new-ccf8137a-47c6-453d-a2f4-8c4176006180'] = $pane;
  $display->panels['right'][2] = 'new-ccf8137a-47c6-453d-a2f4-8c4176006180';
  $pane = new stdClass();
  $pane->pid = 'new-a8612ba8-f47e-451f-999e-eab962602d21';
  $pane->panel = 'right';
  $pane->type = 'panel_pages';
  $pane->subtype = 'panel_pages';
  $pane->shown = FALSE;
  $pane->access = array();
  $pane->configuration = array(
    'item1' => NULL,
    'item2' => NULL,
    'override_title' => 0,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 3;
  $pane->locks = '';
  $pane->uuid = 'a8612ba8-f47e-451f-999e-eab962602d21';
  $display->content['new-a8612ba8-f47e-451f-999e-eab962602d21'] = $pane;
  $display->panels['right'][3] = 'new-a8612ba8-f47e-451f-999e-eab962602d21';
  $pane = new stdClass();
  $pane->pid = 'new-4ee44607-8608-4fca-a3a7-a00401380137';
  $pane->panel = 'right';
  $pane->type = 'block';
  $pane->subtype = 'openberkeley_admin-url_administration';
  $pane->shown = TRUE;
  $pane->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'perm',
        'settings' => array(
          'perm' => 'access dashboard url administration',
        ),
        'context' => 'logged-in-user',
        'not' => FALSE,
      ),
    ),
  );
  $pane->configuration = array(
    'override_title' => 0,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 4;
  $pane->locks = array();
  $pane->uuid = '4ee44607-8608-4fca-a3a7-a00401380137';
  $display->content['new-4ee44607-8608-4fca-a3a7-a00401380137'] = $pane;
  $display->panels['right'][4] = 'new-4ee44607-8608-4fca-a3a7-a00401380137';
  $pane = new stdClass();
  $pane->pid = 'new-b912d98c-6724-4288-8c7e-d52cd321bcc4';
  $pane->panel = 'right';
  $pane->type = 'block';
  $pane->subtype = 'openberkeley_admin-other_administration';
  $pane->shown = TRUE;
  $pane->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'perm',
        'settings' => array(
          'perm' => 'access dashboard other administration',
        ),
        'context' => 'logged-in-user',
        'not' => FALSE,
      ),
    ),
  );
  $pane->configuration = array(
    'override_title' => 0,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 5;
  $pane->locks = array();
  $pane->uuid = 'b912d98c-6724-4288-8c7e-d52cd321bcc4';
  $display->content['new-b912d98c-6724-4288-8c7e-d52cd321bcc4'] = $pane;
  $display->panels['right'][5] = 'new-b912d98c-6724-4288-8c7e-d52cd321bcc4';
  $pane = new stdClass();
  $pane->pid = 'new-d690fa6f-f10a-47e5-9855-48b8a88611e2';
  $pane->panel = 'right';
  $pane->type = 'block';
  $pane->subtype = 'openberkeley_admin-backups';
  $pane->shown = TRUE;
  $pane->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'perm',
        'settings' => array(
          'perm' => 'access dashboard backups',
        ),
        'context' => 'logged-in-user',
        'not' => FALSE,
      ),
    ),
  );
  $pane->configuration = array(
    'override_title' => 1,
    'override_title_text' => 'Administer Backups',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 6;
  $pane->locks = array();
  $pane->uuid = 'd690fa6f-f10a-47e5-9855-48b8a88611e2';
  $display->content['new-d690fa6f-f10a-47e5-9855-48b8a88611e2'] = $pane;
  $display->panels['right'][6] = 'new-d690fa6f-f10a-47e5-9855-48b8a88611e2';
  $pane = new stdClass();
  $pane->pid = 'new-16d4c71a-52f3-4130-8d4f-aed01fbcedc2';
  $pane->panel = 'top';
  $pane->type = 'welcome';
  $pane->subtype = 'welcome';
  $pane->shown = FALSE;
  $pane->access = array();
  $pane->configuration = array();
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = '';
  $pane->uuid = '16d4c71a-52f3-4130-8d4f-aed01fbcedc2';
  $display->content['new-16d4c71a-52f3-4130-8d4f-aed01fbcedc2'] = $pane;
  $display->panels['top'][0] = 'new-16d4c71a-52f3-4130-8d4f-aed01fbcedc2';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;

  $pages['page-dashboard'] = $page;

  return $pages;
}
