<?php
/**
 * @file
 * Provides the "Content field value" rule plugin for the Menu Position module.
 */

/**
 * Checks if the node has a certain field with a certain value.
 *
 * @param $variables
 *   An array containing each of the variables saved in the database necessary
 *   to evaluate this condition of the rule.
 * @return boolean
 *   TRUE if condition applies successfully. Otherwise FALSE.
 */
function menu_position_menu_position_condition_content_field_value($variables) {
  // Check if this is a node page and that the specified field matches the value.
  if ($variables['context']['entity_type'] == 'node') {
    $node_wrapper = entity_metadata_wrapper('node', $variables['context']['node']);

    // Make sure the field exists on the node.
    if (!isset($node_wrapper->{$variables['content_field_name']})) {
      return FALSE;
    }

    // Get the valule of content_field
    $field_values = $node_wrapper->{$variables['content_field_name']}->value(array('identifier' => 'TRUE'));

    // Allow for multi-value fields.
    if (!is_array($field_values)) {
      $field_values = array($field_values);
    }

    foreach ($field_values as $field_value) {
      // Check if the value is a boolean type
      if (is_bool($field_value)) {
        $field_value = ($field_value) ? '1' : '0';
      }
      if ($field_value == $variables['content_field_value']) {
        return TRUE;
      }
    }
  }
  return FALSE;
}

/**
 * Adds form elements for the "Content field value" plugin to the rule configuration form.
 *
 * @param $form
 *   A reference to the "add/edit rule" form array. New form elements should be
 *   added directly to this array.
 * @param $form_state
 *   A reference to the current form state.
 */
function menu_position_menu_position_rule_content_field_value_form(&$form, &$form_state) {
  // If this is an existing rule, load the variables stored in the rule for this plugin.
  $variables = !empty($form_state['#menu-position-rule']['conditions']['content_field_value']) ? $form_state['#menu-position-rule']['conditions']['content_field_value'] : array();

  $fields_name = array_keys(field_info_fields());
  $fields_name = drupal_map_assoc($fields_name);
  $fields_name = array('' => '- please select -') + $fields_name;
  asort($fields_name);

  $form['conditions']['content_field_value'] = array(
    '#type' => 'fieldset',
    '#title' => t('Content field'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
    '#attached' => array(
      'js' => array(drupal_get_path('module', 'menu_position') . '/plugins/menu_position.content_field_value.js'),
    ),
  );

  $form['conditions']['content_field_value']['content_field_name'] = array(
    '#title' => t('Field name'),
    '#type' => 'select',
    '#options' => $fields_name,
    '#description' => t('Select the field to check'),
    '#default_value' => isset($variables['content_field_name']) ? $variables['content_field_name'] : '',
  );

  $form['conditions']['content_field_value']['content_field_value'] = array(
    '#title' => t('Field value'),
    '#type' => 'textfield',
    '#description' => t('Enter the field value to compare'),
    '#default_value' => isset($variables['content_field_value']) ? $variables['content_field_value'] : '',
  );

  // Add a submit handler.
  $form['#submit'][] = 'menu_position_menu_position_rule_content_field_value_form_submit';
}

/**
 * Prepares the "Content field value" variables to be stored in the rule.
 *
 * @param $form
 *   A reference to the "add/edit rule" form array.
 * @param $form_state
 *   A reference to the current form state, including submitted values.
 */
function menu_position_menu_position_rule_content_field_value_form_submit(&$form, &$form_state) {
  // The user has added our plugin's form elements as a condition for the rule.
  if (!empty($form_state['values']['content_field_name'])) {
    if ($form_state['values']['content_field_name']) {
      $variables = array(
        'content_field_name' => $form_state['values']['content_field_name'],
        'content_field_value' => $form_state['values']['content_field_value'],
      );
      $form_state['values']['conditions']['content_field_value'] = $variables;
    }
  }
}
