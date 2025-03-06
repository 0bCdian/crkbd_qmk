/*
This is the c configuration file for the keymap

Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#define USE_MATRIX_I2C
#define PERMISSIVE_HOLD_PER_KEY
#define TAPPING_TERM 180
#define QUICK_TAP_TERM 50
#define SPLIT_WPM_ENABLE
#define OLED_TIMEOUT 50000
#define OLED_BRIGHTNESS 80
#define TAPPING_TERM_PER_KEY
#define BOTH_SHIFTS_TURNS_ON_CAPS_WORD
// Holding Shift while Caps Word is active inverts the shift state.
#define CAPS_WORD_INVERT_ON_SHIFT
#ifdef RGBLIGHT_ENABLE
    #undef  RGBLIGHT_EFFECT_BREATHING
    #undef  RGBLIGHT_EFFECT_RAINBOW_MOOD
    #define  RGBLIGHT_EFFECT_RAINBOW_SWIRL
    #undef  RGBLIGHT_EFFECT_SNAKE
    #undef  RGBLIGHT_EFFECT_KNIGHT
    #undef  RGBLIGHT_EFFECT_CHRISTMAS
    #undef  RGBLIGHT_EFFECT_STATIC_GRADIENT
    #undef  RGBLIGHT_EFFECT_RGB_TEST
    #undef  RGBLIGHT_EFFECT_ALTERNATING
    #undef  RGBLIGHT_EFFECT_TWINKLE
    #define RGBLIGHT_LIMIT_VAL 120
    #define RGBLIGHT_HUE_STEP 10
    #define RGBLIGHT_SPLIT
    #define RGBLIGHT_SLEEP
    #define RGBLIGHT_SAT_STEP 17
    #define RGBLIGHT_VAL_STEP 17
    #define RGBLIGHT_DEFAULT_HUE 0
    #define RGBLIGHT_DEFAULT_SAT 0
    #define RGBLIGHT_DEFAULT_VAL 255
#endif

#if defined(OLED_ENABLE)
#   define SPLIT_LAYER_STATE_ENABLE
#   define SPLIT_LED_STATE_ENABLE
#   define SPLIT_MODS_ENABLE
#   define SPLIT_OLED_ENABLE
#    undef OLED_TIMEOUT
#   define OLED_KEY_TIMEOUT 30000
#   define KEY_LOG_ENABLE
#endif

/*#ifdef RGB_MATRIX_ENABLE*/
/*#    define RGB_MATRIX_KEYPRESSES               // reacts to keypresses*/
/*#    define RGB_DISABLE_WHEN_USB_SUSPENDED      // turn off effects when suspended*/
/*#    define RGB_MATRIX_TIMEOUT 60000      // turn off effects when suspended*/
/*#    define RGB_MATRIX_HUE_STEP 32*/
/*#    define RGB_MATRIX_SAT_STEP 64*/
/*#    define RGB_MATRIX_VAL_STEP 64*/
/*#    define RGB_MATRIX_SPD_STEP 20*/
/*#    define ENABLE_RGB_MATRIX_SPLASH*/
/*#endif*/
