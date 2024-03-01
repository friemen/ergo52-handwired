#include QMK_KEYBOARD_H
#include "stdio.h"

// WATCHOUT: using SAFE_RANGE just didn't work
#define KEYMAP_SAFE_RANGE 23842

enum custom_layers {
  _QWERTY_RIGHT = 0,
  _QWERTY_LEFT,
  _FN,
  _NAV,
  _MPOINT,
  _MWHEEL,
  _UMLAUTS,
  _NUM,
  _SYM,
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
  M_PARA,
  M_DEGR,
  M_LTLT,
  M_GTGT,
  M_BFNBGBM,
  M_DTKW,
  M_DTMS,
  M_IDWQSHB,
  M_OVSMSUP,
  M_SNAPS,
  M_WHEREBY
};

#define COMP_UML   OSL(_UMLAUTS)
#define GRV_LSFT   MT(MOD_LSFT, KC_GRV)
#define QUOT_RSFT  MT(MOD_RSFT, KC_QUOT)
#define CTL_PLUS   LCTL(KC_PLUS)
#define CTL_MINS   LCTL(KC_MINUS)
#define CTL_PGUP   LCTL(KC_PGUP)
#define CTL_PGDN   LCTL(KC_PGDN)
#define SPC_LEFT   LT(_QWERTY_LEFT, KC_SPC)
#define ENT_NAV    LT(_NAV, KC_ENT)
#define X_COMPOSE  X_SCRL    // this must match the setxkbmap -option "compose:sclk"


// ERGO52
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY_RIGHT] = LAYOUT_default(
    KC_ESC,    MO(_NUM),   _______,   _______,   _______,   _______,   KC_1,      KC_2,      KC_3,      KC_4,      KC_5,      KC_BSPC, \
    KC_LALT,   MO(_SYM),   _______,   _______,   _______,   _______,   KC_T,      KC_R,      KC_E,      KC_O,      KC_SCLN,   KC_DEL,  \
    KC_LSFT,   MO(_FN),    _______,   _______,   _______,   _______,   KC_G,      KC_F,      KC_D,      KC_S,      KC_A,      KC_RSFT, \
    KC_LCTL,   KC_LGUI, MO(_MPOINT),MO(_MWHEEL), _______,   _______,   KC_N,      KC_M,      KC_COMM,   KC_DOT,    KC_SLSH,   COMP_UML, \
                                                 KC_APP,    MO(_FN),   SPC_LEFT,  ENT_NAV \
  ),

  [_QWERTY_LEFT] = LAYOUT_default(
    KC_ESC,    MO(_NUM),  _______,   _______,   _______,   _______,   KC_6,      KC_7,      KC_8,      KC_9,      KC_0,      KC_ESC,   \
    KC_LALT,   MO(_SYM),  _______,   _______,   _______,   _______,   KC_Y,      KC_U,      KC_I,      KC_W,      KC_Q,      KC_TAB,   \
    KC_LSFT,   MO(_FN),   _______,   _______,   _______,   _______,   KC_H,      KC_J,      KC_K,      KC_L,      KC_P,      KC_RSFT,  \
    KC_LCTL,   KC_LGUI,   _______,   _______,   _______,   _______,   KC_B,      KC_V,      KC_C,      KC_X,      KC_Z,      COMP_UML, \
                                                _______,   _______,   _______,   _______ \
  ),

  [_FN] = LAYOUT_default(
    QK_BOOT,   _______,   _______,   _______,   _______,   _______,   KC_F1,     KC_F2,     KC_F3,     KC_F4,     KC_F5,     KC_F6,   \
    KC_LALT,   _______,   _______,   _______,   _______, OSL(_TEXT),  KC_F7,     KC_F8,     KC_F9,     KC_F10,    KC_F11,    KC_F12,  \
    KC_CAPS,   _______,   _______,   _______,   _______,   _______,   KC_PSCR,   KC_NO,     KC_MPRV,   KC_MPLY,   KC_MNXT,   KC_CAPS, \
    KC_LCTL,   _______,   _______,   _______,   _______,   _______,   CTL_MINS,  CTL_PLUS,  KC_VOLD,   KC_VOLU,   KC_MUTE,   KC_INS,  \
                                                _______,   _______,   KC_BRID,   KC_BRIU \
  ),

  [_NAV] = LAYOUT_default(
    KC_ESC,    _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   KC_BSPC, \
    _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   KC_UP,     KC_PGUP,   KC_PGDN,   KC_DEL,  \
    _______,   _______,   _______,   _______,   _______,   _______,   KC_HOME,   KC_LEFT,   KC_DOWN,   KC_RIGHT,  KC_END,    KC_CAPS, \
    _______,   _______,   _______,   _______,   _______,   _______,   CTL_PGUP,  CTL_PGDN,  _______,   _______,   _______,   KC_INS,  \
                                                _______,   _______,   _______,   _______  \
  ),

  [_MPOINT] = LAYOUT_default(
    _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______, \
    _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   KC_MS_U,   _______,   _______,   _______, \
    _______,   _______,   _______,   _______,   _______,   _______,   _______,   KC_MS_L,   KC_MS_D,   KC_MS_R,   _______,   _______, \
    _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______, \
                                                _______,   _______,   KC_BTN1,   KC_BTN2 \
  ),

  [_MWHEEL] = LAYOUT_default(
    _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______, \
    _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   KC_WH_U,   _______,   _______,   _______, \
    _______,   _______,   _______,   _______,   _______,   _______,   _______,   KC_WH_L,   KC_WH_D,   KC_WH_R,   _______,   _______, \
    _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______, \
                                                _______,   _______,   KC_BTN1,   KC_BTN2 \
  ),

  [_UMLAUTS] = LAYOUT_default(
    _______,   _______,   _______,   _______,   _______,   _______,   _______,   M_DEGR,    M_PARA,    _______,   _______,   _______, \
    _______,   _______,   _______,   _______,   _______,   _______,   M_YEN,     M_UMLU,    M_EURO,    M_UMLO,    _______,   _______, \
    _______,   _______,   _______,   _______,   _______,   _______,   M_POUND,   _______,   KC_DLR,    M_ESZETT,  M_UMLA,    _______, \
    KC_SCRL,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   M_LTLT,    M_GTGT,    _______,   KC_SCRL, \
                                                _______,   _______,   _______,   _______ \
  ),

  [_NUM] = LAYOUT_default(
    _______,   _______,   _______,   _______,   _______,   _______,   _______,   KC_KP_7,   KC_KP_8,   KC_KP_9,   KC_EQL,    _______, \
    _______,   _______,   _______,   _______,   _______,   _______,   _______,   KC_KP_4,   KC_KP_5,   KC_KP_6,   KC_PLUS,   KC_ASTR, \
    _______,   _______,   _______,   _______,   _______,   _______,   KC_COLN,   KC_KP_1,   KC_KP_2,   KC_KP_3,   KC_MINS,   KC_QUOT, \
    _______,   _______,   _______,   _______,   _______,   _______,   _______,   KC_KP_0,   KC_COMM,   KC_DOT,    KC_SLSH,   _______, \
                                                _______,   _______,   _______,   _______ \
  ),

  [_SYM] = LAYOUT_default(
    _______,   _______,   _______,   _______,   _______,   _______,   KC_CIRC,   KC_AMPR,   KC_LCBR,   KC_RCBR,   KC_EQL,    KC_PERC, \
    _______,   _______,   _______,   _______,   _______,   _______,   KC_PIPE,   KC_HASH,   KC_LBRC,   KC_RBRC,   KC_PLUS,   KC_GRV,  \
    _______,   _______,   _______,   _______,   _______,   _______,   KC_TILD,   KC_MINS,   KC_LPRN,   KC_RPRN,   KC_ASTR,   KC_DQUO, \
    _______,   _______,   _______,   _______,   _______,   _______,   KC_BSLS,   KC_UNDS,   KC_LT,     KC_GT,     KC_SLSH,   KC_QUOT, \
                                                _______,   _______,   KC_SPC,    KC_ENT \
  ),

  [_TEXT] = LAYOUT_default(
    _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______, \
    _______,   _______,  M_WHEREBY,  _______,   _______,   _______,   _______,   _______,   M_IDWQSHB, M_OVSMSUP, _______,   _______, \
    _______,   _______,   M_SNAPS,   M_DTMS,    _______,   _______,   _______,   _______,   M_DTKW,    _______,   _______,   _______, \
    _______,   _______,   _______,   _______,   _______,  M_BFNBGBM,  _______,   _______,   _______,   _______,   _______,   _______, \
                                                _______,   _______,   _______,   _______ \
  )

  /* [_NEWLAYER] = LAYOUT_default( */
  /*   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______, \ */
  /*   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______, \ */
  /*   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______, \ */
  /*   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______, \ */
  /*                                               _______,   _______,   _______,   _______     \ */
  /* ) */
};



// right after keyboard init
void keyboard_post_init_user() {
  // layer_on(_MODS);
}


// macros
void compose_umlaut(char *umlaut) {
  bool is_shift = keyboard_report->mods & (MOD_BIT(KC_LSFT) | MOD_BIT(KC_RSFT));
  if (is_shift) {
    SEND_STRING(SS_TAP(X_COMPOSE) SS_TAP(X_QUOT));
  } else {
    SEND_STRING(SS_TAP(X_COMPOSE) SS_LSFT(SS_TAP(X_QUOT)));
  }
  send_string(umlaut);
};


#define COMPOSE(KC,SEQUENCE) \
  case KC: \
    if (record->event.pressed) { \
      SEND_STRING(SS_TAP(X_COMPOSE) SS_DELAY(50) SEQUENCE); \
      layer_off(_UMLAUTS); \
    } \
    return false;


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  /* char keycode_string[20]; */
  /* sprintf(keycode_string,"%d  ",keycode); */
  /* send_string(keycode_string); */

  switch (keycode) {
    /* umlauts, currency symbols and other special characters */
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
  COMPOSE(M_ESZETT, SS_TAP(X_S) SS_TAP(X_S));
  COMPOSE(M_EURO,   SS_TAP(X_E) SS_TAP(X_EQL));
  COMPOSE(M_POUND,  SS_TAP(X_L) SS_TAP(X_MINS));
  COMPOSE(M_YEN,    SS_TAP(X_Y) SS_TAP(X_MINS));
  COMPOSE(M_PARA,   SS_TAP(X_O) SS_TAP(X_S));
  COMPOSE(M_DEGR,   SS_TAP(X_O) SS_TAP(X_O));
  COMPOSE(M_LTLT,   SS_LSFT(SS_TAP(X_COMMA) SS_TAP(X_COMMA)));
  COMPOSE(M_GTGT,   SS_LSFT(SS_TAP(X_DOT) SS_TAP(X_DOT)));
    /* text entering macros */
  case M_BFNBGBM:
    if (record->event.pressed) {
      SEND_STRING("BFNBGBM-");
    }
    return true;
  case M_DTKW:
    if (record->event.pressed) {
      SEND_STRING("DTKW-");
    }
    return true;
  case M_DTMS:
    if (record->event.pressed) {
      SEND_STRING("DTMS-");
    }
    return true;
  case M_IDWQSHB:
    if (record->event.pressed) {
      SEND_STRING("IDWQSHB-");
    }
    return true;
  case M_OVSMSUP:
    if (record->event.pressed) {
      SEND_STRING("OVSMSUP-");
    }
    return true;
  case M_SNAPS:
    if (record->event.pressed) {
      SEND_STRING("SNAPSHOT");
    }
    return true;
  case M_WHEREBY:
    if (record->event.pressed) {
      SEND_STRING("https://doctronic.whereby.com/falko");
    }
    return true;
  default:
    return true;
  }
};

// reacting on layer change

layer_state_t layer_state_set_user(layer_state_t state) {
  /* char state_string[20]; */
  /* sprintf(state_string,"%lu  ", state); */
  /* send_string(state_string); */

  // turn numlock on in _NUM layer
  bool numlock = (host_keyboard_leds() & (1 << USB_LED_NUM_LOCK));
  if (state & (1 << _NUM)) {
    if (!numlock) {
      SEND_STRING(SS_TAP(X_NUM));
    }
  } else {
    if (numlock) {
      SEND_STRING(SS_TAP(X_NUM));
    }
  }
  return state;
};
