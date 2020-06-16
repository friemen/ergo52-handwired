#include QMK_KEYBOARD_H
#include "stdio.h"

// WATCHOUT: using SAFE_RANGE just didn't work
#define KEYMAP_SAFE_RANGE 23842

enum custom_layers {
  _QWERTY = 0,
  _MODS,
  _FN1,
  _MPOINT,
  _MWHEEL,
  _UMLAUTS,
  _NUM,
  _BRACKETS,
  _TEXT
};

enum custom_keycodes {
  M_UMLA = KEYMAP_SAFE_RANGE,
  M_UMLO,
  M_UMLU,
  M_ESZETT,
  M_EURO,
  M_POUND,
  M_YEN,
  M_BFNBGBM,
  M_DTMS
};

#define CAPS_UML   OSL(_UMLAUTS)
#define Q_MPOINT   LT(_MPOINT,KC_Q)
#define W_MWHEEL   LT(_MWHEEL,KC_W)
#define GRV_LSFT   MT(MOD_LSFT, KC_GRV)
#define A_CTL      MT(MOD_LCTL, KC_A)
#define S_GUI      MT(MOD_LGUI, KC_S)
#define D_ALT      MT(MOD_LALT, KC_D)
#define F_FN1      LT(_FN1, KC_F)
#define J_FN1      LT(_FN1, KC_J)
#define K_ALT      MT(MOD_LALT, KC_K)
#define L_GUI      MT(MOD_RGUI, KC_L)
#define SCLN_CTL   MT(MOD_RCTL, KC_SCLN)
#define QUOT_RSFT  MT(MOD_RSFT, KC_QUOT)
#define CTL_PLUS   LCTL(KC_PLUS)
#define CTL_MINS   LCTL(KC_MINUS)
#define APP_NUM    LT(_NUM,KC_APP)
#define BSPC_BRC   LT(_BRACKETS, KC_BSPC)
#define ENT_NUM    LT(_NUM,KC_ENT)


// ERGO52
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT(
    KC_ESC,    KC_EXLM,   KC_AT,     KC_HASH,   KC_DLR,    KC_PERC,   KC_CIRC,   KC_AMPR,   KC_ASTR,   KC_MINS,   KC_EQL,    KC_BSPC, \
    KC_TAB,    Q_MPOINT,  W_MWHEEL,  KC_E,      KC_R,      KC_T,      KC_Y,      KC_U,      KC_I,      KC_O,      KC_P,      KC_BSLS, \
    KC_LSFT,   KC_A,      KC_S,      KC_D,      KC_F,      KC_G,      KC_H,      KC_J,      KC_K,      KC_L,      KC_SCLN,   KC_QUOT, \
    CAPS_UML,  KC_Z,      KC_X,      KC_C,      KC_V,      KC_B,      KC_N,      KC_M,      KC_COMM,   KC_DOT,    KC_SLSH,   CAPS_UML,\
                                                APP_NUM,   BSPC_BRC,  KC_SPC,    ENT_NUM \
  ),
  // always activated
  [_MODS] = LAYOUT(
    _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______, \
    _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______, \
    GRV_LSFT,  A_CTL,     S_GUI,     D_ALT,     F_FN1,     _______,   _______,   J_FN1,     K_ALT,     L_GUI,     SCLN_CTL,  QUOT_RSFT, \
    _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______, \
                                                _______,   _______,   _______,   _______ \
  ),

  [_FN1] = LAYOUT(
    KC_GRV,    KC_F1,     KC_F2,     KC_F3,     KC_F4,     KC_F5,     KC_F6,     KC_F7,     KC_F8,     KC_F9,     KC_F10,    KC_DEL,   \
    _______,   KC_F11,    KC_F12,    _______,   _______,  OSL(_TEXT), _______,   _______,   KC_UP,     KC_PGUP,   KC_PGDN,   CTL_PLUS, \
    _______,   _______,   _______,   _______,   _______,   _______,   KC_HOME,   KC_LEFT,   KC_DOWN,   KC_RIGHT,  KC_END,    CTL_MINS, \
    RESET,     _______,   _______,   _______,   KC_MPLY,   KC_MNXT,   KC_HOME,   KC_END,    KC_VOLD,   KC_VOLU,   KC_MUTE,   _______,  \
                                                _______,   _______,   _______,   _______  \
  ),

  [_MPOINT] = LAYOUT(
    _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______, \
    _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   KC_MS_U,   _______,   _______,   _______, \
    _______,   _______,   _______,   _______,   _______,   _______,   _______,   KC_MS_L,   KC_MS_D,   KC_MS_R,   _______,   _______, \
    _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______, \
                                                _______,   KC_BTN1,   KC_BTN2,   _______ \
  ),

  [_MWHEEL] = LAYOUT(
    _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______, \
    _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   KC_WH_U,   _______,   _______,   _______, \
    _______,   _______,   _______,   _______,   _______,   _______,   _______,   KC_WH_L,   KC_WH_D,   KC_WH_R,   _______,   _______, \
    _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______, \
                                                _______,   _______,   _______,   _______ \
  ),

  [_UMLAUTS] = LAYOUT(
    _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______, \
    _______,   _______,   _______,   M_EURO,    _______,   _______,   M_YEN,     M_UMLU,    _______,   M_UMLO,    M_POUND,   _______, \
    _______,   M_UMLA,    M_ESZETT,  KC_DLR,    _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______, \
    KC_CAPS,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   KC_CAPS, \
                                                _______,   _______,   _______,   _______ \
  ),

  [_NUM] = LAYOUT(
    _______,   KC_1,      KC_2,      KC_3,      KC_4,      KC_5,      KC_6,      KC_7,      KC_8,      KC_9,      KC_0,      _______, \
    _______,   _______,   _______,   _______,   _______,   _______,   _______,   KC_4,      KC_5,      KC_6,      KC_PLUS,   KC_ASTR, \
    _______,   _______,   _______,   _______,   _______,   _______,   _______,   KC_1,      KC_2,      KC_3,      KC_MINS,   KC_SLSH, \
    _______,   _______,   _______,   _______,   _______,   _______,   _______,   KC_0,      KC_COMM,   KC_DOT,    KC_EQL,    KC_ENT, \
                                                _______,   _______,   _______,   _______ \
  ),

  [_BRACKETS] = LAYOUT(
    _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   KC_LPRN,   KC_RPRN,   _______,   _______, \
    _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   KC_LBRC,   KC_RBRC,   _______,   _______, \
    _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   KC_LCBR,   KC_RCBR,   _______,   _______, \
    _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   KC_LT,     KC_GT,     _______,   _______, \
                                                _______,   _______,   _______,   _______ \
  ),

  [_TEXT] = LAYOUT(
    _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______, \
    _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______, \
    _______,   _______,   _______,   M_DTMS,    _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______, \
    _______,   _______,   _______,   _______,   _______,  M_BFNBGBM,  _______,   _______,   _______,   _______,   _______,   _______, \
                                                _______,   _______,   _______,   _______ \
  )

  /* [_NEWLAYER] = LAYOUT( */
  /*   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______, \ */
  /*   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______, \ */
  /*   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______, \ */
  /*   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______, \ */
  /*                                               _______,   _______,   _______,   _______     \ */
  /* ) */
};



// right after keyboard init
void keyboard_post_init_user() {
  layer_on(_MODS);
}


// macros
void compose_umlaut(char *umlaut) {
  bool is_shift = keyboard_report->mods & (MOD_BIT(KC_LSFT) | MOD_BIT(KC_RSFT));
  if (is_shift) {
    SEND_STRING(SS_TAP(X_CAPSLOCK) SS_TAP(X_QUOT));
  } else {
    SEND_STRING(SS_TAP(X_CAPSLOCK) SS_LSFT(SS_TAP(X_QUOT)));
  }
  send_string(umlaut);
};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  /* char keycode_string[20]; */
  /* sprintf(keycode_string,"%d  ",keycode); */
  /* send_string(keycode_string); */

  switch (keycode) {
  case M_UMLA:
    if (record->event.pressed) {
      compose_umlaut("a");
      layer_off(_UMLAUTS);
    }
    return false;
  case M_UMLO:
    if (record->event.pressed) {
      compose_umlaut("o");
      layer_off(_UMLAUTS);
    }
    return false;
  case M_UMLU:
    if (record->event.pressed) {
      compose_umlaut("u");
      layer_off(_UMLAUTS);
    }
    return false;
  case M_ESZETT:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_CAPSLOCK) SS_DELAY(50) SS_TAP(X_S) SS_TAP(X_S));
      layer_off(_UMLAUTS);
    }
    return false;
  case M_EURO:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_CAPSLOCK) SS_DELAY(50) SS_TAP(X_E) SS_TAP(X_EQL));
      layer_off(_UMLAUTS);
    }
    return false;
  case M_POUND:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_CAPSLOCK) SS_DELAY(50) SS_TAP(X_L) SS_TAP(X_MINS));
      layer_off(_UMLAUTS);
    }
    return false;
  case M_YEN:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_CAPSLOCK) SS_DELAY(50) SS_TAP(X_Y) SS_TAP(X_MINS));
      layer_off(_UMLAUTS);
    }
    return false;
  case M_BFNBGBM:
    if (record->event.pressed) {
      SEND_STRING("BFNBGBM-");
    }
    return false;
  case M_DTMS:
    if (record->event.pressed) {
      SEND_STRING("DTMS-");
    }
    return false;
  default:
    return true;
  }
};

// reacting on layer change

bool _num = false;

layer_state_t layer_state_set_user(layer_state_t state) {
  /* char state_string[20]; */
  /* sprintf(state_string,"%lu  ", state); */
  /* send_string(state_string); */

  // send F13 (keycode 191) and F14 (keycode 192) when _NUM layer state changes
  // these keypresses correspond to i3 bindcode expressions
  /* bool old_num = _num; */
  /* if (state & (1 << _NUM)) { */
  /*   _num = true; */
  /* } else { */
  /*   _num = false; */
  /* } */
  /* if (old_num != _num) { */
  /*   if (_num) { */
  /*     SEND_STRING(SS_LGUI(SS_TAP(X_F14))); */
  /*   } else { */
  /*     SEND_STRING(SS_LGUI(SS_TAP(X_F13))); */
  /*   } */
  /* } */
  return state;
};
