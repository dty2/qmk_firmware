#include "color.h"

RGB_MATRIX_EFFECT(lucky)
#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS
bool lucky(effect_params_t* params) {
    HSV hsv;
    RGB rgb;
    switch (get_highest_layer(layer_state)) {
        case 0: hsv = (HSV){HSV_CORAL}; break;         // 天蓝色调，清澈而优雅，略带青绿色感
        case 1: hsv = (HSV){HSV_AZURE}; break;         // 粉橘色调，柔和而不张扬
        case 2: hsv = (HSV){HSV_GOLDENROD}; break;     // 暖黄色调，有秋天感
        case 3: hsv = (HSV){HSV_TURQUOISE}; break;     // 蓝绿宝石色，科技感十足
        case 4: hsv = (HSV){HSV_MAGENTA}; break;       // 品红色，梦幻而炫目
        case 5: hsv = (HSV){HSV_SPRINGGREEN}; break;   // 春绿色，清新明快
        case 6: hsv = (HSV){HSV_TEAL}; break;          // 青色，沉稳又耐看
        case 7: hsv = (HSV){HSV_CHARTREUSE}; break;    // 荧光黄绿，很有未来感
        default: hsv = (HSV){HSV_WHITE}; break;        // 默认纯白，适配任意主题
    }

    hsv.v = rgb_matrix_config.hsv.v;
    rgb = hsv_to_rgb(hsv);
    rgb_matrix_set_color_all(rgb.r, rgb.g, rgb.b);

    return false;
}

#endif
