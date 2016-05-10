<?php
/**
 * @file
 * Page functions for user group info.
 */

/**
 * Generate the group info page for a given user.
 *
 * @param object $account
 *   The user to display data for.
 *
 * @return array
 *   The render array for this page.
 */
function group_user_page($account) {
  // Create the group overview table.
  $page['groups'] = array(
    '#theme' => 'table',
    '#header' => array(
      'group' => t('Group name'),
      'roles' => t('Roles'),
      'operations' => t('Operations'),
    ),
    '#rows' => array(),
    '#empty' => t('You are not a member of any group.'),
  );

  // Retrieve all active memberships.
  if ($memberships = GroupMembership::getByActiveStatus($account->uid)) {
    // Link the rows variable to the table element's rows.
    $rows = &$page['groups']['#rows'];

    foreach ($memberships as $group_membership) {
      $wrapper = entity_metadata_wrapper('group_membership', $group_membership);

      // Extract the membership roles.
      $group_roles = array();
      foreach ($wrapper->roles->getIterator() as $group_role_wrapper) {
        $group_roles[] = $group_role_wrapper->label();
      }

      // Populate the group operations.
      $operations['view group'] = array(
        'title' => t('Edit Group'),
        'href' => "group/$group_membership->gid/edit",
      );
      $operations['group members'] = array(
        'title' => t('Manage Members'),
        'href' => "group/$group_membership->gid/member",
      );
      $operations['group content'] = array(
        'title' => t('View Content'),
        'href' => "group/$group_membership->gid/content",
      );
      $operations['group menu'] = array(
        'title' => t('Manage Menu'),
        'href' => "group/$group_membership->gid/menus",
      );

      $rows[] = array(
        'group' => $wrapper->group->label(),
        'roles' => array(
          'data' => array(
            '#theme' => 'item_list__group_roles',
            '#items' => $group_roles,
          ),
        ),
        'operations' => array(
          'data' => array(
            '#theme' => 'links__group_operation_links',
            '#links' => $operations,
            '#attributes' => array('class' => array('links', 'inline')),
          ),
        ),
      );
    }
  }

  return $page;
}
