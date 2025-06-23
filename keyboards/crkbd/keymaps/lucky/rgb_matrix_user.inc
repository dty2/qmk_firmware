RGB_MATRIX_EFFECT(lucky)

#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

bool lucky(effect_params_t* params) {
    uint8_t r, g, b;

    switch (get_highest_layer(layer_state)) {
        case 0: r = 100; g = 149; b = 237; break;  // cornflower blue
        case 1: r = 123; g = 201; b = 111; break;  // light green
        case 2: r = 186; g = 85;  b = 211; break;  // medium orchid (purple)
        case 3: r = 255; g = 140; b = 0;   break;  // dark orange
        case 4: r = 72;  g = 209; b = 204; break;  // medium turquoise (cyan)
        case 5: r = 255; g = 105; b = 180; break;  // hot pink
        case 6: r = 255; g = 223; b = 100; break;  // goldenrod (yellow)
        case 7: r = 220; g = 20;  b = 60;  break;  // crimson red
        default: r = 211; g = 211; b = 211; break; // light gray
    }

    rgb_matrix_set_color_all(r, g, b);
    return false;
}

#endif
