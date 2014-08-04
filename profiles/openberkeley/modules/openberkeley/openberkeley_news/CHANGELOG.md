Open Berkeley News - CHANGELOG
==============================

openberkeley_news-7.x-0.1-beta1
------------------------------
* OPENUCB-330: Dependencies
** Removed dependency on panopoly_pages. Added dependency on panopoly_core. Removed redundant dependencies.
* OPENUCB-330: Namespacing
** Namespaced the feature; renamed CSS to match naming convention.
* OPENUCB-330: Permissions
** Added permissions to manage news taxonomy terms; removed unnecessary Panelizer permission
* OPENUCB-330: Updated views, panel page, taxonomy, RSS feed
** Added field_openberkeley_news_byline, field_openberkeley_news_type; removed description from node_info; added taxonomy; change view human_names and displays; change permissions
** Added openberkeley_newsarchive.css from Berkeley theme
* OPENUCB-330: Initial version of openberkeley_news content
