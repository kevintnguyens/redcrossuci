<?php
/**
 * @file
 * Administration functions for Group context module.
 */

/**
 * Setting for language negotiation options
 */
function groupcontext_configure_form() {
  $form = array(
    '#submit' => array('groupcontext_configure_form_submit'),
    '#theme' => 'groupcontext_configure_form',
    '#groupcontext_providers' => groupcontext_negotiation_info(),
  );

  _groupcontext_configure_form_table($form);

  $form['actions'] = array('#type' => 'actions');
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save settings'),
  );

  return $form;
}

/**
 * Helper function to build a group context provider table.
 */
function _groupcontext_configure_form_table(&$form) {
  $type = 'groupcontext';

  $table_form = array(
    '#title' => t('Group context detection'),
    '#tree' => TRUE,
    '#description' => t('Order of Group context detection methods.'),
    '#groupcontext_providers' => array(),
    '#show_operations' => FALSE,
    'weight' => array('#tree' => TRUE),
    'enabled' => array('#tree' => TRUE),
  );

  $groupcontext_providers = $form['#groupcontext_providers'];
  // Enable url and node context handlers by default.
  $defaults = array('url' => -5, 'node' => -4);
  $enabled_providers = variable_get("groupcontext_negotiation_$type", $defaults);
  $providers_weight = variable_get("groupcontext_providers_weight_$type", $defaults);

  // Add missing data to the providers lists.
  foreach ($groupcontext_providers as $id => $provider) {
    if (!isset($providers_weight[$id])) {
      $providers_weight[$id] = groupcontext_provider_weight($provider);
    }
  }

  // Order providers list by weight.
  asort($providers_weight);

  foreach ($providers_weight as $id => $weight) {
    $enabled = isset($enabled_providers[$id]);
    $provider = $groupcontext_providers[$id];


    $table_form['#groupcontext_providers'][$id] = $provider;

    $table_form['weight'][$id] = array(
      '#type' => 'weight',
      '#default_value' => $weight,
      '#attributes' => array('class' => array("groupcontext-provider-weight-$type")),
    );

    $table_form['title'][$id] = array('#markup' => check_plain($provider['name']));
    $table_form['enabled'][$id] = array('#type' => 'checkbox', '#default_value' => $enabled);
    $table_form['description'][$id] = array('#markup' => filter_xss_admin($provider['description']));

    $config_op = array();
    if (isset($provider['config'])) {
      $config_op = array('#type' => 'link', '#title' => t('Configure'), '#href' => $provider['config']);
      // If there is at least one operation enabled show the operation column.
      $table_form['#show_operations'] = TRUE;
    }
    $table_form['operation'][$id] = $config_op;
  }

  $form['groupcontext'] = $table_form;
}

/**
 * Returns HTML for a group context configuration form.
 *
 * @param $variables
 *   An associative array containing:
 *   - form: A render element representing the form.
 *
 * @ingroup themeable
 */
function theme_groupcontext_configure_form($variables) {
  $form = $variables['form'];
  $output = '';

  $type = 'groupcontext';
  $rows = array();
  $title = '<label>' . $form[$type]['#title'] . '</label>';
  $description = '<div class="description">' . $form[$type]['#description'] . '</div>';

  foreach ($form[$type]['title'] as $id => $element) {
    // Do not take form control structures.
    if (is_array($element) && element_child($id)) {
      $row = array(
        'data' => array(
          '<strong>' . drupal_render($form[$type]['title'][$id]) . '</strong>',
          drupal_render($form[$type]['description'][$id]),
          drupal_render($form[$type]['enabled'][$id]),
          drupal_render($form[$type]['weight'][$id]),
        ),
        'class' => array('draggable'),
      );
      if ($form[$type]['#show_operations']) {
        $row['data'][] = drupal_render($form[$type]['operation'][$id]);
      }
      $rows[] = $row;
    }
  }

  $header = array(
    array('data' => t('Detection method')),
    array('data' => t('Description')),
    array('data' => t('Enabled')),
    array('data' => t('Weight')),
  );

  // If there is at least one operation enabled show the operation column.
  if ($form[$type]['#show_operations']) {
    $header[] = array('data' => t('Operations'));
  }

  $variables = array(
    'header' => $header,
    'rows' => $rows,
    'attributes' => array('id' => "groupcontext-negotiation-providers-$type"),
  );
  $table  = theme('table', $variables);
  $table .= drupal_render_children($form[$type]);

  drupal_add_tabledrag("groupcontext-negotiation-providers-$type", 'order', 'sibling', "groupcontext-provider-weight-$type");

  $output .= '<div class="form-item">' . $title . $description . $table . '</div>';

  $output .= drupal_render_children($form);
  return $output;
}

/**
 * Submit handler for groupcontext negotiation settings.
 */
function groupcontext_configure_form_submit($form, &$form_state) {
  $type = 'groupcontext';

  $negotiation = array();
  $enabled_providers = $form_state['values'][$type]['enabled'];
  $providers_weight = $form_state['values'][$type]['weight'];

  foreach ($providers_weight as $id => $weight) {
    if ($enabled_providers[$id]) {
      $provider = $form[$type]['#groupcontext_providers'][$id];
      $provider['weight'] = $weight;
      $negotiation[$id] = $provider;
    }
  }

  groupcontext_negotiation_set($negotiation);
  variable_set("groupcontext_providers_weight_$type", $providers_weight);

  $form_state['redirect'] = 'admin/config/system/groupcontext';
  drupal_set_message(t('Group context negotiation configuration saved.'));
}
