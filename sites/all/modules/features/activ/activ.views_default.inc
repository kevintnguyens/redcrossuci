<?php
/**
 * @file
 * activ.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function activ_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'active_quarter';
  $view->description = 'A view that takes the a user id. and in the code takes the last current quarter term.';
  $view->tag = 'default';
  $view->base_table = 'users';
  $view->human_name = 'Active Quarter';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    3 => '3',
    2 => '2',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'field_term' => 'field_term',
    'field_event_nid' => 'field_event_nid',
    'field_points' => 'field_points',
  );
  $handler->display->display_options['style_options']['default'] = 'field_term';
  $handler->display->display_options['style_options']['info'] = array(
    'field_term' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_event_nid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_points' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Header: Global: Unfiltered text */
  $handler->display->display_options['header']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['header']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['header']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['header']['area_text_custom']['empty'] = TRUE;
  $handler->display->display_options['header']['area_text_custom']['content'] = '<h1>Current Quarter: </h1>';
  $handler->display->display_options['header']['area_text_custom']['tokenize'] = TRUE;
  /* Footer: Global: Unfiltered text */
  $handler->display->display_options['footer']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['footer']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['footer']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['footer']['area_text_custom']['empty'] = TRUE;
  $handler->display->display_options['footer']['area_text_custom']['content'] = '<div class=\'button\'><a href=\'/active-membership/%1\'>Previous Quarters</a></div>';
  $handler->display->display_options['footer']['area_text_custom']['tokenize'] = TRUE;
  /* No results behavior: Global: Unfiltered text */
  $handler->display->display_options['empty']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['empty']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['empty'] = TRUE;
  $handler->display->display_options['empty']['area_text_custom']['content'] = '<div>You do not have any voulenteer events for this quarter .  If there is a problem please email the webmaster at <a href=\'mailto:kevitn11@uci.edu\'>redcrossuci.com</a>  </div>';
  $handler->display->display_options['empty']['area_text_custom']['tokenize'] = TRUE;
  /* Relationship: User: Active Quarter (field_active_quarter) */
  $handler->display->display_options['relationships']['field_active_quarter_value']['id'] = 'field_active_quarter_value';
  $handler->display->display_options['relationships']['field_active_quarter_value']['table'] = 'field_data_field_active_quarter';
  $handler->display->display_options['relationships']['field_active_quarter_value']['field'] = 'field_active_quarter_value';
  $handler->display->display_options['relationships']['field_active_quarter_value']['required'] = TRUE;
  $handler->display->display_options['relationships']['field_active_quarter_value']['delta'] = '-1';
  /* Relationship: Field collection item: Events (field_events) */
  $handler->display->display_options['relationships']['field_events_value']['id'] = 'field_events_value';
  $handler->display->display_options['relationships']['field_events_value']['table'] = 'field_data_field_events';
  $handler->display->display_options['relationships']['field_events_value']['field'] = 'field_events_value';
  $handler->display->display_options['relationships']['field_events_value']['relationship'] = 'field_active_quarter_value';
  $handler->display->display_options['relationships']['field_events_value']['delta'] = '-1';
  /* Relationship: Field: Term (field_term) */
  $handler->display->display_options['relationships']['field_term_tid']['id'] = 'field_term_tid';
  $handler->display->display_options['relationships']['field_term_tid']['table'] = 'field_data_field_term';
  $handler->display->display_options['relationships']['field_term_tid']['field'] = 'field_term_tid';
  $handler->display->display_options['relationships']['field_term_tid']['relationship'] = 'field_active_quarter_value';
  /* Field: Field: Term */
  $handler->display->display_options['fields']['field_term']['id'] = 'field_term';
  $handler->display->display_options['fields']['field_term']['table'] = 'field_data_field_term';
  $handler->display->display_options['fields']['field_term']['field'] = 'field_term';
  $handler->display->display_options['fields']['field_term']['relationship'] = 'field_active_quarter_value';
  $handler->display->display_options['fields']['field_term']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Field collection item: Event_nid */
  $handler->display->display_options['fields']['field_event_nid']['id'] = 'field_event_nid';
  $handler->display->display_options['fields']['field_event_nid']['table'] = 'field_data_field_event_nid';
  $handler->display->display_options['fields']['field_event_nid']['field'] = 'field_event_nid';
  $handler->display->display_options['fields']['field_event_nid']['relationship'] = 'field_events_value';
  $handler->display->display_options['fields']['field_event_nid']['label'] = 'Event';
  $handler->display->display_options['fields']['field_event_nid']['settings'] = array(
    'link' => 1,
  );
  /* Field: Field collection item: Points */
  $handler->display->display_options['fields']['field_points']['id'] = 'field_points';
  $handler->display->display_options['fields']['field_points']['table'] = 'field_data_field_points';
  $handler->display->display_options['fields']['field_points']['field'] = 'field_points';
  $handler->display->display_options['fields']['field_points']['relationship'] = 'field_events_value';
  $handler->display->display_options['fields']['field_points']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Contextual filter: User: Uid */
  $handler->display->display_options['arguments']['uid']['id'] = 'uid';
  $handler->display->display_options['arguments']['uid']['table'] = 'users';
  $handler->display->display_options['arguments']['uid']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'user';
  $handler->display->display_options['arguments']['uid']['default_argument_options']['user'] = FALSE;
  $handler->display->display_options['arguments']['uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['uid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['uid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['uid']['validate']['type'] = 'user';
  $handler->display->display_options['arguments']['uid']['validate_options']['type'] = 'either';
  /* Contextual filter: Field: Term (field_term) */
  $handler->display->display_options['arguments']['field_term_tid']['id'] = 'field_term_tid';
  $handler->display->display_options['arguments']['field_term_tid']['table'] = 'field_data_field_term';
  $handler->display->display_options['arguments']['field_term_tid']['field'] = 'field_term_tid';
  $handler->display->display_options['arguments']['field_term_tid']['relationship'] = 'field_active_quarter_value';
  $handler->display->display_options['arguments']['field_term_tid']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['field_term_tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_term_tid']['default_argument_options']['argument'] = '8';
  $handler->display->display_options['arguments']['field_term_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_term_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_term_tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_term_tid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['field_term_tid']['validate']['type'] = 'numeric';
  $handler->display->display_options['arguments']['field_term_tid']['validate']['fail'] = 'ignore';
  /* Filter criterion: User: Active */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page_1');
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Unfiltered text */
  $handler->display->display_options['header']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['header']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['header']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['header']['area_text_custom']['empty'] = TRUE;
  $handler->display->display_options['header']['area_text_custom']['content'] = '<h1>Quarter:[field_term] </h1>';
  $handler->display->display_options['header']['area_text_custom']['tokenize'] = TRUE;
  $handler->display->display_options['defaults']['footer'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: User: Uid */
  $handler->display->display_options['arguments']['uid']['id'] = 'uid';
  $handler->display->display_options['arguments']['uid']['table'] = 'users';
  $handler->display->display_options['arguments']['uid']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'current_user';
  $handler->display->display_options['arguments']['uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['uid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['uid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['uid']['validate']['type'] = 'user';
  $handler->display->display_options['arguments']['uid']['validate_options']['type'] = 'either';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: User: Active */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Field: Term (field_term) */
  $handler->display->display_options['filters']['field_term_tid']['id'] = 'field_term_tid';
  $handler->display->display_options['filters']['field_term_tid']['table'] = 'field_data_field_term';
  $handler->display->display_options['filters']['field_term_tid']['field'] = 'field_term_tid';
  $handler->display->display_options['filters']['field_term_tid']['relationship'] = 'field_active_quarter_value';
  $handler->display->display_options['filters']['field_term_tid']['value'] = array(
    7 => '7',
  );
  $handler->display->display_options['filters']['field_term_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_term_tid']['expose']['operator_id'] = 'field_term_tid_op';
  $handler->display->display_options['filters']['field_term_tid']['expose']['label'] = 'Term';
  $handler->display->display_options['filters']['field_term_tid']['expose']['operator'] = 'field_term_tid_op';
  $handler->display->display_options['filters']['field_term_tid']['expose']['identifier'] = 'field_term_tid';
  $handler->display->display_options['filters']['field_term_tid']['expose']['required'] = TRUE;
  $handler->display->display_options['filters']['field_term_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['field_term_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_term_tid']['vocabulary'] = 'quarter';
  $handler->display->display_options['filters']['field_term_tid']['hierarchy'] = 1;
  $handler->display->display_options['path'] = 'active-membership';

  /* Display: Attachment */
  $handler = $view->new_display('attachment', 'Attachment', 'attachment_1');
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['defaults']['header'] = FALSE;
  $handler->display->display_options['defaults']['footer'] = FALSE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: User: Active Quarter (field_active_quarter) */
  $handler->display->display_options['relationships']['field_active_quarter_value']['id'] = 'field_active_quarter_value';
  $handler->display->display_options['relationships']['field_active_quarter_value']['table'] = 'field_data_field_active_quarter';
  $handler->display->display_options['relationships']['field_active_quarter_value']['field'] = 'field_active_quarter_value';
  $handler->display->display_options['relationships']['field_active_quarter_value']['required'] = TRUE;
  $handler->display->display_options['relationships']['field_active_quarter_value']['delta'] = '-1';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Field collection item: Active Member */
  $handler->display->display_options['fields']['field_active_member']['id'] = 'field_active_member';
  $handler->display->display_options['fields']['field_active_member']['table'] = 'field_data_field_active_member';
  $handler->display->display_options['fields']['field_active_member']['field'] = 'field_active_member';
  $handler->display->display_options['fields']['field_active_member']['relationship'] = 'field_active_quarter_value';
  /* Field: Field: Term */
  $handler->display->display_options['fields']['field_term']['id'] = 'field_term';
  $handler->display->display_options['fields']['field_term']['table'] = 'field_data_field_term';
  $handler->display->display_options['fields']['field_term']['field'] = 'field_term';
  $handler->display->display_options['fields']['field_term']['relationship'] = 'field_active_quarter_value';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: User: Uid */
  $handler->display->display_options['arguments']['uid']['id'] = 'uid';
  $handler->display->display_options['arguments']['uid']['table'] = 'users';
  $handler->display->display_options['arguments']['uid']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'current_user';
  $handler->display->display_options['arguments']['uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['uid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['uid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['uid']['validate']['type'] = 'user';
  $handler->display->display_options['arguments']['uid']['validate_options']['type'] = 'either';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: User: Active */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Field: Term (field_term) */
  $handler->display->display_options['filters']['field_term_tid']['id'] = 'field_term_tid';
  $handler->display->display_options['filters']['field_term_tid']['table'] = 'field_data_field_term';
  $handler->display->display_options['filters']['field_term_tid']['field'] = 'field_term_tid';
  $handler->display->display_options['filters']['field_term_tid']['relationship'] = 'field_active_quarter_value';
  $handler->display->display_options['filters']['field_term_tid']['value'] = array(
    6 => '6',
  );
  $handler->display->display_options['filters']['field_term_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_term_tid']['expose']['operator_id'] = 'field_term_tid_op';
  $handler->display->display_options['filters']['field_term_tid']['expose']['label'] = 'Term (field_term)';
  $handler->display->display_options['filters']['field_term_tid']['expose']['operator'] = 'field_term_tid_op';
  $handler->display->display_options['filters']['field_term_tid']['expose']['identifier'] = 'field_term_tid';
  $handler->display->display_options['filters']['field_term_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['field_term_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_term_tid']['vocabulary'] = 'quarter';
  $handler->display->display_options['displays'] = array(
    'page_1' => 'page_1',
    'default' => 0,
  );
  $handler->display->display_options['inherit_arguments'] = FALSE;
  $handler->display->display_options['inherit_exposed_filters'] = TRUE;

  /* Display: Master Attachment */
  $handler = $view->new_display('attachment', 'Master Attachment', 'attachment_2');
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  $handler->display->display_options['defaults']['footer'] = FALSE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: User: Active Quarter (field_active_quarter) */
  $handler->display->display_options['relationships']['field_active_quarter_value']['id'] = 'field_active_quarter_value';
  $handler->display->display_options['relationships']['field_active_quarter_value']['table'] = 'field_data_field_active_quarter';
  $handler->display->display_options['relationships']['field_active_quarter_value']['field'] = 'field_active_quarter_value';
  $handler->display->display_options['relationships']['field_active_quarter_value']['required'] = TRUE;
  $handler->display->display_options['relationships']['field_active_quarter_value']['delta'] = '-1';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Field collection item: Active Member */
  $handler->display->display_options['fields']['field_active_member']['id'] = 'field_active_member';
  $handler->display->display_options['fields']['field_active_member']['table'] = 'field_data_field_active_member';
  $handler->display->display_options['fields']['field_active_member']['field'] = 'field_active_member';
  $handler->display->display_options['fields']['field_active_member']['relationship'] = 'field_active_quarter_value';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: User: Uid */
  $handler->display->display_options['arguments']['uid']['id'] = 'uid';
  $handler->display->display_options['arguments']['uid']['table'] = 'users';
  $handler->display->display_options['arguments']['uid']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'current_user';
  $handler->display->display_options['arguments']['uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['uid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['uid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['uid']['validate']['type'] = 'user';
  $handler->display->display_options['arguments']['uid']['validate_options']['type'] = 'either';
  /* Contextual filter: Field: Term (field_term) */
  $handler->display->display_options['arguments']['field_term_tid']['id'] = 'field_term_tid';
  $handler->display->display_options['arguments']['field_term_tid']['table'] = 'field_data_field_term';
  $handler->display->display_options['arguments']['field_term_tid']['field'] = 'field_term_tid';
  $handler->display->display_options['arguments']['field_term_tid']['relationship'] = 'field_active_quarter_value';
  $handler->display->display_options['arguments']['field_term_tid']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['field_term_tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_term_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_term_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_term_tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: User: Active */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  $handler->display->display_options['displays'] = array(
    'default' => 'default',
    'page_1' => 0,
  );
  $handler->display->display_options['inherit_exposed_filters'] = TRUE;
  $export['active_quarter'] = $view;

  $view = new view();
  $view->name = 'all_active_members';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'users';
  $view->human_name = 'All Active Members';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'All Active Members';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'access user profiles';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: User: Active Quarter (field_active_quarter) */
  $handler->display->display_options['relationships']['field_active_quarter_value']['id'] = 'field_active_quarter_value';
  $handler->display->display_options['relationships']['field_active_quarter_value']['table'] = 'field_data_field_active_quarter';
  $handler->display->display_options['relationships']['field_active_quarter_value']['field'] = 'field_active_quarter_value';
  $handler->display->display_options['relationships']['field_active_quarter_value']['required'] = TRUE;
  $handler->display->display_options['relationships']['field_active_quarter_value']['delta'] = '-1';
  /* Relationship: Field: Term (field_term) */
  $handler->display->display_options['relationships']['field_term_tid']['id'] = 'field_term_tid';
  $handler->display->display_options['relationships']['field_term_tid']['table'] = 'field_data_field_term';
  $handler->display->display_options['relationships']['field_term_tid']['field'] = 'field_term_tid';
  $handler->display->display_options['relationships']['field_term_tid']['relationship'] = 'field_active_quarter_value';
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  /* Field: Field: Term */
  $handler->display->display_options['fields']['field_term']['id'] = 'field_term';
  $handler->display->display_options['fields']['field_term']['table'] = 'field_data_field_term';
  $handler->display->display_options['fields']['field_term']['field'] = 'field_term';
  $handler->display->display_options['fields']['field_term']['relationship'] = 'field_active_quarter_value';
  $handler->display->display_options['fields']['field_term']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Field collection item: Active Member */
  $handler->display->display_options['fields']['field_active_member']['id'] = 'field_active_member';
  $handler->display->display_options['fields']['field_active_member']['table'] = 'field_data_field_active_member';
  $handler->display->display_options['fields']['field_active_member']['field'] = 'field_active_member';
  $handler->display->display_options['fields']['field_active_member']['relationship'] = 'field_active_quarter_value';
  $handler->display->display_options['fields']['field_active_member']['label'] = '';
  $handler->display->display_options['fields']['field_active_member']['alter']['text'] = 'Yes';
  $handler->display->display_options['fields']['field_active_member']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_active_member']['empty'] = 'No';
  $handler->display->display_options['fields']['field_active_member']['empty_zero'] = TRUE;
  $handler->display->display_options['fields']['field_active_member']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_active_member']['type'] = 'list_key';
  /* Sort criterion: Taxonomy term: Date Term -  start date (field_date_term) */
  $handler->display->display_options['sorts']['field_date_term_value']['id'] = 'field_date_term_value';
  $handler->display->display_options['sorts']['field_date_term_value']['table'] = 'field_data_field_date_term';
  $handler->display->display_options['sorts']['field_date_term_value']['field'] = 'field_date_term_value';
  $handler->display->display_options['sorts']['field_date_term_value']['relationship'] = 'field_term_tid';
  $handler->display->display_options['sorts']['field_date_term_value']['order'] = 'DESC';
  /* Filter criterion: User: Active */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Field: Term (field_term) */
  $handler->display->display_options['filters']['field_term_tid']['id'] = 'field_term_tid';
  $handler->display->display_options['filters']['field_term_tid']['table'] = 'field_data_field_term';
  $handler->display->display_options['filters']['field_term_tid']['field'] = 'field_term_tid';
  $handler->display->display_options['filters']['field_term_tid']['relationship'] = 'field_active_quarter_value';
  $handler->display->display_options['filters']['field_term_tid']['value'] = '';
  $handler->display->display_options['filters']['field_term_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_term_tid']['expose']['operator_id'] = 'field_term_tid_op';
  $handler->display->display_options['filters']['field_term_tid']['expose']['label'] = 'Term ';
  $handler->display->display_options['filters']['field_term_tid']['expose']['operator'] = 'field_term_tid_op';
  $handler->display->display_options['filters']['field_term_tid']['expose']['identifier'] = 'field_term_tid';
  $handler->display->display_options['filters']['field_term_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['field_term_tid']['vocabulary'] = 'quarter';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'all-active-members';
  $export['all_active_members'] = $view;

  return $export;
}
