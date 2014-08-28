api = 2
core = 7.x

;;;;;;;;;;;;;;;;;;;;;;;;;;
;;; UCB Custom Modules ;;;
;;;;;;;;;;;;;;;;;;;;;;;;;;

projects[ucberkeley_cas][type] = module
projects[ucberkeley_cas][subdir] = ucb
projects[ucberkeley_cas][download][type] = file
projects[ucberkeley_cas][download][url] = https://github.com/ucb-ist-drupal/ucberkeley_cas-7/releases/download/7.x-2.1-beta3/ucberkeley_cas-7.x-2.1-beta3.tar.gz

projects[openberkeley_admin][type] = module
projects[openberkeley_admin][subdir] = openberkeley
projects[openberkeley_admin][download][type] = git
projects[openberkeley_admin][download][url] = git://github.com/ucb-ist-drupal/openberkeley_admin.git


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

projects[openberkeley_media][type] = module
projects[openberkeley_media][subdir] = openberkeley
projects[openberkeley_media][download][type] = git
projects[openberkeley_media][download][url] = git://github.com/ucb-ist-drupal/openberkeley_media.git

projects[openberkeley_starter][type] = module
projects[openberkeley_starter][subdir] = openberkeley
projects[openberkeley_starter][download][type] = git
projects[openberkeley_starter][download][url] = git://github.com/ucb-ist-drupal/openberkeley_starter.git

projects[openberkeley_theme][type] = module
projects[openberkeley_theme][subdir] = openberkeley
projects[openberkeley_theme][download][type] = git
projects[openberkeley_theme][download][url] = git://github.com/ucb-ist-drupal/openberkeley_theme.git

projects[openberkeley_news][type] = module
projects[openberkeley_news][subdir] = openberkeley
projects[openberkeley_news][download][type] = git
projects[openberkeley_news][download][url] = git://github.com/ucb-ist-drupal/openberkeley_news.git

projects[openberkeley_faq][type] = module
projects[openberkeley_faq][subdir] = openberkeley
projects[openberkeley_faq][download][type] = git
projects[openberkeley_faq][download][url] = git://github.com/ucb-ist-drupal/openberkeley_faq.git

;;;;;;;;;;;;;;;;;
;;; UCB Theme ;;;
;;;;;;;;;;;;;;;;;

projects[berkeley][type] = theme
projects[berkeley][download][type] = git
projects[berkeley][download][url] = git://github.com/ucb-ist-drupal/berkeley.git
projects[berkeley][download][branch] = master
;projects[berkeley][download][tag] = 7.x-1.0-alpha11
;projects[berkeley][download][revision] = 6c3173a

;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;; UCB Contrib Modules ;;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;

; ******************************
; ***** OB not in Panopoly *****

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
; TODO: delete after testing openberkeley_media
; projects[entity_view_mode][version] = 1.0-rc1
; projects[entity_view_mode][subdir] = contrib

; External Link - extlink and mailto icons and behavior
projects[extlink][version] = 1.13
projects[extlink][subdir] = contrib

; FAQ Module 
; commented out ;TODO: Delete once openberkeley_faq has been tested. 
; projects[faq][version] = 1.0-rc2
; projects[faq][subdir] = contrib
; projects[faq][patch][1828758] = https://drupal.org/files/1828758-1-category-descriptions-dont-respect-text-formats.patch
; 1572414: later patch available
; projects[faq][patch][1572414] = https://drupal.org/files/faq-view_question-1572414-2.patch

; Features Override
projects[features_override][version] = 2.0-rc1
projects[features_override][subdir] = contrib

; Nice Menus - used with Berkeley Theme
projects[nice_menus][version] = 2.5
projects[nice_menus][subdir] = contrib

; Pathologic - Used for dev/test/live/localhost paths
projects[pathologic][version] = 2.11
projects[pathologic][subdir] = contrib

; Security Review - Part of go-live process
projects[security_review][version] = 1.0
projects[security_review][subdir] = contrib

; SMTP
projects[smtp][version] = 1.0
projects[smtp][subdir] = contrib

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
projects[panopoly_core][download][revision] = cc631ea
projects[panopoly_core][download][branch] = 7.x-1.x

projects[panopoly_images][version] = 1.x-dev
projects[panopoly_images][subdir] = panopoly
projects[panopoly_images][download][type] = git
projects[panopoly_images][download][revision] = 5b4155c
projects[panopoly_images][download][branch] = 7.x-1.x

projects[panopoly_theme][version] = 1.x-dev
projects[panopoly_theme][subdir] = panopoly
projects[panopoly_theme][download][type] = git
projects[panopoly_theme][download][revision] = 242f70e
projects[panopoly_theme][download][branch] = 7.x-1.x

projects[panopoly_magic][version] = 1.x-dev
projects[panopoly_magic][subdir] = panopoly
projects[panopoly_magic][download][type] = git
projects[panopoly_magic][download][revision] = 56a6d74
projects[panopoly_magic][download][branch] = 7.x-1.x

projects[panopoly_widgets][version] = 1.x-dev
projects[panopoly_widgets][subdir] = panopoly
projects[panopoly_widgets][download][type] = git
projects[panopoly_widgets][download][revision] = a6ea204
projects[panopoly_widgets][download][branch] = 7.x-1.x

projects[panopoly_admin][version] = 1.x-dev
projects[panopoly_admin][subdir] = panopoly
projects[panopoly_admin][download][type] = git
projects[panopoly_admin][download][revision] = 8c4e01d
projects[panopoly_admin][download][branch] = 7.x-1.x

projects[panopoly_users][version] = 1.x-dev
projects[panopoly_users][subdir] = panopoly
projects[panopoly_users][download][type] = git
projects[panopoly_users][download][revision] = 6a02f79
projects[panopoly_users][download][branch] = 7.x-1.x

; The Panopoly Toolset

projects[panopoly_pages][version] = 1.x-dev
projects[panopoly_pages][subdir] = panopoly
projects[panopoly_pages][download][type] = git
projects[panopoly_pages][download][revision] = a70fcd9
projects[panopoly_pages][download][branch] = 7.x-1.x

projects[panopoly_wysiwyg][version] = 1.x-dev
projects[panopoly_wysiwyg][subdir] = panopoly
projects[panopoly_wysiwyg][download][type] = git
projects[panopoly_wysiwyg][download][revision] = 47b5799
projects[panopoly_wysiwyg][download][branch] = 7.x-1.x

projects[panopoly_search][version] = 1.x-dev
projects[panopoly_search][subdir] = panopoly
projects[panopoly_search][download][type] = git
projects[panopoly_search][download][revision] = ac7d5da
projects[panopoly_search][download][branch] = 7.x-1.x
projects[panopoly_search][patch][2080893] = https://www.drupal.org/files/issues/panopoly_search-update-search-api-2080893-17.patch

; For running the automated tests.

projects[panopoly_test][version] = 1.x-dev
projects[panopoly_test][subdir] = panopoly
projects[panopoly_test][type] = module
projects[panopoly_test][download][type] = git
projects[panopoly_test][download][revision] = a51edf6
projects[panopoly_test][download][branch] = 7.x-1.x

; Patch to remove dependency on panopoly_pages.
projects[panopoly_test][patch][2316067] = http://drupal.org/files/issues/panopoly-test-remove-pages-dependency-2316067-1.patch

; Note: Removed patches #2316157 and #2268641 because they've been merged into upstream Panopoly
