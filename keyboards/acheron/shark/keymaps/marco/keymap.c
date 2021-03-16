#include QMK_KEYBOARD_H

enum custom_keycodes {
  MY_HOME = SAFE_RANGE,
  MY_END,
  MY_LPRN,
  MY_RPRN,
  MY_LCBR,
  MY_RCBR,
  MY_LT,
  MY_GT,
  MY_UNDS,
  MY_EXLM,
  MY_AT,
  MY_HASH,
  MY_DLR,
  MY_PERC,
  MY_CIRC,
  MY_AMPR,
  MY_ASTR,
  MY_PLUS,
  MY_TILD,
  MY_QUES,
};

#define MY_WARM_WHITE 21, 214, 255
#define MY_WHITE 43, 3, 252
#define MY_RED 244, 255, 255
#define MY_ORANGE 21, 255, 255
#define MY_MAGENTA 177, 220, 240
#define MY_GREEN 71, 255, 230

/*
const rgblight_segment_t PROGMEM _workman_layer[] = RGBLIGHT_LAYER_SEGMENTS(
  {0, 16, MY_WHITE}
);
const rgblight_segment_t PROGMEM _alternate_layer[] = RGBLIGHT_LAYER_SEGMENTS(
  {0, 1, MY_RED},
  {7, 2, MY_RED},
  {15, 1, MY_RED}
);
const rgblight_segment_t PROGMEM _lower_layer[] = RGBLIGHT_LAYER_SEGMENTS(
  {12, 3, HSV_CYAN}
);
const rgblight_segment_t PROGMEM _raise_layer[] = RGBLIGHT_LAYER_SEGMENTS(
  {9, 3, MY_ORANGE}
);
const rgblight_segment_t PROGMEM _extend_layer[] = RGBLIGHT_LAYER_SEGMENTS(
  {9, 6, MY_MAGENTA}
);
const rgblight_segment_t PROGMEM _function_layer[] = RGBLIGHT_LAYER_SEGMENTS(
  {9, 6, MY_GREEN}
);
const rgblight_segment_t PROGMEM _esc_blink_layer[] = RGBLIGHT_LAYER_SEGMENTS(
  {3, 2, MY_RED},
  {11, 2, MY_RED}
);

const rgblight_segment_t * const PROGMEM _rgb_layers[] = RGBLIGHT_LAYERS_LIST(
  _alternate_layer,
  _extend_layer,
  _lower_layer,
  _raise_layer,
  _function_layer,
  _esc_blink_layer
);
*/

// Layer numbers
enum layers {
    WORKMAN = 0,
    ALTERNATE,
    EXTEND,
    LOWER,
    RAISE,
    FUNCTION,
};

// Keycodes for layout matrix
#define MY_ALTR TG(ALTERNATE)
#define MY_XTND LT(EXTEND, KC_ESC)
#define MY_LOWR MO(LOWER)
#define MY_RAIS MO(RAISE)
#define MY_FUNC MO(FUNCTION)
#define MY_TSFT LM(SHIFT, MOD_LSFT)

static bool fast_mod(uint16_t mod, uint16_t keycode) {
  register_code(mod);
  register_code(keycode);
  unregister_code(keycode);
  unregister_code(mod);
  return false;
}

/*
void keyboard_post_init_user(void) {
  rgblight_layers = _rgb_layers;
  rgblight_enable_noeeprom();
  rgblight_sethsv_noeeprom(42, 192, 255);
  rgblight_mode_noeeprom(RGBLIGHT_MODE_RAINBOW_SWIRL + 4);
}

layer_state_t layer_state_set_user(layer_state_t state) {
  rgblight_set_layer_state(0, layer_state_cmp(state, 1));
  rgblight_set_layer_state(1, layer_state_cmp(state, 2));
  rgblight_set_layer_state(2, layer_state_cmp(state, 3));
  rgblight_set_layer_state(3, layer_state_cmp(state, 4));
  rgblight_set_layer_state(4, layer_state_cmp(state, 5));
  return state;
}
*/

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
  case MY_HOME:
    if (record->event.pressed)
      return fast_mod(KC_LGUI, KC_LEFT);
    break;
  case MY_END:
    if (record->event.pressed)
      return fast_mod(KC_LGUI, KC_RGHT);
    break;
  case MY_LPRN:
    if (record->event.pressed)
      return fast_mod(KC_LSFT, KC_9);
    break;
  case MY_RPRN:
    if (record->event.pressed)
      return fast_mod(KC_LSFT, KC_0);
    break;
  case MY_LCBR:
    if (record->event.pressed)
      return fast_mod(KC_LSFT, KC_LBRC);
    break;
  case MY_RCBR:
    if (record->event.pressed)
      return fast_mod(KC_LSFT, KC_RBRC);
    break;
  case MY_LT:
    if (record->event.pressed)
      return fast_mod(KC_LSFT, KC_COMM);
    break;
  case MY_GT:
    if (record->event.pressed)
      return fast_mod(KC_LSFT, KC_DOT);
    break;
  case MY_UNDS:
    if (record->event.pressed)
      return fast_mod(KC_LSFT, KC_MINS);
    break;
  case MY_EXLM:
    if (record->event.pressed)
      return fast_mod(KC_LSFT, KC_1);
    break;
  case MY_AT:
    if (record->event.pressed)
      return fast_mod(KC_LSFT, KC_2);
    break;
  case MY_HASH:
    if (record->event.pressed)
      return fast_mod(KC_LSFT, KC_3);
    break;
  case MY_DLR:
    if (record->event.pressed)
      return fast_mod(KC_LSFT, KC_4);
    break;
  case MY_PERC:
    if (record->event.pressed)
      return fast_mod(KC_LSFT, KC_5);
    break;
  case MY_CIRC:
    if (record->event.pressed)
      return fast_mod(KC_LSFT, KC_6);
    break;
  case MY_AMPR:
    if (record->event.pressed)
      return fast_mod(KC_LSFT, KC_7);
    break;
  case MY_ASTR:
    if (record->event.pressed)
      return fast_mod(KC_LSFT, KC_8);
    break;
  case MY_PLUS:
    if (record->event.pressed)
      return fast_mod(KC_LSFT, KC_EQL);
    break;
  case MY_TILD:
    if (record->event.pressed)
      return fast_mod(KC_LSFT, KC_GRV);
    break;
  case MY_QUES:
    if (record->event.pressed)
      return fast_mod(KC_LSFT, KC_SLSH);
    break;
  }

  return true;
}

/*
void post_process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
  case MY_XTND:
    if (record->tap.count > 0) {
      rgblight_blink_layer(5, 150);
    }
    break;
  }
}
*/

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // Workman
  [0] = LAYOUT_ortho_4x12(
    KC_TAB,  KC_Q,    KC_D,    KC_R,    KC_W,    KC_B,    KC_J,    KC_F,    KC_U,    KC_P,    KC_SCLN, KC_DEL,
    MY_XTND, KC_A,    KC_S,    KC_H,    KC_T,    KC_G,    KC_Y,    KC_N,    KC_E,    KC_O,    KC_I,    KC_ENT,
    KC_LSFT, KC_Z,    KC_X,    KC_M,    KC_C,    KC_V,    KC_K,    KC_L,    KC_COMM, KC_DOT,  KC_QUOT, KC_RSFT,
    KC_LCTL, MY_ALTR, KC_LALT, KC_LGUI, MY_LOWR, KC_SPC,  KC_BSPC, MY_RAIS, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
  ),
  // Alternate base
  [ALTERNATE] = LAYOUT_ortho_4x12(
    KC_TAB,  KC_Q,    KC_D,    KC_R,    KC_W,    KC_B,    KC_J,    KC_F,    KC_UP,   KC_P,    KC_SCLN, KC_DEL,
    MY_XTND, KC_A,    KC_S,    KC_H,    KC_T,    KC_G,    KC_Y,    KC_LEFT, KC_DOWN, KC_RGHT, KC_I,    KC_ENT,
    KC_LSFT, KC_Z,    KC_X,    KC_M,    KC_C,    KC_V,    KC_K,    KC_L,    KC_COMM, KC_DOT,  KC_QUOT, KC_RSFT,
    KC_LCTL, MY_ALTR, KC_LALT, KC_LGUI, MY_LOWR, KC_SPC,  KC_BSPC, MY_RAIS, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
  ),
  // Extend
  [EXTEND] = LAYOUT_ortho_4x12(
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_MS_U, KC_HOME, KC_PGUP, KC_UP,   KC_PGDN, KC_END,  KC_NO,
    KC_TRNS, KC_NO,   KC_LCTL, KC_LSFT, KC_LALT, KC_MS_D, MY_HOME, KC_LEFT, KC_DOWN, KC_RGHT, MY_END,  KC_TAB,
    KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_BTN3, KC_BTN1, KC_MS_L, KC_MS_R, KC_BTN2, KC_TRNS,
    KC_TRNS, KC_NO,   KC_NO,   KC_NO,   MY_LOWR, KC_NO,   KC_DEL,  MY_RAIS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
  ),
  // Lower
  [LOWER] = LAYOUT_ortho_4x12(
    KC_NO,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_NO,
    KC_TRNS, MY_EXLM, MY_AT,   MY_HASH, MY_DLR,  MY_PERC, MY_CIRC, MY_AMPR, MY_ASTR, MY_PLUS, MY_UNDS, KC_TRNS,
    KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   MY_QUES, MY_TILD, KC_TRNS,
    KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_TRNS, KC_TRNS, KC_TRNS, MY_FUNC, KC_NO,   KC_NO,   KC_NO,   KC_NO
  ),
  // Raise
  [RAISE] = LAYOUT_ortho_4x12(
    KC_NO,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_NO,
    KC_TRNS, MY_UNDS, MY_PLUS, KC_LBRC, KC_RBRC, KC_NO,   KC_BSLS, MY_LPRN, MY_RPRN, KC_EQL,  KC_MINS, KC_TRNS,
    KC_TRNS, MY_TILD, MY_QUES, MY_LT,   MY_GT,   KC_NO,   KC_PIPE, MY_LCBR, MY_RCBR, KC_SLSH, KC_GRV,  KC_TRNS,
    KC_TRNS, KC_NO,   KC_NO,   KC_NO,   MY_FUNC, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_NO
  ),
  // Function
  [FUNCTION] = LAYOUT_ortho_4x12(
    RESET,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_CAPS, KC_NO,   KC_MUTE, KC_VOLD, KC_VOLU, KC_BRIU, KC_PSCR,
    KC_TRNS, KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_NLCK, VLK_TOG, KC_MRWD, KC_MPLY, KC_MFFD, KC_BRID, KC_PAUS,
    KC_TRNS, KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_SLCK, RGB_HUI, RGB_SAI, RGB_M_P, RGB_M_SW,RGB_TOG, KC_TRNS,
    EEP_RST, KC_TRNS, KC_NO,   KC_NO,   KC_TRNS, KC_NO,   KC_NO,   KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_NO
  )
};
