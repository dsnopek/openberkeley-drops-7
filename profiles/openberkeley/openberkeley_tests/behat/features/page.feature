Feature: Create content
  In order to add content to my site
  As a site builder
  I need to be able to create a basic content page

  Background:
    Given I am logged in as a user with the "administrator" role
      And I wait 5 seconds
      And Panopoly magic live previews are disabled
    When I visit "/node/add/openberkeley-content-page"
      And I fill in the following:
        | Title               | Testing title |
        | Editor              | plain_text    |
        | body[und][0][value] | Testing body  |
      And I press "Publish"
    Then the "#page-title" element should contain "Testing title"
      And I should see the link "Edit" in the "Tabs" region

  @api
  Scenario: Change the alias of a content page - headless version
    When I click "Edit" in the "Tabs" region
      And I uncheck "Generate automatic URL alias"
      And I fill in "edit-path-alias" with "new-path"
      And I press "Save"
    Then I should be on "new-path"

  @api @javascript
  Scenario: Add page to menu
    When I click "Edit" in the "Tabs" region
      And I check "Provide a menu link"
      And I fill in "edit-menu-link-title" with "Test menu item"
      And I select "<Main menu>" from "edit-menu-parent"
      And I press "Save"
    Then I should see the link "Test menu item" in the "Main menu" region
