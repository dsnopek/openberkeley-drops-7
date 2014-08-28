<?php
/**
 * @file
 * Template for Open Berkeley Oahu Panel Layout.
 *
 * Variables:
 * - $css_id: An optional CSS id to use for the layout.
 * - $content: An array of content, each item in the array is keyed to one
 * panel of the layout. This layout supports the following sections:
 */
?>

<div class="panel-display oahu clearfix <?php if (!empty($class)) { print $class; } ?>" <?php if (!empty($css_id)) { print "id=\"$css_id\""; } ?>>

  <div class="oahu-container oahu-header clearfix panel-panel">
    <div class="oahu-container-inner oahu-header-inner panel-panel-inner">
      <?php print $content['header']; ?>
    </div>
  </div>

  <div class="oahu-container oahu-column-content oahu-column-content-row1 clearfix">
    <div class="oahu-column-content-region oahu-column oahu-column1 panel-panel">
      <div class="oahu-column-content-region-inner oahu-column-inner oahu-column1-inner panel-panel-inner">
        <?php print $content['column1']; ?>
      </div>
    </div>
    <div class="oahu-column-content-region oahu-column oahu-column2 panel-panel">
      <div class="oahu-column-content-region-inner oahu-column-inner oahu-column2-inner panel-panel-inner">
        <?php print $content['column2']; ?>
      </div>
    </div>
    <div class="oahu-column-content-region oahu-column oahu-column3 panel-panel">
      <div class="oahu-column-content-region-inner oahu-column-inner oahu-column3-inner panel-panel-inner">
        <?php print $content['column3']; ?>
      </div>
    </div>
  </div>

  <div class="oahu-container oahu-second-column-content oahu-column-content-row2 clearfix">
    <div class="oahu-second-column-content-region oahu-column oahu-second-column1 panel-panel">
      <div class="oahu-second-column-content-region-inner oahu-column-inner oahu-second-column1-inner panel-panel-inner">
        <?php print $content['secondcolumn1']; ?>
      </div>
    </div>
    <div class="oahu-second-column-content-region oahu-column oahu-second-column2 panel-panel">
      <div class="oahu-second-column-content-region-inner oahu-column-inner oahu-second-column2-inner panel-panel-inner">
        <?php print $content['secondcolumn2']; ?>
      </div>
    </div>
    <div class="oahu-second-column-content-region oahu-column oahu-second-column3 panel-panel">
      <div class="oahu-second-column-content-region-inner oahu-column-inner oahu-second-column3-inner panel-panel-inner">
        <?php print $content['secondcolumn3']; ?>
      </div>
    </div>
  </div>

  <div class="oahu-container oahu-third-column-content oahu-column-content-row3 clearfix">
    <div class="oahu-third-column-content-region oahu-column oahu-third-column1 panel-panel">
      <div class="oahu-third-column-content-region-inner oahu-column-inner oahu-third-column1-inner panel-panel-inner">
        <?php print $content['thirdcolumn1']; ?>
      </div>
    </div>
    <div class="oahu-third-column-content-region oahu-column oahu-third-column2 panel-panel">
      <div class="oahu-third-column-content-region-inner oahu-column-inner oahu-third-column2-inner panel-panel-inner">
        <?php print $content['thirdcolumn2']; ?>
      </div>
    </div>
    <div class="oahu-third-column-content-region oahu-column oahu-third-column3 panel-panel">
      <div class="oahu-third-column-content-region-inner oahu-column-inner oahu-third-column3-inner panel-panel-inner">
        <?php print $content['thirdcolumn3']; ?>
      </div>
    </div>
  </div>

  <div class="oahu-container oahu-fourth-column-content oahu-column-content-row4 clearfix">
    <div class="oahu-fourth-column-content-region oahu-column oahu-fourth-column1 panel-panel">
      <div class="oahu-fourth-column-content-region-inner oahu-column-inner oahu-fourth-column1-inner panel-panel-inner">
        <?php print $content['fourthcolumn1']; ?>
      </div>
    </div>
    <div class="oahu-fourth-column-content-region oahu-column oahu-fourth-column2 panel-panel">
      <div class="oahu-fourth-column-content-region-inner oahu-column-inner oahu-fourth-column2-inner panel-panel-inner">
        <?php print $content['fourthcolumn2']; ?>
      </div>
    </div>
    <div class="oahu-fourth-column-content-region oahu-column oahu-fourth-column3 panel-panel">
      <div class="oahu-fourth-column-content-region-inner oahu-column-inner oahu-fourth-column3-inner panel-panel-inner">
        <?php print $content['fourthcolumn3']; ?>
      </div>
    </div>
  </div>

</div><!-- /.oahu -->
