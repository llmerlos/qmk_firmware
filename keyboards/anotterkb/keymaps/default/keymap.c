#include QMK_KEYBOARD_H
#include "anotterkb.h"

enum custom_keycodes {
   KVM1 = SAFE_RANGE,
   KVM2,
};

// Keybinds for Discord
#define DSC_MUT S(C(KC_F9))
#define DSC_DFN S(C(KC_F10))
#define DSC_SSC S(C(KC_F11))
#define DSC_EXT S(C(KC_F12))

//Layer Definitions
enum layer_number {
  _GAMING = 0,
  _GAMNUM,
  _BASE, // This is actually the default
  _LOWER,
  _RAISE,
  _FUNCT,
  _ADJUST,
};

void keyboard_post_init_user(void) {
   default_layer_set(1 << _BASE);
}

layer_state_t layer_state_set_user(layer_state_t state) {
   return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

#define AOTLAY DF(_BASE)
#define ALPHAS MO(_BASE)
#define GAMING DF(_GAMING)
#define GAMNUM MO(_GAMNUM)
#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define FUNCL MO(_FUNCT)

#define D_MUT S(C(KC_F9))
#define D_SIL S(C(KC_F11))
#define D_SHS S(C(KC_F10))

#define VD_L   C(G(KC_LEFT))
#define VD_R   C(G(KC_RGHT))
#define VD_U   G(KC_TAB)

#define E_IEX   ALGR(KC_1)
#define E_IQM   ALGR(KC_SLSH)

#define E_NN    ALGR(KC_N)
#define E_CC    ALGR(KC_C)
#define E_LL    ALGR(S(KC_SCLN))
#define E_OF    ALGR(KC_2)
#define E_OM    ALGR(KC_3)
#define E_EUR   ALGR(KC_5)
#define E_PND   ALGR(KC_4)
#define E_DEG   ALGR(KC_SCLN)

#define E_AOB   ALGR(KC_GRV)
#define E_ATC   ALGR(KC_QUOT)
#define E_ACF   ALGR(KC_6)
#define E_ADI   ALGR(S(KC_DQT))
#define E_ATI   ALGR(S(KC_GRV))

#define E_SMT   ALGR(S(KC_M))
#define E_SLI   ALGR(KC_BSLS)
#define MS_RALT   OSM(MOD_RALT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
   [_GAMING] = LAYOUT_split_4x5(
//         +--------+--------+--------+--------+--------+                 +--------+--------+--------+--------+--------+
            KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    
//+--------+--------+--------+--------+--------+--------+                 +--------+--------+--------+--------+--------+--------+
   KC_ESC,  KC_LSFT, KC_A,    KC_S,    KC_D,    KC_F,                      KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT,
//+--------+--------+--------+--------+--------+--------+                 +--------+--------+--------+--------+--------+--------+
   KC_B,    KC_LCTL, KC_Z,    KC_X,    KC_C,    KC_V,                      KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_LGUI,
//+--------+--------+--------+--------+--------+--------+                 +--------+--------+--------+--------+--------+--------+
                                       KC_LALT, KC_SPC,  GAMNUM,  LOWER,   KC_BSPC, ALPHAS
//                                    +--------+--------+--------+--------+--------+--------+
  ),

   [_GAMNUM] = LAYOUT_split_4x5(
//         +--------+--------+--------+--------+--------+                 +--------+--------+--------+--------+--------+
            KC_TRNS, KC_1,    KC_TRNS, KC_2,    KC_3,                      VD_U,    KC_TRNS, KC_UP,   KC_TRNS, VD_R,
//+--------+--------+--------+--------+--------+--------+                 +--------+--------+--------+--------+--------+--------+
   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_G,                      VD_L,    KC_LEFT, KC_DOWN, KC_RGHT, KC_TRNS, A(KC_F4),
//+--------+--------+--------+--------+--------+--------+                 +--------+--------+--------+--------+--------+--------+
   FUNCL,   KC_TRNS, KC_4,    KC_5,    KC_6,    KC_B,                      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
//+--------+--------+--------+--------+--------+--------+                 +--------+--------+--------+--------+--------+--------+
                                       KC_TRNS, KC_TRNS, GAMNUM,  KC_TRNS, KC_TRNS, KC_TRNS
//                                    +--------+--------+--------+--------+--------+--------+
  ),

   [_BASE] = LAYOUT_split_4x5(
//         +--------+--------+--------+--------+--------+                 +--------+--------+--------+--------+--------+
            KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
//+--------+--------+--------+--------+--------+--------+                 +--------+--------+--------+--------+--------+--------+
   KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                      KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT,
//+--------+--------+--------+--------+--------+--------+                 +--------+--------+--------+--------+--------+--------+
   KC_LCTL, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                      KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_LALT,
//+--------+--------+--------+--------+--------+--------+                 +--------+--------+--------+--------+--------+--------+
                                       KC_LGUI, KC_SPC,  RAISE,   LOWER,   KC_BSPC, KC_RSFT
//                                    +--------+--------+--------+--------+--------+--------+
  ),

   [_LOWER] = LAYOUT_split_4x5(
//         +--------+--------+--------+--------+--------+                 +--------+--------+--------+--------+--------+
            KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                   E_AOB,   KC_7,    KC_8,    KC_9,    E_ATC,
//+--------+--------+--------+--------+--------+--------+                 +--------+--------+--------+--------+--------+--------+
   KC_TRNS, KC_TILD, KC_MINS, KC_PLUS, KC_EQL,  E_PND,                     E_ADI,   KC_4,    KC_5,    KC_6,    KC_0,    KC_TRNS,
//+--------+--------+--------+--------+--------+--------+                 +--------+--------+--------+--------+--------+--------+
   KC_TRNS, KC_GRV,  KC_SLSH, KC_ASTR, KC_UNDS, E_EUR,                     E_NN,    KC_1,    KC_2,    KC_3,    FUNCL,   KC_TRNS,
//+--------+--------+--------+--------+--------+--------+                 +--------+--------+--------+--------+--------+--------+
                                       KC_TRNS, KC_TRNS, RAISE,   LOWER,   KC_TRNS, KC_TRNS
//                                    +--------+--------+--------+--------+--------+--------+
  ),  

   [_RAISE] = LAYOUT_split_4x5(
//         +--------+--------+--------+--------+--------+                 +--------+--------+--------+--------+--------+
            VD_L,    KC_HOME, KC_UP,   KC_END,  VD_U,                      KC_CIRC, KC_AMPR, KC_DQT,  KC_LPRN, KC_RPRN,
//+--------+--------+--------+--------+--------+--------+                 +--------+--------+--------+--------+--------+--------+
   KC_TRNS, KC_ESC,  KC_LEFT, KC_DOWN, KC_RGHT, VD_R,                      KC_LCBR, KC_LBRC, KC_RBRC, KC_RCBR, KC_QUOT,  KC_TRNS,
//+--------+--------+--------+--------+--------+--------+                 +--------+--------+--------+--------+--------+--------+
   KC_TRNS, FUNCL,   KC_PGDN, E_CC,    KC_PGUP, KC_DEL,                    KC_BSLS, KC_PIPE, KC_LABK, KC_RABK, KC_QUES,  KC_TRNS,
//+--------+--------+--------+--------+--------+--------+                 +--------+--------+--------+--------+--------+--------+
                                       KC_TRNS, KC_TRNS, RAISE,   LOWER,   KC_TRNS, KC_TRNS
//                                    +--------+--------+--------+--------+--------+--------+
  ),

   [_FUNCT] = LAYOUT_split_4x5(
//         +--------+--------+--------+--------+--------+                 +--------+--------+--------+--------+--------+
            QK_BOOT, KC_F7,    KC_F8,   KC_F9,  KC_F12,                    KC_F12,  KC_F7,    KC_F8,   KC_F9,   QK_BOOT,    
//+--------+--------+--------+--------+--------+--------+                 +--------+--------+--------+--------+--------+--------+
   KC_TRNS, KC_F13,  KC_F4,    KC_F5,   KC_F6,  KC_F11,                    KC_F11,  KC_F4,    KC_F5,   KC_F6,   KC_F13,  KC_TRNS,
//+--------+--------+--------+--------+--------+--------+                 +--------+--------+--------+--------+--------+--------+
   KC_TRNS, KC_TRNS, KC_F1,    KC_F2,   KC_F3,  KC_F10,                    KC_F10,  KC_F1,    KC_F2,   KC_F3,   KC_TRNS, KC_TRNS,
//+--------+--------+--------+--------+--------+--------+                 +--------+--------+--------+--------+--------+--------+
                                       KC_TRNS, KC_TRNS, RAISE,   LOWER,   KC_TRNS, KC_TRNS
//                                    +--------+--------+--------+--------+--------+--------+
  ),

   [_ADJUST] = LAYOUT_split_4x5(
//         +--------+--------+--------+--------+--------+                 +--------+--------+--------+--------+--------+
            E_IEX,   E_ACF,   E_LL,    D_SHS,   KC_KB_VOLUME_UP,           KC_MPRV, KC_INS,  KC_PSCR, KC_SCRL, KC_PAUS, 
//+--------+--------+--------+--------+--------+--------+                 +--------+--------+--------+--------+--------+--------+
   KC_TRNS, KC_CAPS, E_OM,    E_OF,    D_MUT,   KC_KB_VOLUME_DOWN,         KC_MSTP, AOTLAY,  GAMING,  MS_RALT, KC_APP,  KC_TRNS,
//+--------+--------+--------+--------+--------+--------+                 +--------+--------+--------+--------+--------+--------+
   KC_RALT, KC_NUBS, E_ATI,   E_DEG,   D_SIL,   KC_KB_MUTE,                KC_MNXT, KVM1,    KVM2,    XXXXXXX, E_IQM,   KC_RCTL,
//+--------+--------+--------+--------+--------+--------+                 +--------+--------+--------+--------+--------+--------+
                                       KC_LSFT, KC_TRNS, RAISE,   LOWER,   KC_TRNS, KC_RGUI
//                                    +--------+--------+--------+--------+--------+--------+
  ),
};

volatile bool is_mac = true;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
   switch (keycode) {
   case KVM1:
      if (record->event.pressed) {
         tap_code(KC_RCTL);
         tap_code(KC_RCTL);
         tap_code(KC_1);
      } else {
      }
      break;
   case KVM2:
      if (record->event.pressed) {
         tap_code(KC_RCTL);
         tap_code(KC_RCTL);
         tap_code(KC_2);
      } else {
      }
      break;
   }
   return true;
};