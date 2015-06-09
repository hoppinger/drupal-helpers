<?php

/**
 * Build array for fields.
 */
function _hoppinger_fields_build_array($input, $mapping) {
  $result = array();

  foreach ($mapping as $key => $parents) {
    drupal_array_set_nested_value($result, $parents, $input[$key]);
  }

  return $result;
}

/**
 * Field settings.
 */
function hoppinger_fields_field($settings) {
  return _hoppinger_fields_build_array($settings + array(
    'cardinality' => 1,
    'entity_types' => array(),
  ), array(
    'field_type' => array('type'),
    'field_name' => array('field_name'),
    'cardinality' => array('cardinality'),
    'entity_types' => array('entity_types'),
  ));
}

/**
 * Instance settings.
 */
function hoppinger_fields_instance($settings) {
  return _hoppinger_fields_build_array($settings + array(
    'description' => '',
    'required' => FALSE,
    'weight' => 0,
  ), array(
    'field_name' => array('field_name'),
    'entity_type' => array('entity_type'),
    'bundle' => array('bundle'),
    'label' => array('label'),
    'description' => array('description'),
    'required' => array('required'),
  ));
}

/**
 * List all view modes with custom settings
 */
function hoppinger_fields_view_modes($entity_type) {
  $info = entity_get_info($entity_type);

  $modes = array('default');
  foreach ($info['view modes'] as $key => $mode_info) {
    if (!empty($mode_info['custom settings'])) {
      $modes[] = $key;
    }
  }

  return $modes;
}

