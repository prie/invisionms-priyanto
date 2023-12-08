<?php

function site_info_json() {
    $data = [
        'site_name' => variable_get('site_name'),
        'slogan' => variable_get('site_slogan'),
        'email_address' => variable_get('site_mail'),
    ];

    return drupal_json_output($data);
}