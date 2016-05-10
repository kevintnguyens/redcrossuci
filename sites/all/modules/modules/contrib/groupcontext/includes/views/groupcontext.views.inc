<?php
/**
 * @file
 * Provides support for the Views module.
 */

/**
 * Implements hook_views_plugins().
 */
function groupcontext_views_plugins() {
  return array(
    'access' => array(
      'groupcontext' => array(
        'title' => t('Group permission'),
        'handler' => 'groupcontext_plugin_access_group_perm',
        'uses options' => TRUE,
      ),
    ),
  );
}
