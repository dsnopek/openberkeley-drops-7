Feature: Admin login
In order to log in if CalNet is down
As an anonymous user
I want to be able to login without CalNet

  Scenario: User can get to backdoor
    Given I am on "/user/admin_login"
    Then I should see the message containing "Admins should login via Calnet whenever possible."
      And I should see an "#edit-name" element

  @api
  Scenario: User log in via backdoor
    Given I am logged in as a user with the "builder" role
    Then I should see "Log out"
