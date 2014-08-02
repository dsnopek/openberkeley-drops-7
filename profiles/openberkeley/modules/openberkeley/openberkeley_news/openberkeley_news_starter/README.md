# openberkeley_news_starter#


Open Berkeley News Starter module. Starter content for Open Berkeley News feature.

## Term Migration ##

The easiest way to create the "General" term in the News Type vocabulary is to
simply use the create_term argument in the field mapping for the term reference
field in the OpenBerkeleyNewsStarterNodePages migration:

openberkeley_news_starter.pages.inc:
```
$this->addFieldMapping('field_news_type', 'news type');
    $this->addFieldMapping('field_news_type:create_term')
      ->defaultValue(TRUE);
```

For this reason the OpenBerkeleyNewsStarterTerm migration is unneeded, however
openberkeley_news_starter.terms.inc and openberkeley_news_starter.terms.csv
are included in case they are useful in the future.

## Blocks Migration ##

No blocks are involved in this migration, but commented blocks code is included
for future reference.

## On Module Disable ##

When the module is disabled, the starter content will be removed.  The General
term will only be removed from the News Type vocabulary if no nodes are
associated with it.