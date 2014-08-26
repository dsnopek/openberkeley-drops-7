# openberkeley_admin #

Feature for capturing administrator configuration.

# Provides #

## Menu: admin/config/openberkeley ##

This menu stub can be used by other Open Berkeley features/modules which need to
provide administrator settings.

## Administration Menu ##

* Enable admin_menu and admin_menu_toolbar

/admin/config/administration/admin_menu:
* Disable client cache
* Disable top of page

## Total Control and Administration Views configuration ##

* Provide custom default panel page for /admin/dashboard
* Provide blocks in code for Other Administration and URL Administration panes
* Add admin_views control_users view
* Form alter to prevent role escalation to Administrator at /admin/dashboard/users > Modify user roles
* Fix date format in control_users view
* Set Builder permissions
* Provide custom permissions to specify the visibility of the panes at admin/dashboard
* Add an Open Berkeley tab exposing links to Open Berkeley configuration
* Add a pane providing links to Backup and Migrate

### Administer Taxonomy Pane ###
By default this pane is configured to display administration links for each taxonomy vocabulary
to which the user has access. Since an unknown number of vocabularies may exist on a site, this
pane has been configured placeholders for 10 vocabularies:

openberkeley_admin.pages_default.inc:
```
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
```

Should > 10 vocabularies be needed the best thing to do is to manually enable the new vocabularies at
/admin/structure/pages/nojs/operation/page-dashboard/handlers/page_dashboard_panel_context/content.
(Alternatively, the above file could be patched to enable more vocabularies.)

(Note that disabling and enabling a vocabulary may increment its vid by 1.)

If taxonomy permissions are modified caches should be cleared to ensure that this pane displays
administration links for vocabularies to which the user has administrative access.

## Link Checker ##

## URL Redirects ##

## Navigation 404 ##

## Google Analytics ##

## Backup and Migrate ##
* Prevent users from saving backups to the server if Pantheon environment variables are present.
* Set backup file name to use \[site:url-brief\] in the default profile.  This is useful for differentiating backups taken in different pantheon environments (dev/test/live).
