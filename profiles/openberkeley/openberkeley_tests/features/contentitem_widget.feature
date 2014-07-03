Feature: Add content item
  In order to put in a particular content item on a page
  As a site administrator
  I need to be able to choose which content item

  @api @javascript
  Scenario: Add content item
    Given I am logged in as a user with the "builder" role
      And Panopoly magic live previews are disabled
    When I visit "/node/add/panopoly-page"
      And I fill in the following:
        | Title               | Testing title |
        | Editor              | plain_text    |
        | body[und][0][value] | Testing body  |
      And I press "Save"
    Then the "#page-title" element should contain "Testing title"
    When I customize this page with the Panels IPE
      And I click "Add new pane"
      And I click "Add content item" in the "CTools modal" region
    Then I should see "Configure new Add content item"
    When I fill in the following:
      | exposed[title]        | Credits  |
    When I select "Content Page" from "exposed[type]"
      And I press "edit-return"
      And I press "Save as custom"
      And I wait for the Panels IPE to deactivate
    Then I should see "Credits"
      And I should see "November 13, 2012"
