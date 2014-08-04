# openberkeley_faq_starter#


Open Berkeley FAQ Starter module. Starter content for Open Berkeley FAQ feature.

## Term Migration ##

Since the Category field is required, we create the "General" term when 
openberkeley_faq is enabled - if there are no terms in the vocabulary already.

In addition, we use create_term argument in the field mapping for the term 
reference field in the OpenBerkeleyFaqStarterNodePages migration:

openberkeley_faq_starter.pages.inc:
```
$this->addFieldMapping('field_openberkeley_faq_cat', 'category');
    $this->addFieldMapping('field_openberkeley_faq_cat:create_term')
      ->defaultValue(TRUE);
```

This allows starter content to be created with different terms, showing what 
categorization looks like on the main FAQ page.

## On Module Disable ##

When the module is disabled, the starter content will be removed.  The added
terms will only be removed from the faqs vocabulary if no nodes are
associated with them.
