<?php
/**
 * @file
 * event_feed_ical.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function event_feed_ical_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "feeds" && $api == "feeds_importer_default") {
    return array("version" => "1");
  }
}
