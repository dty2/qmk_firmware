#include "color.h"

RGB_MATRIX_EFFECT(lucky)

#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS
void finger_color() {
    HSV hsv = HSV_PURPLE;
    hsv.v = rgb_matrix_config.val;
    RGB rgb = hsv_to_rgb(hsv);

    uint16_t finger_table[10] = {
        // left
        KC_A,
        KC_S,
        KC_D,
        KC_F,
        LT(2, KC_TAB),
        // right
        KC_H,
        KC_J,
        KC_K,
        KC_L,
        KC_SPC
    };

    for (int i = 0; i < 10; i++) {
        rgb_matrix_set_color(finger_table[i], rgb.r, rgb.g, rbg.b);
    }
}

bool lucky(effect_params_t* params) {
    HSV hsv;
    RGB rgb;
    switch (get_highest_layer(layer_state)) {
        case 0:
            hsv = HSV_AZURE;                // 天蓝色调，清澈而优雅，略带青绿色感
            break;
        case 1: hsv = HSV_CORAL; break;         // 粉橘色调，柔和而不张扬
        case 2: hsv = HSV_GOLDENROD; break;     // 暖黄色调，有秋天感
        case 3: hsv = HSV_TURQUOISE; break;     // 蓝绿宝石色，科技感十足
        case 4: hsv = HSV_MAGENTA; break;       // 品红色，梦幻而炫目
        case 5: hsv = HSV_SPRINGGREEN; break;   // 春绿色，清新明快
        case 6: hsv = HSV_TEAL; break;          // 青色，沉稳又耐看
        case 7: hsv = HSV_CHARTREUSE; break;    // 荧光黄绿，很有未来感
        default: hsv = HSV_WHITE; break;        // 默认纯白，适配任意主题
    }

    hsv.v = rgb_matrix_config.val;
    rgb = hsv_to_rgb(hsv);
    rgb_matrix_set_color_all(rgb.r, rgb.g, rgb.b);

    if (get_highest_layer(layer_state) == 0) {
        finger_color();
    }

    return false;
}

#endif
