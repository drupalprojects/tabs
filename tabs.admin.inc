<?php

/**
 * @file
 * Administrative page for tabs.
 */

/**
 * Menu callback for admin settings.
 */
function tabs_admin_settings() {
  $form = array();
  $form['effects'] = array(
    '#type' => 'fieldset',
    '#title' => t('Effects'),
  );
  $form['effects']['tabs_slide'] = array(
    '#type' => 'checkbox',
    '#title' => t('Slide effect'),
    '#description' => t('Apply slide effect when changing tabs.'),
    '#default_value' => variable_get('tabs_slide', 0),
  );
  $form['effects']['tabs_fade'] = array(
    '#type' => 'checkbox',
    '#title' => t('Fade effect'),
    '#description' => t('Apply fade effect when changing tabs.'),
    '#default_value' => variable_get('tabs_fade', 0),
  );
  $form['effects']['tabs_speed'] = array(
    '#type' => 'radios',
    '#title' => t('Effect speed'),
    '#description' => t('Speed at which to apply effects.'),
    '#default_value' => variable_get('tabs_speed', 'fast'),
    '#options' => array('slow' => t('slow'), 'fast' => t('fast'), '1' => t('immediate')),
  );
  $form['navigation'] = array(
    '#type' => 'fieldset',
    '#title' => t('Navigation'),
  );
  $form['navigation']['tabs_navigation'] = array(
    '#type' => 'checkbox',
    '#title' => t('Navigation buttons'),
    '#description' => t('Enable to add "next" and "previous" buttons to the bottom of all tab sets.'),
    '#default_value' => variable_get('tabs_navigation', 0),
  );
  $form['navigation']['tabs_nav_next'] = array(
    '#type' => 'textfield',
    '#title' => t('Next button caption'),
    '#description' => t('The text to be displayed in the \'next\' button.'),
    '#default_value' => variable_get('tabs_nav_next', t('next')),
  );
  $form['navigation']['tabs_nav_prev'] = array(
    '#type' => 'textfield',
    '#title' => t('Previous button caption'),
    '#description' => t('The text to be displayed in the \'previous\' button.'),
    '#default_value' => variable_get('tabs_nav_prev', t('previous')),
  );
  $form['navigation']['tabs_navigation_titles'] = array(
    '#type' => 'checkbox',
    '#title' => t('Take captions from tab titles'),
    '#description' => t('Enable to use tht titles of the next or previous tabs for "next" and "previous" button captions. If this option is enabled, the next and previous captions above will be ignored.'),
    '#default_value' => variable_get('tabs_navigation_titles', 0),
  );
  $form['tabs_descriptive_urls'] = array(
    '#type' => 'checkbox',
    '#title' => t('Descriptive tab URLs'),
    '#description' => t('Construct a descriptive tab URL from the title of the tab. This can be useful for making URLs of tabs more readable. However, special characters in tab titles are stripped when constructing the URL, which can lead to meaningless URLs on sites using many special characters.'),
    '#default_value' => variable_get('tabs_descriptive_urls', 0),
  );
  return system_settings_form($form);
}
