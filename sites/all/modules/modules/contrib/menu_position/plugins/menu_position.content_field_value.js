(function ($) {

/**
 * Provide the summary information for the content field value plugin's vertical tab.
 */
Drupal.behaviors.menuPositionContentFieldValueSettingsSummary = {
  attach: function (context) {
    $('fieldset#edit-content-field-value', context).drupalSetSummary(function (context) {
      if ($('#edit-content-field-name', context).val()) {
        var field_data = {
          '@field_name' : $('#edit-content-field-name').val(),
          '@field_value' : $('#edit-content-field-value--2', context).val()
        };
        return Drupal.t('Field name: @field_name<br>Field value: @field_value', field_data);
      }
      else {
        return Drupal.t('Any content field value');
      }
    });
  }
};

})(jQuery);
