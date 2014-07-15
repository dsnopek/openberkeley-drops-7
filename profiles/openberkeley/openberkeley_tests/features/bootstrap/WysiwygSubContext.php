<?php
/**
 * @file
 * Provide Behat step-definitions for WYSIWYG editor.
 *
 * @todo This should move to the WYSIWYG feature folder eventually
 */

use Drupal\DrupalExtension\Context\DrupalSubContextInterface;
use Behat\Behat\Context\BehatContext;

class WysiwygSubContext extends BehatContext implements DrupalSubContextInterface {
  /**
   * Initializes context.
   */
  public function __construct(array $parameters = array()) {
  }

  public static function getAlias() {
    return 'wysiwyg';
  }

  /**
   * Get the session from the parent context.
   */
  protected function getSession() {
    return $this->getMainContext()->getSession();
  }

  /**
   * @Given /^I select the text in the WYSIWYG editor$/
   */
  public function iSelectTheTextInTheEditor($editorFrame='edit-body-und-0-value_ifr', $editorType='tinymce') {
    /*
     * @todo :
     * Figure out how to run non-headless;
     * Allow for more than one WYSIWYG field on a page;
     * Allow for only a subset of the text to be selected;
     * Allow for different WYSYWYG editor types;
     * Parameterize;
     * Test results with more buttons than just Bold and Italic!
     */

    //verify presence of field
    $driver = $this->getSession()->getDriver();
    $editor = $driver->find("//iframe[@id='$editorFrame']");

    if (empty($editor)) {
      throw new \Exception(sprintf('The editor "%s" was not found on the page %s', $editorFrame, $this->getSession()->getCurrentUrl()));
    }

    $selector = "document.getElementById('$editorFrame').contentDocument.getElementById('$editorType')";

    //create and inject javascript
    $javascript  = "selection = window.getSelection();";
    $javascript .= "range = document.createRange();";
    $javascript .= "range.selectNodeContents($selector);";
    $javascript .= "selection.removeAllRanges();";
    $javascript .= "selection.addRange(range);";

    $this->getSession()->executeScript($javascript);
  }


  /**
   * Get the instance variable to use in Javascript.
   *
   * @param string
   *   The instanceId used by the WYSIWYG module to identify the instance.
   *
   * @throws Exeception
   *   Throws an exception if the editor doesn't exist.
   *
   * @return string
   *   A Javascript expression representing the WYSIWYG instance.
   */
  protected function getWysiwygInstance($instanceId) {
    $instance = "Drupal.wysiwyg.instances['$instanceId']";

    if (!$this->getSession()->evaluateScript("return !!$instance")) {
      throw new \Exception(sprintf('The editor "%s" was not found on the page %s', $instanceId, $this->getSession()->getCurrentUrl()));
    }

    return $instance;
  }

  /**
   * Get a Mink Element representing the WYSIWYG toolbar.
   *
   * @param string
   *   The instanceId used by the WYSIWYG module to identify the instance.
   * @param string
   *   Identifies the underlying editor (for example, "tinymce").
   *
   * @throws Exeception
   *   Throws an exception if the toolbar can't be found.
   *
   * @return \Behat\Mink\Element\NodeElement
   *   The toolbar DOM Node.
   */
  protected function getWysiwygToolbar($instanceId, $editorType) {
    $driver = $this->getSession()->getDriver();

    // TODO: This is tinyMCE specific. We should probably do a switch statement
    // based on $editorType.
    $toolbarElement = $driver->find("//div[@id='{$instanceId}_toolbargroup']");
    $toolbarElement = !empty($toolbarElement) ? $toolbarElement[0] : NULL;
    if (!$toolbarElement) {
      throw new \Exception(sprintf('Toolbar for editor "%s" was not found on the page %s', $instanceId, $this->getSession()->getCurrentUrl()));
    }

    return $toolbarElement;
  }

  /**
   * @When /^I type "([^"]*)" in the "([^"]*)" WYSIWYG editor$/
   */
  public function iTypeInTheWysiwygEditor($text, $instanceId) {
    $instance = $this->getWysiwygInstance($instanceId);
    $this->getSession()->executeScript("$instance.insert(\"$text\");");
  }

  /**
   * @When /^I fill in the "([^"]*)" WYSIWYG editor with "([^"]*)"$/
   */
  public function iFillInTheWysiwygEditor($instanceId, $text) {
    $instance = $this->getWysiwygInstance($instanceId);
    $this->getSession()->executeScript("$instance.setContent(\"$text\");");
  }

  /**
   * @When /^I click the "([^"]*)" button in the "([^"]*)" WYSIWYG editor$/
   */
  public function iClickTheButtonInTheWysiwygEditor($action, $instanceId) {
    $driver = $this->getSession()->getDriver();

    $instance = $this->getWysiwygInstance($instanceId);
    $editorType = $this->getSession()->evaluateScript("return $instance.editor");
    $toolbarElement = $this->getWysiwygToolbar($instanceId, $editorType);

    // Click the action button.
    $button = $toolbarElement->find("xpath", "//a[starts-with(@title, '$action')]");
    $button->click();
    $driver->wait(1000, TRUE);
  }

  /**
   * @When /^I expand the toolbar in the "([^"]*)" WYSIWYG editor$/
   */
  public function iExpandTheToolbarInTheWysiwygEditor($instanceId) {
    $driver = $this->getSession()->getDriver();

    $instance = $this->getWysiwygInstance($instanceId);
    $editorType = $this->getSession()->evaluateScript("return $instance.editor");
    $toolbarElement = $this->getWysiwygToolbar($instanceId, $editorType);

    // TODO: This is tinyMCE specific. We should probably switch on
    // $editorType.
    $action = 'Show/hide toolbars';

    // Expand wysiwyg toolbar.
    $button = $toolbarElement->find("xpath", "//a[starts-with(@title, '$action')]");
    if (strpos($button->getAttribute('class'), 'mceButtonActive') !== FALSE) {
      $button->click();
    }
  }

  /**
   * @Then /^I should see "([^"]*)" in the "([^"]*)" WYSIWYG editor$/
   */
  public function assertContentInWysiwygEditor($text, $tag, $region) {
    $instance = $this->getWysiwygInstance($instanceId);
    $content = $this->evaluateScript("return $instance.getContent()");
    if (strpos($text, $content) === FALSE) {
      throw new \Exception(sprintf('The text "%s" was not found in the "%s" WYSWIYG editor on the page %s', $text, $instanceId, $this->getSession()->getCurrentUrl()));
    }
  }

  /**
   * @Then /^I should not see "([^"]*)" in the "([^"]*)" WYSIWYG editor$/
   */
  public function assertContentNotInWysiwygEditor($text, $tag, $region) {
    $instance = $this->getWysiwygInstance($instanceId);
    $content = $this->evaluateScript("return $instance.getContent()");
    if (strpos($text, $content) !== FALSE) {
      throw new \Exception(sprintf('The text "%s" was found in the "%s" WYSWIYG editor on the page %s', $text, $instanceId, $this->getSession()->getCurrentUrl()));
    }
  }
}
