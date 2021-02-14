#include QMK_KEYBOARD_H
#include "stdio.h"

// WATCHOUT: using SAFE_RANGE just didn't work
#define KEYMAP_SAFE_RANGE 23842

enum custom_layers {
  _QWERTY = 0,
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
  M_DTMS,
  M_OVSMSUP,
  M_SNAPS
};

#define COMP_UML   OSL(_UMLAUTS)
#define Q_MPOINT   LT(_MPOINT, KC_Q)
#define W_MWHEEL   LT(_MWHEEL, KC_W)
#define GRV_LSFT   MT(MOD_LSFT, KC_GRV)
#define A_CTL      MT(MOD_LCTL, KC_A)
#define S_GUI      MT(MOD_LGUI, KC_S)
#define D_ALT      MT(MOD_LALT, KC_D)
#define F_FN       LT(_FN, KC_F)
#define J_FN       LT(_FN, KC_J)
#define K_ALT      MT(MOD_LALT, KC_K)
#define L_GUI      MT(MOD_RGUI, KC_L)
#define P_CTL      MT(MOD_RCTL, KC_P)
#define QUOT_RSFT  MT(MOD_RSFT, KC_QUOT)
#define CTL_PLUS   LCTL(KC_PLUS)
#define CTL_MINS   LCTL(KC_MINUS)
#define CTL_PGUP   LCTL(KC_PGUP)
#define CTL_PGDN   LCTL(KC_PGDN)
#define APP_NUM    LT(_NUM, KC_APP)
#define BSPC_SYM   LT(_SYM, KC_BSPC)
#define SPC_SYM    LT(_SYM, KC_SPC)
#define ENT_NUM    LT(_NUM, KC_ENT)
#define X_COMPOSE  X_PAUSE    // this must match the setxkbmap -option "compose:paus"


// ERGO52
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT(
    KC_ESC,    KC_1,      KC_2,      KC_3,      KC_4,      KC_5,      KC_6,      KC_7,      KC_8,      KC_9,      KC_0,      KC_BSPC, \
    KC_TAB,    Q_MPOINT,  W_MWHEEL,  KC_E,      KC_R,      KC_T,      KC_Y,      KC_U,      KC_I,      KC_O,      KC_SCLN,   KC_DEL,  \
    KC_LSFT,   A_CTL,     S_GUI,     D_ALT,     F_FN,      KC_G,      KC_H,      J_FN,      K_ALT,     L_GUI,     P_CTL,     KC_RSFT, \
    COMP_UML,  KC_Z,      KC_X,      KC_C,      KC_V,      KC_B,      KC_N,      KC_M,      KC_COMM,   KC_DOT,    KC_SLSH,   COMP_UML,\
                                                APP_NUM,   BSPC_SYM,  SPC_SYM,   ENT_NUM \
  ),

  [_FN] = LAYOUT(
    _______,   KC_F1,     KC_F2,     KC_F3,     KC_F4,     KC_F5,     KC_F6,     KC_F7,     KC_F8,     KC_F9,     KC_F10,    _______, \
    KC_CAPS,   KC_F11,    KC_F12,    KC_NO,     KC_BRIU,  OSL(_TEXT), _______,   _______,   KC_UP,     KC_PGUP,   KC_PGDN,   KC_INS,  \
    _______,   _______,   KC_PSCR,   KC_NO,     KC_BRID,   _______,   KC_HOME,   KC_LEFT,   KC_DOWN,   KC_RIGHT,  KC_END,    KC_ENT,  \
    RESET,     CTL_MINS,  CTL_PLUS,  KC_MPRV,   KC_MPLY,   KC_MNXT,   CTL_PGUP,  CTL_PGDN,  KC_VOLD,   KC_VOLU,   KC_MUTE,   TG(_NAV),\
                                                _______,   KC_BSPC,   KC_SPC,    KC_ENT  \
  ),

  [_NAV] = LAYOUT(
   TG(_NAV),   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______, \
    _______,   _______,   _______,   KC_W,      _______,   _______,   _______,   _______,   KC_UP,     KC_PGUP,   KC_PGDN,   KC_DEL,  \
    _______,   KC_ESC,    KC_A,      KC_S,      KC_D,      _______,   KC_HOME,   KC_LEFT,   KC_DOWN,   KC_RIGHT,  KC_END,    KC_ENT,  \
    _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______, \
                                                KC_SPC,    KC_ENT,    _______,   _______  \
  ),

  [_MPOINT] = LAYOUT(
    _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______, \
    _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   KC_MS_U,   _______,   _______,   _______, \
    _______,   _______,   _______,   _______,   _______,   _______,   _______,   KC_MS_L,   KC_MS_D,   KC_MS_R,   _______,   _______, \
    _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______, \
                                                KC_BTN1,   KC_BTN2,   KC_BTN1,   KC_BTN2 \
  ),

  [_MWHEEL] = LAYOUT(
    _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______, \
    _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   KC_WH_U,   _______,   _______,   _______, \
    _______,   _______,   _______,   _______,   _______,   _______,   _______,   KC_WH_L,   KC_WH_D,   KC_WH_R,   _______,   _______, \
    _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______, \
                                                _______,   _______,   _______,   _______ \
  ),

  [_UMLAUTS] = LAYOUT(
    TG(_UMLAUTS), M_DEGR, _______,   M_PARA,    _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______, \
    _______,   _______,   _______,   M_EURO,    _______,   _______,   M_YEN,     M_UMLU,    _______,   M_UMLO,    _______,   _______, \
    _______,   M_UMLA,    M_ESZETT,  KC_DLR,    _______,   _______,   _______,   _______,   _______,   _______,   M_POUND,   _______, \
    KC_PAUS,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   M_LTLT,    M_GTGT,    _______,   KC_PAUS, \
                                                _______,   _______,   _______,   _______ \
  ),

  [_NUM] = LAYOUT(
    TG(_NUM),  KC_1,      KC_2,      KC_3,      KC_4,      KC_5,      KC_6,      KC_7,      KC_8,      KC_9,      KC_EQL,    _______, \
    TG(_NUM),  KC_4,      KC_5,      KC_6,      _______,   _______,   _______,   KC_4,      KC_5,      KC_6,      KC_PLUS,   KC_ASTR, \
    _______,   KC_7,      KC_8,      KC_9,      _______,   _______,   KC_COLN,   KC_1,      KC_2,      KC_3,      KC_MINS,   KC_QUOT, \
    _______,   KC_0,      _______,   _______,   _______,   _______,   _______,   KC_0,      KC_COMM,   KC_DOT,    KC_SLSH,   KC_ENT,  \
                                                _______,   _______,   _______,   _______ \
  ),

  [_SYM] = LAYOUT(
    _______,   KC_EXLM,   KC_AT,     KC_HASH,   KC_DLR,    KC_PERC,   KC_CIRC,   KC_AMPR,   KC_LCBR,   KC_RCBR,   KC_EQL,    _______, \
    _______,   KC_ASTR,   KC_PIPE,   KC_GRV,    KC_HASH,   KC_COMM,   KC_AT,     KC_HASH,   KC_LBRC,   KC_RBRC,   KC_PLUS,   KC_ASTR, \
    _______,   KC_COLN,   KC_TILD,   KC_DQUO,   KC_MINS,   KC_DOT,    KC_EXLM,   KC_MINS,   KC_LPRN,   KC_RPRN,   KC_MINS,   KC_QUOT, \
    _______,   KC_SCLN,   KC_BSLS,   KC_QUOT,   KC_UNDS,   KC_QUES,   KC_PERC,   KC_UNDS,   KC_LT,     KC_GT,     KC_SLSH,   _______, \
                                                _______,   _______,   _______,   _______ \
  ),

  [_TEXT] = LAYOUT(
    _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______, \
    _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   M_OVSMSUP, _______,   _______, \
    _______,   _______,   M_SNAPS,   M_DTMS,    _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______, \
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
  case M_DTMS:
    if (record->event.pressed) {
      SEND_STRING("DTMS-");
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
  default:
    return true;
  }
};

// reacting on layer change

/* bool _caps = false; */

/* layer_state_t layer_state_set_user(layer_state_t state) { */
/*   /\* char state_string[20]; *\/ */
/*   /\* sprintf(state_string,"%lu  ", state); *\/ */
/*   /\* send_string(state_string); *\/ */

/*   // send F13 (keycode 191) and F14 (keycode 192) when _NUM layer state changes */
/*   // these keypresses correspond to i3 bindcode expressions */
/*   bool old_caps = _caps; */
/*   if (state & (1 << _CAPS)) { */
/*     _caps = true; */
/*   } else { */
/*     _caps = false; */
/*   } */
/*   if (old_caps != _caps) { */
/*     if (_caps) { */
/*       SEND_STRING(SS_LGUI(SS_TAP(X_F14))); */
/*     } else { */
/*       SEND_STRING(SS_LGUI(SS_TAP(X_F13))); */
/*     } */
/*   } */
/*   return state; */
/* }; */
