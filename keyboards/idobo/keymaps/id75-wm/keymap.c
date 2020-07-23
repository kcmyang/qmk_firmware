#include QMK_KEYBOARD_H

enum custom_keycodes {
  MY_HOME = SAFE_RANGE,
  MY_END,
  MY_LPRN,
  MY_RPRN,
  MY_LCBR,
  MY_RCBR,
  MY_UNDS,
  MY_CIRC,
  NOT,
  AND,
  OR,
  IMPLIES,
  IFF,
  FORALL,
  EXISTS,
  PROVES,
  CONSEQ,
  TAUTEQ,
  SIGMA,
  UNION,
  APPROX
};

const rgblight_segment_t PROGMEM _workman_layer[] = RGBLIGHT_LAYER_SEGMENTS(
  {0, 16, HSV_WHITE}
);
const rgblight_segment_t PROGMEM _qwerty_layer[] = RGBLIGHT_LAYER_SEGMENTS(
  {0, 1, HSV_RED},
  {7, 2, HSV_RED},
  {15, 1, HSV_RED}
);
const rgblight_segment_t PROGMEM _lower_layer[] = RGBLIGHT_LAYER_SEGMENTS(
  {12, 3, HSV_CYAN}
);
const rgblight_segment_t PROGMEM _raise_layer[] = RGBLIGHT_LAYER_SEGMENTS(
  {9, 3, HSV_ORANGE}
);
const rgblight_segment_t PROGMEM _extend_layer[] = RGBLIGHT_LAYER_SEGMENTS(
  {9, 6, HSV_MAGENTA}
);
const rgblight_segment_t PROGMEM _function_layer[] = RGBLIGHT_LAYER_SEGMENTS(
  {9, 6, HSV_GREEN}
);

const rgblight_segment_t * const PROGMEM _rgb_layers[] = RGBLIGHT_LAYERS_LIST(
  _workman_layer,
  _qwerty_layer,
  _lower_layer,
  _raise_layer,
  _extend_layer,
  _function_layer
);

// #define MY_LOWR LT(2, KC_TAB)
#define MY_LOWR MO(2)
// #define MY_RAIS LT(3, KC_DEL)
#define MY_RAIS MO(3)
#define MY_XTND LT(4, KC_ESC)

static bool fast_mod(uint16_t mod, uint16_t keycode) {
  register_code(mod);
  register_code(keycode);
  unregister_code(keycode);
  unregister_code(mod);
  return false;
}

void keyboard_post_init_user(void) {
  rgblight_layers = _rgb_layers;
  rgblight_enable_noeeprom();
  rgblight_sethsv_noeeprom(HSV_WHITE);
}

layer_state_t layer_state_set_user(layer_state_t state) {
  rgblight_set_layer_state(0, layer_state_cmp(state, 0));
  rgblight_set_layer_state(1, layer_state_cmp(state, 1));
  rgblight_set_layer_state(2, layer_state_cmp(state, 2));
  rgblight_set_layer_state(3, layer_state_cmp(state, 3));
  rgblight_set_layer_state(4, layer_state_cmp(state, 4));
  rgblight_set_layer_state(5, layer_state_cmp(state, 5));
  return state;
}

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
  case MY_UNDS:
    if (record->event.pressed)
      return fast_mod(KC_LSFT, KC_MINS);
    break;
  case MY_CIRC:
    if (record->event.pressed)
      return fast_mod(KC_LSFT, KC_6);
    break;
  case NOT:
    if (record->event.pressed)
      SEND_STRING("@NOT");
    break;
  case AND:
    if (record->event.pressed)
      SEND_STRING("@AND");
    break;
  case OR:
    if (record->event.pressed)
      SEND_STRING("@OR");
    break;
  case IMPLIES:
    if (record->event.pressed)
      SEND_STRING("@IMPLIES");
    break;
  case IFF:
    if (record->event.pressed)
      SEND_STRING("@IFF");
    break;
  case FORALL:
    if (record->event.pressed)
      SEND_STRING("@FORALL");
    break;
  case EXISTS:
    if (record->event.pressed)
      SEND_STRING("@EXISTS");
    break;
  case PROVES:
    if (record->event.pressed)
      SEND_STRING("@PROVES");
    break;
  case CONSEQ:
    if (record->event.pressed)
      SEND_STRING("@CONSEQ");
    break;
  case TAUTEQ:
    if (record->event.pressed)
      SEND_STRING("@TAUTEQ");
    break;
  case SIGMA:
    if (record->event.pressed)
      SEND_STRING("@SIGMA");
    break;
  case UNION:
    if (record->event.pressed)
      SEND_STRING("@UNION");
    break;
  case APPROX:
    if (record->event.pressed)
      SEND_STRING("@APPROX");
    break;
  }

  return true;
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // Workman
  [0] = LAYOUT_ortho_5x15(
    KC_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_MRWD, KC_MPLY, KC_MFFD, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
    KC_TAB,  KC_Q,    KC_D,    KC_R,    KC_W,    KC_B,    KC_GRV,  KC_PGUP, KC_BSLS, KC_J,    KC_F,    KC_U,    KC_P,    KC_SCLN, KC_DEL,
    MY_XTND, KC_A,    KC_S,    KC_H,    KC_T,    KC_G,    KC_DEL,  KC_PGDN, KC_BSPC, KC_Y,    KC_N,    KC_E,    KC_O,    KC_I,    KC_ENT,
    KC_LSFT, KC_Z,    KC_X,    KC_M,    KC_C,    KC_V,    KC_HOME, KC_UP,   KC_END,  KC_K,    KC_L,    KC_COMM, KC_DOT,  KC_QUOT, KC_RSFT,
    KC_LCTL, TG(1),   KC_LALT, KC_LGUI, MY_LOWR, KC_SPC,  KC_LEFT, KC_DOWN, KC_RGHT, KC_BSPC, MY_RAIS, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
  ),
  // QWERTY, currently used for macros
  [1] = LAYOUT_ortho_5x15(
    KC_GRV,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, SIGMA,   APPROX,  UNION,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, NOT,     AND,     OR,      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, IMPLIES, IFF,     FORALL,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, PROVES,  CONSEQ,  EXISTS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, TAUTEQ,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
  ),
  // Lower
  [2] = LAYOUT_ortho_5x15(
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_NO,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_NO,   KC_NO,   KC_NO,   KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_NO,
    KC_TRNS, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_NO,   KC_NO,   KC_NO,   MY_CIRC, KC_AMPR, KC_ASTR, KC_PLUS, MY_UNDS, KC_TRNS,
    KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_QUES, KC_TILD, KC_TRNS,
    KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_TRNS, KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_TRNS, MO(5),   KC_NO,   KC_NO,   KC_NO,   KC_NO
  ),
  // Raise
  [3] = LAYOUT_ortho_5x15(
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_NO,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_NO,   KC_NO,   KC_NO,   KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_NO,
    KC_TRNS, MY_UNDS, KC_PLUS, KC_LBRC, KC_RBRC, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_BSLS, MY_LPRN, MY_RPRN, KC_EQL,  KC_MINS, KC_TRNS,
    KC_TRNS, KC_TILD, KC_QUES, KC_LT,   KC_GT,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_PIPE, MY_LCBR, MY_RCBR, KC_SLSH, KC_GRV,  KC_TRNS,
    KC_TRNS, KC_NO,   KC_NO,   KC_NO,   MO(5),   KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_TRNS, KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_NO
  ),
  // Extend
  [4] = LAYOUT_ortho_5x15(
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_PSCR, KC_SLCK, KC_PAUS, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_MS_U, KC_NO,   KC_NO,   KC_NO,   KC_HOME, KC_PGUP, KC_UP,   KC_PGDN, KC_END,  KC_NO,
    KC_TRNS, KC_NO,   KC_LCTL, KC_LSFT, KC_LALT, KC_MS_D, KC_NO,   KC_NO,   KC_NO,   MY_HOME, KC_LEFT, KC_DOWN, KC_RGHT, MY_END,  KC_TAB,
    KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_BTN3, KC_BTN1, KC_MS_L, KC_MS_R, KC_BTN2, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_DEL,  KC_NO,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
  ),
  // Function
  [5] = LAYOUT_ortho_5x15(
    RESET,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_CAPS, KC_NLCK, KC_SLCK, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
    KC_NO,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_MUTE, KC_VOLD, KC_VOLU, KC_BRIU, KC_NO,
    KC_NO,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_MRWD, KC_MPLY, KC_MFFD, KC_BRID, KC_NO,
    KC_NO,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   RGB_TOG, KC_NO,
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_NO
  )
};
