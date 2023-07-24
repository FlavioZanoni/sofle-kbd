 /* Copyright 2021 Dane Evans
  *
  * This program is free software: you can redistribute it and/or modify
  * it under the terms of the GNU General Public License as published by
  * the Free Software Foundation, either version 2 of the License, or
  * (at your option) any later version.
  *
  * This program is distributed in the hope that it will be useful,
  * but WITHOUT ANY WARRANTY; without even the implied warranty of
  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  * GNU General Public License for more details.
  *
  * You should have received a copy of the GNU General Public License
  * along with this program.  If not, see <http://www.gnu.org/licenses/>.
  */
  // SOFLE RGB
#include <stdio.h>
#include "action_util.h"
#include "keycodes.h"
#include "keymap_us.h"
#include "modifiers.h"
#include "quantum.h"

#include QMK_KEYBOARD_H

#define INDICATOR_BRIGHTNESS 30

#define HSV_OVERRIDE_HELP(h, s, v, Override) h, s , Override
#define HSV_OVERRIDE(hsv, Override) HSV_OVERRIDE_HELP(hsv,Override)

// Light combinations
#define SET_INDICATORS(hsv) \
	{0, 1, HSV_OVERRIDE_HELP(hsv, INDICATOR_BRIGHTNESS)}, \
    {35+0, 1, hsv}
#define SET_UNDERGLOW(hsv) \
	{1, 6, hsv}, \
    {35+1, 6,hsv}
#define SET_NUMPAD(hsv)     \
	{35+15, 5, hsv},\
	  {35+22, 3, hsv},\
	  {35+27, 3, hsv}
#define SET_NUMROW(hsv) \
	{10, 2, hsv}, \
		{20, 2, hsv}, \
		{30, 2, hsv}, \
	  {35+ 10, 2, hsv}, \
	  {35+ 20, 2, hsv}, \
	  {35+ 30, 2, hsv}
#define SET_INNER_COL(hsv)	\
	{33, 4, hsv}, \
	  {35+ 33, 4, hsv}

#define SET_OUTER_COL(hsv) \
	{7, 4, hsv}, \
	  {35+ 7, 4, hsv}
#define SET_THUMB_CLUSTER(hsv) 	\
	{25, 2, hsv}, \
	  {35+ 25, 2, hsv}
#define SET_LAYER_ID(hsv) 	\
	{0, 1, HSV_OVERRIDE_HELP(hsv, INDICATOR_BRIGHTNESS)}, \
    {35+0, 1, HSV_OVERRIDE_HELP(hsv, INDICATOR_BRIGHTNESS)}, \
		{1, 6, hsv}, \
    {35+1, 6, hsv}, \
		{7, 4, hsv}, \
	  {35+ 7, 4, hsv}, \
		{25, 2, hsv}, \
	  {35+ 25, 2, hsv}


enum sofle_layers {
    _DEFAULTS = 0,
    _QWERTY = 0,
    _02,
    _01,
    _ADJUST,
};

enum custom_keycodes {
    KC_QWERTY = SAFE_RANGE,
    KC_02,
    KC_01
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
   [_QWERTY] =  LAYOUT(KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_DEL, KC_ESC, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC, KC_LSFT, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_TAB, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_MUTE, RGB_MOD, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, KC_LGUI, KC_LALT, MO(1), KC_LCTL, KC_SPC, KC_ENT, KC_RCTL, TO(1), KC_RALT, KC_RGUI),

  [_02] = LAYOUT(KC_GRV, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F6, KC_F8, KC_F10, KC_F11, KC_F12, KC_ESC, KC_ASTR, KC_PIPE, KC_QUES, KC_MINS, KC_DLR, KC_LPRN, KC_RPRN, KC_PERC, KC_AMPR, KC_HASH, KC_BSPC, KC_LSFT, KC_LBRC, KC_RBRC, KC_LCBR, KC_RCBR, KC_EXLM, KC_EQL, KC_LEFT, KC_UP, KC_DOWN, KC_RGHT, KC_QUOT, KC_TAB, KC_HOME, KC_PGUP, KC_PGDN, KC_END, KC_PSCR, KC_MUTE, RGB_RMOD, KC_LT, KC_GT, KC_SCLN, KC_COLN, KC_SLSH, KC_RSFT, KC_LGUI, KC_LALT, TO(0), KC_LCTL, KC_SPC, KC_ENT, KC_RCTL, TO(0), KC_RALT, KC_RGUI),

  [_01] = LAYOUT(KC_TRNS, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_F12, KC_TRNS, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_LEFT, KC_UP, KC_DOWN, KC_RGHT, KC_NO, KC_TRNS, KC_EQL, KC_MINS, KC_PLUS, KC_LCBR, KC_RCBR, KC_TRNS, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_TRNS, TO(0), KC_TRNS, KC_TRNS, KC_TRNS, KC_NO, TO(1), KC_NO, KC_NO),
};

#ifdef RGBLIGHT_ENABLE
// This section define RGB_Lighting overrides by layers

const rgblight_segment_t PROGMEM rgb_layer_1[] = RGBLIGHT_LAYER_SEGMENTS(
    {30, 6, HSV_TURQUOISE},
    {38, 6, HSV_TURQUOISE}
);
const rgblight_segment_t PROGMEM rgb_layer_2[] = RGBLIGHT_LAYER_SEGMENTS(
    {30, 6, HSV_TEAL},
    {38, 6, HSV_TEAL}
);
const rgblight_segment_t PROGMEM rgb_layer_3[] = RGBLIGHT_LAYER_SEGMENTS(
    {38, 6, HSV_PURPLE}
);

const rgblight_segment_t* const PROGMEM rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    rgb_layer_1,     // Overrides for layer 1
    rgb_layer_2,     // Overrides for layer 2
    rgb_layer_3     // Overrides for layer 3
);

// Enable the LED layers
void keyboard_post_init_user(void) {
    rgblight_layers = rgb_layers;
}

// Set activation conditions for each LED layers
layer_state_t layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(0, layer_state_cmp(state, 1));
    rgblight_set_layer_state(1, layer_state_cmp(state, 2));
    rgblight_set_layer_state(2, layer_state_cmp(state, 3));
    return state;
}

#endif

#ifdef OLED_ENABLE

static void render_logo(void) {
    static const char PROGMEM right_logo[] = {
// 'bocc', 32x128px
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x1f, 0xff, 0xff, 0xfc, 0x0f, 0xff, 0xff, 0xfc, 0x0f, 0xff, 
	0xff, 0xe3, 0xe7, 0xff, 0xff, 0xe3, 0xe7, 0xff, 0xff, 0x8e, 0xf9, 0xff, 0xff, 0x8e, 0xf9, 0xff, 
	0xff, 0x3f, 0x7c, 0xff, 0xff, 0x3f, 0x7c, 0xff, 0xff, 0x3f, 0x7e, 0xff, 0xff, 0x3f, 0x3f, 0xff, 
	0xff, 0x3f, 0x7f, 0xff, 0xc4, 0x7f, 0xdf, 0xbf, 0xc4, 0x7f, 0xdf, 0xbf, 0xd0, 0x7f, 0xff, 0xdf, 
	0xd0, 0x7f, 0xff, 0xdf, 0xb9, 0xff, 0xff, 0xdf, 0xb9, 0xff, 0xf5, 0xff, 0xb9, 0xff, 0xfd, 0xff, 
	0xb9, 0xff, 0xfc, 0xff, 0xbb, 0xff, 0xfc, 0xff, 0x9b, 0xff, 0xfc, 0x6f, 0x9b, 0xff, 0xfc, 0x6f, 
	0x83, 0xff, 0xfc, 0x3f, 0x83, 0xff, 0xfc, 0x3f, 0x87, 0xff, 0xfc, 0x3f, 0x87, 0xff, 0xfc, 0x3f, 
	0x87, 0xff, 0xfe, 0x17, 0xe7, 0xff, 0xfe, 0x17, 0x27, 0xff, 0xfe, 0x07, 0x07, 0xff, 0xfe, 0x07, 
	0x07, 0xff, 0xfe, 0x07, 0x0f, 0xf7, 0xfe, 0x47, 0x0f, 0xf7, 0xfe, 0x67, 0x0f, 0x77, 0xff, 0x63, 
	0x2f, 0x77, 0xff, 0x63, 0x4f, 0x7f, 0xff, 0x73, 0x6f, 0x7f, 0xff, 0xf3, 0x4f, 0x7f, 0xff, 0xf3, 
	0x0f, 0x7e, 0xff, 0xfb, 0x4f, 0x7e, 0xff, 0xfb, 0x47, 0x7e, 0xff, 0xfb, 0x46, 0x7e, 0xff, 0xfb, 
	0x46, 0x7e, 0xf8, 0xfb, 0x46, 0x7e, 0xf8, 0xfb, 0x44, 0x3e, 0x30, 0xfb, 0x40, 0x3c, 0x00, 0xfb, 
	0x00, 0x3c, 0x00, 0xbb, 0x00, 0x3c, 0x80, 0xbb, 0x00, 0x3c, 0x80, 0xbb, 0x00, 0x01, 0x80, 0x3b, 
	0x00, 0x01, 0x80, 0x7b, 0x00, 0x01, 0x80, 0x23, 0x80, 0x01, 0x80, 0x23, 0x80, 0x01, 0x80, 0x11, 
	0x80, 0x01, 0x80, 0x11, 0x80, 0x01, 0x80, 0x31, 0x80, 0x01, 0x80, 0x31, 0x80, 0x01, 0x80, 0x31, 
	0x80, 0xc3, 0x84, 0x31, 0x80, 0xc1, 0x84, 0x11, 0x80, 0x23, 0x80, 0x11, 0x80, 0x23, 0x80, 0x11, 
	0x81, 0x37, 0x80, 0x11, 0x81, 0x3f, 0x80, 0x31, 0x81, 0x3f, 0x80, 0x31, 0x81, 0x3f, 0xb0, 0x31, 
	0x81, 0x3f, 0xf0, 0x31, 0x81, 0x3f, 0xf8, 0x31, 0x81, 0x1f, 0xd8, 0x31, 0x81, 0x1f, 0xf8, 0x01, 
	0x80, 0x1f, 0xf8, 0x01, 0xc0, 0x1f, 0xf8, 0x01, 0xc0, 0x1f, 0xf8, 0x01, 0xc0, 0x1f, 0xf8, 0x01, 
	0xc0, 0xdf, 0xf8, 0x01, 0xc1, 0xff, 0xf8, 0x01, 0xc1, 0xff, 0xf8, 0x01, 0xc1, 0xff, 0xf8, 0x01, 
	0xc1, 0x7f, 0xf8, 0x01, 0xc1, 0x7f, 0xf8, 0x01, 0xc1, 0xff, 0xf8, 0x01, 0xc1, 0xff, 0xf8, 0x01, 
	0xc1, 0xff, 0xf8, 0x01, 0xc1, 0xff, 0xf8, 0x01, 0xc1, 0xff, 0xf8, 0x01, 0xc1, 0xff, 0xf8, 0x01, 
	0xc1, 0xff, 0xf8, 0x01, 0xc1, 0xfb, 0xf8, 0x01, 0xc1, 0xfb, 0xf8, 0x01, 0xc1, 0xff, 0xf8, 0x01, 
	0xc1, 0xff, 0xf8, 0x01, 0xc1, 0xff, 0xf8, 0x01, 0xc1, 0xff, 0xf8, 0x01, 0xc1, 0xff, 0xf8, 0x01, 
	0xc1, 0xff, 0xf8, 0x01, 0xc1, 0xff, 0xf8, 0x01, 0xc0, 0xff, 0xf8, 0x00, 0xc0, 0xff, 0xf8, 0x00, 
	0xc0, 0x3f, 0xf0, 0x00, 0xc0, 0x3f, 0xf0, 0x00, 0xc0, 0x1f, 0xf0, 0x00, 0xc0, 0x0f, 0xb8, 0x00, 
	0xc0, 0x0f, 0xb8, 0x00, 0xc0, 0x00, 0x78, 0x00, 0xc0, 0x00, 0x70, 0x00, 0xc0, 0x00, 0x70, 0x00, 
	0xc0, 0x00, 0x70, 0x00, 0xc0, 0x00, 0x60, 0x00, 0xc0, 0x00, 0x60, 0x00, 0xc0, 0x00, 0x60, 0x00, 
	0xc0, 0x00, 0x60, 0x00, 0xc0, 0x00, 0x40, 0x00, 0xc0, 0x30, 0x00, 0x00, 0xc0, 0x38, 0x00, 0x00
    };

    oled_write_P(right_logo, false);
}

static void print_status_narrow(void) {
    // Print current mode
    oled_write_P(PSTR("\n\n"), false);
    oled_write_ln_P(PSTR("galo\ngalo"), false);

    oled_write_ln_P(PSTR(""), false);

    oled_write_P(PSTR("\n\n"), false);
    // Print current layer
    oled_write_ln_P(PSTR("LAYER"), false);
    switch (get_highest_layer(layer_state)) {
        case _QWERTY:
            oled_write_P(PSTR("Base"), false);
            break;
        case _02:
            oled_write_P(PSTR("0002"), false);
            break;
        case _01:
            oled_write_P(PSTR("0001"), false);
            break;
        default:
            oled_write_ln_P(PSTR("Undef"), false);
    }
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_master()) {
        return OLED_ROTATION_270;
    }
    return rotation;
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        print_status_narrow();
    } else {
        render_logo();
    }
    return false;
}

#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_QWERTY:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_QWERTY);
            }
            return false;
        case KC_01:
            if (record->event.pressed) {
                layer_on(_01);
                update_tri_layer(_01, _02, _ADJUST);
            } else {
                layer_off(_01);
                update_tri_layer(_01, _02, _ADJUST);
            }
            return false;
        case KC_02:
            if (record->event.pressed) {
                layer_on(_02);
                update_tri_layer(_01, _02, _ADJUST);
            } else {
                layer_off(_02);
                update_tri_layer(_01, _02, _ADJUST);
            }
            return false;
    }
    return true;
}

#ifdef ENCODER_ENABLE

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
		} else if (index == 1) {
			switch (get_highest_layer(layer_state)) {
				case _QWERTY:
					if (clockwise) {
						tap_code(KC_PGDN);
					} else {
						tap_code(KC_PGUP);
					}
				break;
			case _02:
			case _01:
					if (clockwise) {
						tap_code(KC_DOWN);
					} else {
						tap_code(KC_UP);
					}
				break;
			default:
					if (clockwise) {
						tap_code(KC_WH_D);
					} else {
						tap_code(KC_WH_U);
					}
				break;
		}
    }
    return true;
}

#endif