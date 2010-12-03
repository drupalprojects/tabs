<?php
// $Id$

/**
 * @file
 * Theme functions for tabs.
 */

/**
 * Return rendered tabset.
 *
 * @themable
 */
function theme_tabset($variables) {
  $element = $variables['element'];
  $output = '<div id="tabs-'. $element['#tabset_name'] .'"'. drupal_attributes($element['#attributes']) .'>';
  if (isset($element['#description'])) {
    $output .= '<div class="description">' . $element['#description'] . '</div>';
  }
  $output .= '<ul class="clear-block">';
  $output .= drupal_render_children($element);
  $output .= '</ul></div>';
  return $output;
  foreach (element_children($element) as $key) {
    $child = &$element[$key];

    if (isset($child['#type']) && $child['#type'] == 'tabpage') {
      // Ensure the tab has content before rendering it.
      if (
        (isset($child['#ajax_url']) && !empty($child['#ajax_url'])) ||
        (isset($child['#content']) && !empty($child['#content'])) ||
        (isset($child['#children']) && !empty($child['#children']))
      ) {
        $output .= '<li'. drupal_attributes($child['#attributes']) .'><a href="' . $child['#url'] . '"><span class="tab">'. $child['#title'] .'</span></a></li>';
      }
    }
  }
  $output .= '</ul>';
  if (isset($element['#children'])) {
    $output .= $element['#children'];
  }
  $output .= '</div>';
  return $output;
}

/**
 * Return rendered content of a tab.
 *
 * @themable
 */
function theme_tabpage($variables) {
  $element = $variables['element'];
  $output = '';
  // Ensure the tab has content before rendering it.
  if (!empty($element['#ajax_url']) || !empty($element['#content']) || !empty($element['#children'])) {
    $output .= '<div id="' . $element['#tab_name'] . '" class="tabs-' . $element['#tabset_name'] . '">';
    $output .= '<h2 class="drupal-tabs-title js-hide">'. $element['#title'] .'</h2>';
    $output .= $element['#content'] . (!empty($element['#children']) ? $element['#children'] : '');
    $output .='</div>';
  }
  return $output;
}
