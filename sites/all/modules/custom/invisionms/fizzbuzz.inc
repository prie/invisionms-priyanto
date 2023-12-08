<?php

/**
 * Form builder function
 */
function fizzbuzz_input($form, &$form_state) {

    $form['number'] = array(
      '#type' => 'fieldset',
      '#title' => t('Number'),
    );

    $form['number']['fizz_min'] = array(
      '#type' => 'textfield',
      '#title' => t('Min'),
      '#description' => t('Minimum number.'),
      '#required' => TRUE,
      '#size' => 10,
      '#maxlength' => 5,
      '#default_value' => variable_get('fizz_min', ''),
    );

    $form['number']['fizz_max'] = array(
      '#type' => 'textfield',
      '#title' => t('Max'),
      '#description' => t('Maximum number.'),
      '#required' => TRUE,
      '#size' => 10,
      '#maxlength' => 5,
      '#default_value' => variable_get('fizz_max', ''),
    );

    $form['submit'] = array(
      '#type' => 'submit',
      '#value' => t('Submit')
    );

    return $form;
}

/**
 * Form validation
 */
function fizzbuzz_input_validate($form, &$form_state) {
    if (!is_numeric($form_state['values']['fizz_min'])) {
        form_set_error('fizz_min', 'Min value was not numeric!');
    }
    if (!is_numeric($form_state['values']['fizz_max'])) {
        form_set_error('fizz_max', 'Max value was not numeric!');
    }
    if (is_numeric($form_state['values']['fizz_min']) and is_numeric($form_state['values']['fizz_max'])) {
        if ($form_state['values']['fizz_min'] >= $form_state['values']['fizz_max']) {
            form_set_error('fizz_max', 'Max value should be greater!');
        }
    }
}

/**
 * Form validation
 */
function fizzbuzz_input_submit($form, &$form_state) {
    $fizz_min = $form_state['values']['fizz_min'];
    $fizz_max = $form_state['values']['fizz_max'];

    variable_set('fizz_min', $fizz_min);
    variable_set('fizz_max', $fizz_max);
    
    $range_number = '';
    for ($i = $fizz_min; $i <= $fizz_max; $i++) {
        $fizzbuzzed = fizzBuzz($i);
        $range_number = $i == $fizz_min ? $range_number = $fizzbuzzed : $range_number . ', ' . $fizzbuzzed;
    }
    
    drupal_set_message($range_number, 'error');
}

/**
 * FizzBuzz function
 */
function fizzBuzz($number) {
    if ($number % 3 == 0 && $number % 5 == 0) {
        $value = "FizzBuzz";
    } elseif ($number % 3 == 0) {
        $value = "Fizz";
    } elseif ($number % 5 == 0) {
        $value = "Buzz";
    } else {
        $value = (string)$number;
    }

    return $value;
}