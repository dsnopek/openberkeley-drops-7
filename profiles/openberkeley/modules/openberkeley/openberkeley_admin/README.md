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

