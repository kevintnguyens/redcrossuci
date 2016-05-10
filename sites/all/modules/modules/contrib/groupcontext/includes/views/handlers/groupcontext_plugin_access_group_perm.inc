<?php
/**
 * @file
 * Contains views access plugin for Group permissions
 */

/**
 * Allow views to allow access to only users with a specified permission in the
 * current group.
 */
class groupcontext_plugin_access_group_perm extends views_plugin_access {

  /**
   * Retrieve the options when this is a new access
   * control plugin
   */
  function option_definition() {
    $options = parent::option_definition();
    $options['perm'] = array('default' => 'edit group');

    return $options;
  }

  /**
   * Provide the default form for setting options.
   */
  function options_form(&$form, &$form_state) {
    $perms = array();
    // Get list of permissions
    foreach (group_permissions() as $perm => $title) {
      $perms[$perm] = strip_tags($title);
    }

    $form['perm'] = array(
      '#type' => 'select',
      '#options' => $perms,
      '#title' => t('Group permission'),
      '#default_value' => $this->options['perm'],
      '#description' => t('Only users with the selected permission flag in a group retrieved from context will be able to access this display.')
    );
  }

  /**
   * Return a string to display as the clickable title for the
   * access control.
   */
  function summary_title() {
    return $this->options['perm'];
  }

  /**
   * Determine if the current user has access or not.
   */
  function access($account) {
    // Attempt to get the group from arg(1) in the url and check the users has
    // access to the defined group permission.
    $gid = arg(1);
    if (is_numeric($gid)) {
      $group = group_load($gid);
      return group_access($this->options['perm'], $group, $account);
    }

    return FALSE;
  }

  /**
   * Determine the access callback and arguments.
   */
  function get_access_callback() {
    return array('_groupcontext_views_page_access', array($this->options['perm']));
  }
}
