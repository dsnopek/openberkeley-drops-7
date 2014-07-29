api = 2
core = 7.x

;;;;;;;;;;;;;;;;;;;;;;;;;;
;;; UCB Custom Modules ;;;
;;;;;;;;;;;;;;;;;;;;;;;;;;

projects[ucberkeley_envconf][type] = module
projects[ucberkeley_envconf][subdir] = ucb
projects[ucberkeley_envconf][download][type] = file
projects[ucberkeley_envconf][download][url] = https://github.com/ucb-ist-drupal/ucberkeley_envconf-7/releases/download/7.x-2.0-alpha1/ucberkeley_envconf-7.x-2.0-alpha1.tar.gz

projects[ucberkeley_cas][type] = module
projects[ucberkeley_cas][subdir] = ucb
projects[ucberkeley_cas][download][type] = file
projects[ucberkeley_cas][download][url] = https://github.com/ucb-ist-drupal/ucberkeley_cas-7/releases/download/7.x-2.1-beta3/ucberkeley_cas-7.x-2.1-beta3.tar.gz

projects[ucb_openberkeley][type] = module
projects[ucb_openberkeley][subdir] = ucb
projects[ucb_openberkeley][download][type] = git
projects[ucb_openberkeley][download][url] = git://github.com/ucb-ist-drupal/ucb_openberkeley.git
; head ;projects[ucb_openberkeley][download][tag] =
; master ;projects[ucb_openberkeley][download][branch] = 7.x-1.x

projects[openberkeley_base][type] = module
projects[openberkeley_base][subdir] = openberkeley
projects[openberkeley_base][download][type] = git
projects[openberkeley_base][download][url] = git://github.com/ucb-ist-drupal/openberkeley_base.git

projects[openberkeley_pages][type] = module
projects[openberkeley_pages][subdir] = openberkeley
projects[openberkeley_pages][download][type] = git
projects[openberkeley_pages][download][url] = git://github.com/ucb-ist-drupal/openberkeley_pages.git

projects[openberkeley_update][type] = module
projects[openberkeley_update][subdir] = openberkeley
projects[openberkeley_update][download][type] = git
projects[openberkeley_update][download][url] = git://github.com/ucb-ist-drupal/openberkeley_update.git

projects[openberkeley_wysiwyg_override][type] = module
projects[openberkeley_wysiwyg_override][subdir] = openberkeley
projects[openberkeley_wysiwyg_override][download][type] = git
projects[openberkeley_wysiwyg_override][download][url] = git://github.com/ucb-ist-drupal/openberkeley_wysiwyg_override.git

projects[openberkeley_core_override][type] = module
projects[openberkeley_core_override][subdir] = openberkeley
projects[openberkeley_core_override][download][type] = git
projects[openberkeley_core_override][download][url] = git://github.com/ucb-ist-drupal/openberkeley_core_override.git

;;;;;;;;;;;;;;;;;
;;; UCB Theme ;;;
;;;;;;;;;;;;;;;;;

projects[berkeley][type] = theme
projects[berkeley][download][type] = git
projects[berkeley][download][url] = git://github.com/ucb-ist-drupal/berkeley.git
projects[berkeley][download][branch] = 7.x-1.x
projects[berkeley][download][tag] = 7.x-1.0-alpha11
;projects[berkeley][download][revision] = 6c3173a

;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;; UCB Contrib Modules ;;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;

; ******************************
; ***** OB not in Panopoly *****

; Backup and Migrate - Used for local backups
projects[backup_migrate][version] = 2.7
projects[backup_migrate][subdir] = contrib

; Bundle Copy - Used for exporting content types in D7
projects[bundle_copy][version] = 1.1
projects[bundle_copy][subdir] = contrib

; Config Perms - Used for custom permissions added to Total Control dashboard
projects[config_perms][version] = 2.0
projects[config_perms][subdir] = contrib
projects[config_perms][patch][1217478] = https://drupal.org/files/issues/0001-Fixed-undefined-index-notice-issue-number-1217478.patch
projects[config_perms][patch][1441692] = https://drupal.org/files/non-property-fix_1441692.patch
projects[config_perms][patch][1229198] = https://drupal.org/files/config_perms-invalid_argument_foreach-1229198-5.patch
projects[config_perms][patch][2200925] = https://drupal.org/files/issues/config_perms-invalid_argument_foreach_cache_clear-2200925-1.patch
projects[config_perms][patch][2307543] = https://drupal.org/files/issues/config_perms-php-notice-2307543-1.patch

; Diff - Used to display diffs in revisions
projects[diff][version] = 3.2
projects[diff][subdir] = contrib

; Email - Provides field type for email addresses
projects[email][version] = 1.2
projects[email][subdir] = contrib

; Entity View Mode - Used for View Modes (image styles)
projects[entity_view_mode][version] = 1.0-rc1
projects[entity_view_mode][subdir] = contrib

; External Link - extlink and mailto icons and behavior
projects[extlink][version] = 1.13
projects[extlink][subdir] = contrib

; FAQ Module 
projects[faq][version] = 1.0-rc2
projects[faq][subdir] = contrib
projects[faq][patch][1828758] = https://drupal.org/files/1828758-1-category-descriptions-dont-respect-text-formats.patch
; 1572414: later patch available
projects[faq][patch][1572414] = https://drupal.org/files/faq-view_question-1572414-2.patch

; Features Override
projects[features_override][version] = 2.0-rc1
projects[features_override][subdir] = contrib

; Google Analytics
projects[google_analytics][version] = 1.4
projects[google_analytics][subdir] = contrib

; Link Checker
projects[linkchecker][version] = 1.1
projects[linkchecker][subdir] = contrib

; Navigation 404
projects[navigation404][version] = 1.0
projects[navigation404][subdir] = contrib

; Nice Menus - used with Berkeley Theme
projects[nice_menus][version] = 2.5
projects[nice_menus][subdir] = contrib

; Pathologic - Used for dev/test/live/localhost paths
projects[pathologic][version] = 2.11
projects[pathologic][subdir] = contrib

; Redirect - Combined path redirect and global redirect for D7
projects[redirect][version] = 1.0-rc1
projects[redirect][subdir] = contrib

; Security Review - Part of go-live process
projects[security_review][version] = 1.0
projects[security_review][subdir] = contrib

; SMTP
projects[smtp][version] = 1.0
projects[smtp][subdir] = contrib

; Total Control - Used for Site Builder dashboard
projects[total_control][version] = 2.4
projects[total_control][subdir] = contrib

; Zen - Base theme for Berkeley Theme
projects[zen][version] = 5.5
projects[zen][type] = theme

; ***** End OB not in Panopoly *****
; **********************************


; *******************************************
; ***** Updates Different from Panopoly *****


; Add versions different from Panopoly here

; Migrate
projects[migrate][version] = 2.5
projects[migrate][subdir] = contrib
; Include Dave Reid's patch for Block support.
projects[migrate][patch][2224297] = http://drupal.org/files/issues/2224297-destination-block-custom_0.patch

; ***** End Updates Different from Panopoly *****
; ***********************************************


; ****************************
; *****Panopoly Features *****

; Use Drush 6 to run make file. See https://github.com/drush-ops/drush/issues/15

; Previously, makefiles were parsed bottom-up, and that in Drush concurrency might
; interfere with recursion.
; Therefore PANOPOLY needs to be listed AT THE BOTTOM of this makefile,
; so we can patch or update certain projects fetched by Panopoly's makefiles.

; The Panopoly Foundation

projects[panopoly_core][version] = 1.x-dev
projects[panopoly_core][subdir] = panopoly
projects[panopoly_core][download][type] = git
projects[panopoly_core][download][revision] = 6e36a51
projects[panopoly_core][download][branch] = 7.x-1.x

projects[panopoly_images][version] = 1.x-dev
projects[panopoly_images][subdir] = panopoly
projects[panopoly_images][download][type] = git
projects[panopoly_images][download][revision] = 647d00f
projects[panopoly_images][download][branch] = 7.x-1.x

projects[panopoly_theme][version] = 1.x-dev
projects[panopoly_theme][subdir] = panopoly
projects[panopoly_theme][download][type] = git
projects[panopoly_theme][download][revision] = a06260a
projects[panopoly_theme][download][branch] = 7.x-1.x

projects[panopoly_magic][version] = 1.x-dev
projects[panopoly_magic][subdir] = panopoly
projects[panopoly_magic][download][type] = git
projects[panopoly_magic][download][revision] = 00252a8
projects[panopoly_magic][download][branch] = 7.x-1.x

projects[panopoly_widgets][version] = 1.x-dev
projects[panopoly_widgets][subdir] = panopoly
projects[panopoly_widgets][download][type] = git
projects[panopoly_widgets][download][revision] = f42092e
projects[panopoly_widgets][download][branch] = 7.x-1.x

projects[panopoly_admin][version] = 1.x-dev
projects[panopoly_admin][subdir] = panopoly
projects[panopoly_admin][download][type] = git
projects[panopoly_admin][download][revision] = ea54328
projects[panopoly_admin][download][branch] = 7.x-1.x

projects[panopoly_users][version] = 1.x-dev
projects[panopoly_users][subdir] = panopoly
projects[panopoly_users][download][type] = git
projects[panopoly_users][download][revision] = 981daef
projects[panopoly_users][download][branch] = 7.x-1.x

; The Panopoly Toolset

projects[panopoly_pages][version] = 1.x-dev
projects[panopoly_pages][subdir] = panopoly
projects[panopoly_pages][download][type] = git
projects[panopoly_pages][download][revision] = a51d319
projects[panopoly_pages][download][branch] = 7.x-1.x

projects[panopoly_wysiwyg][version] = 1.x-dev
projects[panopoly_wysiwyg][subdir] = panopoly
projects[panopoly_wysiwyg][download][type] = git
projects[panopoly_wysiwyg][download][revision] = 126072a
projects[panopoly_wysiwyg][download][branch] = 7.x-1.x

projects[panopoly_search][version] = 1.x-dev
projects[panopoly_search][subdir] = panopoly
projects[panopoly_search][download][type] = git
projects[panopoly_search][download][revision] = aa2a293
projects[panopoly_search][download][branch] = 7.x-1.x

; For running the automated tests.

projects[panopoly_test][version] = 1.x-dev
projects[panopoly_test][subdir] = panopoly
projects[panopoly_test][type] = module
projects[panopoly_test][download][type] = git
projects[panopoly_test][download][revision] = ecfb4c2
projects[panopoly_test][download][branch] = 7.x-1.x

