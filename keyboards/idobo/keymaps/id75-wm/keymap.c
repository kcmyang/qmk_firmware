#include QMK_KEYBOARD_H

enum custom_keycodes {
  MY_HOME = SAFE_RANGE,
  MY_END,
  MY_UNDS,
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

static bool fast_mod(uint16_t mod, uint16_t keycode) {
  register_code(mod);
  register_code(keycode);
  unregister_code(keycode);
  unregister_code(mod);
  return false;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
  case MY_HOME:
    if (record->event.pressed)
      return fast_mod(KC_LGUI, KC_LEFT);
    break;
  case MY_END:
    if (record->event.pressed)
      return fast_mod(KC_LGUI, KC_RIGHT);
    break;
  case MY_UNDS:
    if (record->event.pressed)
      return fast_mod(KC_LSFT, KC_MINS);
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
    KC_GESC,       KC_1,     KC_2,     KC_3,    KC_4,    KC_5,    KC_MRWD, KC_MPLY, KC_MFFD, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
    KC_TAB,        KC_Q,     KC_D,     KC_R,    KC_W,    KC_B,    KC_GRV,  KC_PGUP, KC_BSLS, KC_J,    KC_F,    KC_U,    KC_P,    KC_SCLN, KC_DEL,
    LT(4, KC_ESC), KC_A,     KC_S,     KC_H,    KC_T,    KC_G,    KC_DEL,  KC_PGDN, KC_BSPC, KC_Y,    KC_N,    KC_E,    KC_O,    KC_I,    KC_ENT,
    KC_LSFT,       KC_Z,     KC_X,     KC_M,    KC_C,    KC_V,    KC_HOME, KC_UP,   KC_END,  KC_K,    KC_L,    KC_COMM, KC_DOT,  KC_QUOT, KC_RSFT,
    KC_LCTL,       MO(5),    KC_LALT,  KC_LGUI, MO(2),   KC_SPC,  KC_LEFT, KC_DOWN, KC_RGHT, KC_BSPC, MO(3),   KC_RGUI, KC_RALT, TG(1),   KC_RCTL
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
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
    KC_NO,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_NO,   KC_NO,   KC_NO,   KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_NO,
    KC_TRNS, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_NO,   KC_NO,   KC_NO,   KC_CIRC, KC_AMPR, KC_ASTR, KC_PLUS, MY_UNDS, KC_NO,
    KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_QUES, KC_TILD, KC_TRNS,
    KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_TRNS, KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_TRNS, MO(5),   KC_NO,   KC_NO,   KC_NO,   KC_TRNS
  ),
  // Raise
	[3] = LAYOUT_ortho_5x15(
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
    KC_NO,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_NO,   KC_NO,   KC_NO,   KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_NO,
    KC_TRNS, MY_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_BSLS, KC_LPRN, KC_RPRN, KC_EQL,  KC_MINS, KC_NO,
    KC_TRNS, KC_TILD, KC_QUES, KC_LT,   KC_GT,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_PIPE, KC_LBRC, KC_RBRC, KC_SLSH, KC_GRV,  KC_TRNS,
    KC_TRNS, KC_NO,   KC_NO,   KC_NO,   MO(5),   KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_TRNS, KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_TRNS
  ),
  // Extend
	[4] = LAYOUT_ortho_5x15(
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_PSCR, KC_SLCK, KC_PAUS, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_MS_U, KC_NO,   KC_NO,   KC_NO,   KC_HOME, KC_PGUP, KC_UP,   KC_PGDN, KC_END,  KC_NO,
    KC_TRNS, KC_NO,   KC_LCTL, KC_LSFT, KC_LALT, KC_MS_D, KC_NO,   KC_NO,   KC_NO,   MY_HOME, KC_LEFT, KC_DOWN, KC_RGHT, MY_END,  KC_TAB,
    KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_BTN3, KC_BTN1, KC_MS_L, KC_MS_R, KC_BTN2, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_DEL,  KC_NO,   KC_TRNS, KC_NO,   KC_NO,   KC_TRNS
  ),
  // Function
	[5] = LAYOUT_ortho_5x15(
    RESET,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_CAPS, KC_NLCK, KC_SLCK, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
    KC_NO,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_MUTE, KC_VOLD, KC_VOLU, KC_BRIU, KC_NO,
    KC_NO,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_MRWD, KC_MPLY, KC_MFFD, KC_BRID, KC_NO,
    KC_NO,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
    KC_NO,   KC_TRNS, KC_NO,   KC_NO,   KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_NO
  )
};
