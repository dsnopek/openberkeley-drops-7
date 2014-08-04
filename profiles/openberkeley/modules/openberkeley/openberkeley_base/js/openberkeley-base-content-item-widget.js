(function ($) {
  // Monkey patch Drupal.jsAC to trigger the input field's change event when
  // the user selects an autocomplete value. This happens in both the 'select'
  // and 'hidePopup' functions.
  function monkeyPatchAC(jsAC, name) {
    var oldFunc = jsAC.prototype[name],
        newFunc = function (arg1) {
          var oldValue = this.input.value,
              retval = oldFunc.call(this, arg1);
          if (this.input.value !== oldValue) {
            $(this.input).change();
          }
          return retval;
        };

    jsAC.prototype[name] = newFunc;
  }
  monkeyPatchAC(Drupal.jsAC, 'select');
  monkeyPatchAC(Drupal.jsAC, 'hidePopup');

  // On the settings form for the "Content Item" widget, add a node link to
  // the page when the user enters a valid title for a node.
  Drupal.behaviors.openberkeley_base_content_item_widget = {
    attach: function (context, settings) {
      var form = $('form#views-content-views-panes-content-type-edit-form', context),
          input = $('input#edit-exposed-title', form),
          view_name = $('input[name="_view_name"]', form).val(),
          timeout = null,
          xhr = null;

      function updateNodeLink() {
        var nodeLink = input.next('a');

        // Create the nodeLink if it doesn't exist.
        if (nodeLink.length === 0) {
          nodeLink = $('<a href="#"></a>').insertAfter(input);
        }

        // Hide it since we know it's not longer current.
        //
        // Note: We can't use nodeLink.hide(), because that will cause the link
        // to lose focus, which it'll have if the user pressed TAB in the
        // autocomplete. If focus is lost, it returns to the top of the page
        // underneath the dialog!
        nodeLink.text('');

        // Abort the current request if we're starting a new one.
        if (xhr && xhr.readystate != 4) {
          xhr.abort();
          xhr = null;
        }

        // Clear timeout if we've already started waiting to send the request.
        if (timeout) {
          clearTimeout(timeout);
          timeout = null;
        }

        // Start waiting 300 milliseconds to send the request.
        timeout = setTimeout(function () {
          xhr = $.ajax({
            url: settings.basePath + 'openberkeley_base/ajax/find_node_by_title/' + Drupal.encodePath(input.val()),
            dataType: 'json',
            success: function (data) {
              // If we receive a good response, then update and show
              // the nodeLink.
              if (data && data.nid && data.path) {
                nodeLink
                  .attr('href', settings.basePath + data.path)
                  .text('View "' + data.title + '" (nid: ' + data.nid + ')')
                  .show();
              }
            }
          });
        }, 300);
      }

      // If we are on the correct form, update the node link and attach our
      // event handlers so it'll get updated again when the title changes.
      if (form.length && view_name === 'panopoly_widgets_general_content-piece_of_content') {
        //if (input.val().trim().length > 0) {
          updateNodeLink();
        //}
        //input.keyup(updateNodeLink);
        input.change(updateNodeLink);
      }
    }
  };
})(jQuery);
