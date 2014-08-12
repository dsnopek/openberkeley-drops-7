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

# Notes #

## Enabling this feature on an existing site requires clearing all caches ##

If you let openberkeley.info enable openberkeley\_admin during site installation you will see the "Dashboard, Content, Categories, User Accounts" tabs at admin/dashboard; however, if you try enabling on an existing site where it has never been installed, you will notice that those tabs are missing. If you flush all caches, these tabs will show up.
