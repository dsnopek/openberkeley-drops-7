<?php
/**
 * @file
 * Template for Open Berkeley Kauai Panel Layout.
 *
 * Variables:
 * - $css_id: An optional CSS id to use for the layout.
 * - $content: An array of content, each item in the array is keyed to one
 * panel of the layout. This layout supports the following sections:
 */
?>

<div class="panel-display kauai clearfix <?php if (!empty($class)) { print $class; } ?>" <?php if (!empty($css_id)) { print "id=\"$css_id\""; } ?>>

  <div class="kauai-container kauai-column-content clearfix">
    <div class="kauai-column-content-region kauai-main panel-panel">
      <div class="kauai-column-content-region-inner kauai-main-inner panel-panel-inner">
        <?php print $content['headermain']; ?>
      </div>
    </div>
    <div class="kauai-column-content-region kauai-sidebar panel-panel">
      <div class="kauai-column-content-region-inner kauai-sidebar-inner panel-panel-inner">
        <?php print $content['headersidebar']; ?>
      </div>
    </div>
  </div>

  <div class="kauai-container clearfix panel-panel">
    <div class="kauai-container-inner panel-panel-inner">
      <?php print $content['middle']; ?>
    </div>
  </div>

  <div class="kauai-container kauai-column-content clearfix">
    <div class="kauai-column-content-region kauai-main panel-panel">
      <div class="kauai-column-content-region-inner kauai-main-inner panel-panel-inner">
        <?php print $content['footermain']; ?>
      </div>
    </div>
    <div class="kauai-column-content-region kauai-sidebar panel-panel">
      <div class="kauai-column-content-region-inner kauai-sidebar-inner panel-panel-inner">
        <?php print $content['footersidebar']; ?>
      </div>
    </div>
  </div>

</div><!-- /.kauai -->
