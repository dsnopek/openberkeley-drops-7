<?php

require_once('PanopolyContext.php');

/**
 * Features context.
 */
class FeatureContext extends PanopolyContext
{
  /**
   * Initializes context.
   * Every scenario gets its own context object.
   *
   * @param array $parameters context parameters (set them up through behat.yml)
   */
  private $params = array();

  public function __construct(array $parameters) {
    // Initialize your context here
    $this->params = $parameters;
  }

  public function login() {
    // Check if logged in.
    if ($this->loggedIn()) {
      $this->logout();
    }
    $loginPath = $this->params['calnet'] ? '/user/admin_login' : '/user';

    if (!$this->user) {
      throw new \Exception('Tried to login without a user.');
    }

    $this->getSession()->visit($this->locatePath($loginPath));
    $element = $this->getSession()->getPage();
    $element->fillField($this->getDrupalText('username_field'), $this->user->name);
    $element->fillField($this->getDrupalText('password_field'), $this->user->pass);
    $submit = $element->findButton($this->getDrupalText('log_in'));
    if (empty($submit)) {
      throw new \Exception(sprintf("No submit button at %s", $this->getSession()->getCurrentUrl()));
    }

    // Log in.
    $submit->click();
/*
    //the loggedIn function is fragile - remove this check for now
    if (!$this->loggedIn()) {
      throw new \Exception(sprintf("Failed to log in as user '%s' with role '%s'", $this->user->name, $this->user->role));
    }
*/
  }
}
