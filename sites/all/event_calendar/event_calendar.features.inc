<?php
/**
 * @file
 * event_calendar.features.inc
 */

/**
 * Implements hook_views_api().
 */
function event_calendar_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}
