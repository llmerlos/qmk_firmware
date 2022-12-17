#include QMK_KEYBOARD_H
#include "anotterkb.h"
#include "keymap_spanish.h"

enum custom_keycodes {
   KVM1 = SAFE_RANGE,
   KVM2,
   ES_LLGM,
   MW_SWAP,
   MW_QUIT,
   MW_TILD,
   MW_SCRS,
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
  _AOTLAYOUT, // This is actually the default
  _RAISE,
  _LOWER,
  _ADJUST,
  _MOUSE,
};

void keyboard_post_init_user(void) {
   default_layer_set(1 << _AOTLAYOUT);
}

layer_state_t layer_state_set_user(layer_state_t state) {
   return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

#define AOTLAY DF(_AOTLAYOUT)
#define ALPHAS MO(_AOTLAYOUT)
#define GAMING DF(_GAMING)
#define GAMNUM MO(_GAMNUM)
#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define MOUSE TG(_MOUSE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
   [_GAMING] = LAYOUT_split_4x5(
//         +--------+--------+--------+--------+--------+                 +--------+--------+--------+--------+--------+
            KC_TAB,  ES_Q,    ES_W,    ES_E,    ES_R,                      ES_Y,    ES_U,    ES_I,    ES_O,    ES_P,    
//+--------+--------+--------+--------+--------+--------+                 +--------+--------+--------+--------+--------+--------+
   KC_ESC,  KC_LSFT, ES_A,    ES_S,    ES_D,    ES_F,                      ES_H,    ES_J,    ES_K,    ES_L,    ES_NTIL, KC_ENT,
//+--------+--------+--------+--------+--------+--------+                 +--------+--------+--------+--------+--------+--------+
   KC_B,    KC_LCTL, ES_Z,    ES_X,    ES_C,    ES_V,                      ES_N,    ES_M,    ES_COMM, ES_DOT,  ES_MINS, KC_LGUI,
//+--------+--------+--------+--------+--------+--------+                 +--------+--------+--------+--------+--------+--------+
                                       KC_LALT, KC_SPC,  GAMNUM,  LOWER,   KC_BSPC, ALPHAS
//                                    +--------+--------+--------+--------+--------+--------+
  ),

   [_GAMNUM] = LAYOUT_split_4x5(
//         +--------+--------+--------+--------+--------+                 +--------+--------+--------+--------+--------+
            ES_0,    ES_1,    ES_T,    ES_4,    ES_7,                      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
//+--------+--------+--------+--------+--------+--------+                 +--------+--------+--------+--------+--------+--------+
   KC_TRNS, KC_TRNS, ES_2,    ES_G,    ES_5,    ES_8,                      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, A(KC_F4),
//+--------+--------+--------+--------+--------+--------+                 +--------+--------+--------+--------+--------+--------+
   KC_TRNS, KC_TRNS, ES_3,    ES_B,    ES_6,    ES_9,                      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
//+--------+--------+--------+--------+--------+--------+                 +--------+--------+--------+--------+--------+--------+
                                       KC_TRNS, KC_TRNS, GAMNUM,  KC_TRNS, KC_TRNS, KC_TRNS
//                                    +--------+--------+--------+--------+--------+--------+
  ),

   [_AOTLAYOUT] = LAYOUT_split_4x5(
//         +--------+--------+--------+--------+--------+                 +--------+--------+--------+--------+--------+
            ES_SCLN, ES_W,    ES_F,    ES_P,    ES_B,                      ES_J,    ES_L,    ES_U,    ES_Y,    ES_Q,
//+--------+--------+--------+--------+--------+--------+                 +--------+--------+--------+--------+--------+--------+
   KC_TAB,  ES_A,    ES_R,    ES_S,    ES_T,    ES_G,                      ES_M,    ES_N,    ES_E,    ES_I,    ES_O,    KC_ENT,
//+--------+--------+--------+--------+--------+--------+                 +--------+--------+--------+--------+--------+--------+
   KC_LCTL, ES_Z,    ES_X,    ES_C,    ES_D,    ES_V,                      ES_K,    ES_H,    ES_COMM, ES_DOT,  ES_SLSH, KC_RALT,
//+--------+--------+--------+--------+--------+--------+                 +--------+--------+--------+--------+--------+--------+
                                       KC_LGUI, KC_SPC,  RAISE,   LOWER,   KC_BSPC, KC_RSFT
//                                    +--------+--------+--------+--------+--------+--------+
  ),

   [_RAISE] = LAYOUT_split_4x5(
//         +--------+--------+--------+--------+--------+                 +--------+--------+--------+--------+--------+
            MW_QUIT, KC_HOME, KC_UP,   KC_END,  ES_FORD,                   ES_BSLS, ES_LBRC, ES_RBRC, ES_HASH, ES_IQUE,
//+--------+--------+--------+--------+--------+--------+                 +--------+--------+--------+--------+--------+--------+
   KC_TRNS, KC_ESC,  KC_LEFT, KC_DOWN, KC_RGHT, ES_MORD,                   ES_AT,   ES_LPRN, ES_RPRN, ES_COLN, ES_DQUO,  KC_TRNS,
//+--------+--------+--------+--------+--------+--------+                 +--------+--------+--------+--------+--------+--------+
   KC_TRNS, CW_TOGG, ES_GRV,  ES_CCED, ES_ACUT, ES_DIAE,                   KC_DEL,  ES_LCBR, ES_RCBR, ES_DLR,  ES_QUES,  KC_TRNS,
//+--------+--------+--------+--------+--------+--------+                 +--------+--------+--------+--------+--------+--------+
                                       KC_TRNS, KC_TRNS, RAISE,   LOWER,   KC_TRNS, KC_TRNS
//                                    +--------+--------+--------+--------+--------+--------+
  ),

   [_LOWER] = LAYOUT_split_4x5(
//         +--------+--------+--------+--------+--------+                 +--------+--------+--------+--------+--------+
            ES_IEXL, ES_LABK, ES_RABK, ES_AMPR, ES_CIRC,                   ES_LLGM, ES_7,    ES_8,    ES_9,    ES_COMM,
//+--------+--------+--------+--------+--------+--------+                 +--------+--------+--------+--------+--------+--------+
   KC_TRNS, ES_QUOT, ES_MINS, ES_PLUS, ES_EQL,  ES_PIPE,                   ES_NTIL, ES_4,    ES_5,    ES_6,    ES_0,    KC_TRNS,
//+--------+--------+--------+--------+--------+--------+                 +--------+--------+--------+--------+--------+--------+
   KC_TRNS, ES_EXLM, ES_PERC, ES_ASTR, ES_UNDS, MW_TILD,                   ES_DOT,  ES_1,    ES_2,    ES_3,    ES_SLSH, KC_TRNS,
//+--------+--------+--------+--------+--------+--------+                 +--------+--------+--------+--------+--------+--------+
                                       KC_TRNS, KC_TRNS, RAISE,   LOWER,   KC_TRNS, KC_TRNS
//                                    +--------+--------+--------+--------+--------+--------+
  ),  

   [_ADJUST] = LAYOUT_split_4x5(
//         +--------+--------+--------+--------+--------+                 +--------+--------+--------+--------+--------+
            KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                     KC_PGUP, GAMING,  DSC_DFN, DSC_EXT, MW_SWAP, 
//+--------+--------+--------+--------+--------+--------+                 +--------+--------+--------+--------+--------+--------+
   KC_TRNS, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,                    MOUSE,   AOTLAY,  DSC_MUT, DSC_SSC, MW_SCRS, KC_TRNS,
//+--------+--------+--------+--------+--------+--------+                 +--------+--------+--------+--------+--------+--------+
   KC_TRNS, KC_F11,  KC_F12,  KC_PSCR, KC_SCRL, KC_PAUS,                   KC_PGDN, KVM1,    KVM2,    KC_CAPS, KC_INS,  KC_TRNS,
//+--------+--------+--------+--------+--------+--------+                 +--------+--------+--------+--------+--------+--------+
                                       KC_TRNS, KC_TRNS, RAISE,   LOWER,   KC_TRNS, KC_TRNS
//                                    +--------+--------+--------+--------+--------+--------+
  ),

   [_MOUSE] = LAYOUT_split_4x5(
//         +--------+--------+--------+--------+--------+                 +--------+--------+--------+--------+--------+
            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, KC_WH_U, KC_MS_U, KC_WH_D, MW_SWAP,
//+--------+--------+--------+--------+--------+--------+                 +--------+--------+--------+--------+--------+--------+
   KC_TAB,  KC_DEL,  KC_LSFT, KC_RCTL, KC_RSFT, KC_RWIN,                   XXXXXXX, KC_MS_L, KC_MS_D, KC_MS_R, MW_SCRS, KC_ENT,
//+--------+--------+--------+--------+--------+--------+                 +--------+--------+--------+--------+--------+--------+
   KC_LCTL, KC_ESC,  KC_LALT, KC_C,    KC_RALT, KC_V,                      XXXXXXX, KC_WH_L, KC_BTN3, KC_WH_R, XXXXXXX, KC_RALT,
//+--------+--------+--------+--------+--------+--------+                 +--------+--------+--------+--------+--------+--------+
                                       KC_LWIN, KC_SPC,  MOUSE,   KC_BTN1, KC_BSPC, KC_BTN2
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
   case ES_LLGM:
      if (record->event.pressed) {
         tap_code16(S(ES_3));

         if (is_caps_word_on())
            tap_code16(S(ES_L));
         else 
            tap_code16(ES_L);

      } else {
      }
      break;
   case MW_SWAP:
      if (record->event.pressed) {
         is_mac = !is_mac;
      } else {
      }
      break;
   case MW_QUIT:
      if (record->event.pressed) {
         if (is_mac) {
            tap_code16(G(KC_Q));
         } else {
            tap_code16(A(KC_F4));
         }
      } else {
      }
      break;
   case MW_TILD:
      if (record->event.pressed) {
         if (is_mac) {
            tap_code16(ALGR(ES_NTIL));
         } else {
            tap_code16(ALGR(ES_4));
         }
      } else {
      }
      break;
   case MW_SCRS:
      if (record->event.pressed) {
         if (is_mac) {
            tap_code16(G(S(KC_4)));
         } else {
            tap_code16(G(S(KC_S)));
         }
      } else {
      }
      break;
   }
   return true;
};

bool caps_word_press_user(uint16_t keycode) {
   switch (keycode) {
      // Keycodes that continue Caps Word, with shift applied.
      case KC_A ... KC_Z:
      case ES_CCED:
      case ES_NTIL:
      case ES_MINS:
      case ES_LLGM:
         add_weak_mods(MOD_BIT(KC_LSFT));  // Apply shift to next key.
         return true;

      // Keycodes that continue Caps Word, without shifting.
      case KC_1 ... KC_0:
      case KC_BSPC:
      case KC_DEL:
      case ES_UNDS:
      case ES_GRV:
      case ES_ACUT:
      case ES_CIRC:
      case KC_UP:
      case KC_DOWN:
      case KC_RGHT:
      case KC_LEFT:
         return true;

      default:
         return false;  // Deactivate Caps Word.
   }
}
