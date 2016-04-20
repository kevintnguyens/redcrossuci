<?php
/**
 * @file
 * event_feed_ical.feeds_importer_default.inc
 */

/**
 * Implements hook_feeds_importer_default().
 */
function event_feed_ical_feeds_importer_default() {
  $export = array();

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'ical_importer';
  $feeds_importer->config = array(
    'name' => 'ICAL importer',
    'description' => 'imports events from an ical link',
    'fetcher' => array(
      'plugin_key' => 'FeedsHTTPFetcher',
      'config' => array(
        'auto_detect_feeds' => FALSE,
        'use_pubsubhubbub' => FALSE,
        'designated_hub' => '',
        'request_timeout' => NULL,
        'auto_scheme' => 'http',
        'accept_invalid_cert' => FALSE,
      ),
    ),
    'parser' => array(
      'plugin_key' => 'DateiCalFeedsParser',
      'config' => array(
        'indefinite_count' => '52',
        'indefinite_message_display' => TRUE,
        'until_not_utc' => FALSE,
        'skip_days' => NULL,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsNodeProcessor',
      'config' => array(
        'expire' => '31536000',
        'author' => 0,
        'authorize' => 1,
        'mappings' => array(
          0 => array(
            'source' => 'UID',
            'target' => 'guid',
            'unique' => FALSE,
            'language' => 'und',
          ),
          1 => array(
            'source' => 'SUMMARY',
            'target' => 'title_field',
            'unique' => FALSE,
            'language' => 'und',
          ),
          2 => array(
            'source' => 'DTSTART',
            'target' => 'field_date:start',
            'unique' => FALSE,
            'language' => 'und',
          ),
          3 => array(
            'source' => 'DTEND',
            'target' => 'field_date:end',
            'unique' => FALSE,
            'language' => 'und',
          ),
          4 => array(
            'source' => 'DESCRIPTION',
            'target' => 'body',
            'unique' => FALSE,
            'language' => 'und',
          ),
          5 => array(
            'source' => 'SUMMARY',
            'target' => 'title',
            'unique' => FALSE,
          ),
        ),
        'insert_new' => '1',
        'update_existing' => '2',
        'update_non_existent' => 'skip',
        'input_format' => 'plain_text',
        'skip_hash_check' => 0,
        'bundle' => 'event',
        'language' => 'und',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => 1800,
    'expire_period' => 3600,
    'import_on_create' => TRUE,
    'process_in_background' => FALSE,
  );
  $export['ical_importer'] = $feeds_importer;

  return $export;
}
