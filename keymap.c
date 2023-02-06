/* Copyright 2018 Carlos Filoteo
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
#include QMK_KEYBOARD_H

#define SC_1 LGUI(LSFT(LCTL(KC_4)))
#define SC_2 LGUI(LSFT(KC_4))
#define CTL_ALT LCTL(KC_LALT)
#define MV_LTAB LCTL(RSFT(KC_TAB))
#define MV_RTAB LCTL(KC_TAB)
#define FWARD LGUI(KC_RBRC)
#define BWARD LGUI(KC_LBRC)
#define ALT_L LALT(KC_LEFT)
#define ALT_R LALT(KC_RIGHT)
#define TGL_A RGUI(KC_SPACE)
#define D_LOCK LCTL(LGUI(KC_Q))

// Virtual display
#define VD_1 LCTL(KC_1)
#define VD_2 LCTL(KC_2)
#define VD_3 LCTL(KC_3)
#define VD_4 LCTL(KC_4)
#define VD_5 LCTL(KC_5)
#define VD_6 LCTL(KC_6)
#define VD_7 LCTL(KC_7)
#define VD_8 LCTL(KC_8)
#define VD_9 LCTL(KC_9)
#define VD_0 LCTL(KC_0)

// Audio
#define V_DN KC__VOLDOWN
#define V_UP KC__VOLUP
#define V_MT KC_AUDIO_MUTE
#define V_PL KC_MPLY


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* Base Layer
   * ,-------------------------------------------------------------------------.
   * | Esc |  Q  |  W  |  E  |  R  |  T  |  Y  |  U  |  I  |  O  |  P  |Bspace |
   * |-------------------------------------------------------------------------+
   * |Tab/L3|  A  |  S  |  D  |  F  |  G  |  H  |  J  |  K  |  L  |  ;  |   '  |
   * |-------------------------------------------------------------------------+
   * | Shift |  Z  |  X  |  C  |  V  |  B  |  N  |  M  |  ,  |  .  |  /  |Sh/En|
   * |-------------------------------------------------------------------------+
   * | Ctrl| Alt | Gui | App |  L2  |   Space   |  L1  | Left| Down|  Up |Right|
   * `-------------------------------------------------------------------------'
   */

LAYOUT(
  LT(4, KC_TAB),KC_Q, KC_W,    KC_E,    KC_R,    KC_T,   KC_Y,   KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
  KC_LCTL,   KC_A,    KC_S,    KC_D,    KC_F,    KC_G,   KC_H,   KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT,
  KC_RSFT,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,   KC_N,   KC_M,    KC_COMM, KC_DOT,  KC_SLSH, SFT_T(KC_QUOTE),
  KC_HOME,  KC_END, CTL_ALT, KC_LGUI, MO(2),   LT(3, KC_SPC),  MO(1),   KC_RGUI, KC_RALT, KC_PGUP,  KC_PGDN
),

  /* FN Layer 1
   * ,-------------------------------------------------------------------------.
   * | ` ~ |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  0  | Delete|
   * |-------------------------------------------------------------------------+
   * |      | RGB |RGBMO|BRT+ |BRT- |     |     |  -  |  =  |  [  |  ]  |  \   |
   * |-------------------------------------------------------------------------+
   * |       | F11 | F12 | F13 | F14 | F15 | F16 | F17 | F18 | F19 | F20 |     |
   * |-------------------------------------------------------------------------+
   * |     |     |     |Capsl|      |          |       | Home| PgDn| PgUp| End |
   * `-------------------------------------------------------------------------'
   */

LAYOUT( /* Right */
  _______, KC_NO,   KC_NO,   KC_GRV,  KC_BSLS, KC_LBRC,  KC_RBRC, KC_MINS, KC_EQL,  KC_NO,   KC_NO,   _______,
  _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
  _______,   SC_1,    SC_2,    KC_NO,   KC_NO,   KC_NO,    KC_NO,   KC_NO,   KC_TRNS, KC_TRNS, KC_TRNS, _______,
  _______, _______, _______, _______, _______,     _______,      _______, _______, _______, _______, _______
),

  /* FN Layer 2
   * ,-------------------------------------------------------------------------.
   * |   ~  |  !  |  @  |  #  |  $  |  %  |  ^  |  &  |  *  |  (  |  )  |Delete|
   * |-------------------------------------------------------------------------+
   * |      |     |     |     |     |     |     |  _  |  +  |  { |  }  |   |   |
   * |-------------------------------------------------------------------------+
   * |       | F1  | F2  | F3  | F4  | F5  | F6  | F7  | F8  | F9  | F10 |     |
   * |-------------------------------------------------------------------------+
   * |     |     |     |Capsl|      |          |       | Home| PgDn| PgUp| End |
   * `-------------------------------------------------------------------------'
   */

LAYOUT( /* Left */
  KC_ESC,   KC_NO,   KC_NO,   KC_TILD, KC_PIPE, KC_LCBR, KC_RCBR, KC_UNDS, KC_PLUS, KC_NO,   KC_NO,  _______,
  _______,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,_______,
  _______,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10, KC_NO,
  _______, _______, _______, _______, _______,     _______,      _______, _______, _______,  KC_F14, KC_F15
),

  /* FN Layer 3
   * ,-------------------------------------------------------------------------.
   * | Esc | Calc|Webhm| Mail| Comp|     |     |     |     |     |PrtSc|       |
   * |-------------------------------------------------------------------------+
   * |      |     |     |     |     |     |     |     |     |     |     |      |
   * |-------------------------------------------------------------------------+
   * |       |    |     |     |     |     |     |     |     |     |     |     |
   * |-------------------------------------------------------------------------+
   * |     |     |     |     |      |          |       |MousL|MousD|MousU|MousR|
   * `-------------------------------------------------------------------------'
   */

LAYOUT( /* Space */
  _______,   KC_NO,   KC_NO,   MV_LTAB, MV_RTAB, KC_NO,   KC_RBRC, ALT_L,   ALT_R,   TGL_A,   V_MT,    V_UP,
  _______,   KC_NO,   KC_NO,   KC_NO,   FWARD,   KC_NO,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, V_PL,    V_DN,
  _______,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   BWARD,   KC_NO,   KC_HOME, KC_END,  KC_PGUP, KC_PGDN, KC_NO,
  _______, _______, _______, _______, _______,     _______,      _______, _______, _______, _______, D_LOCK
),


  /* FN Layer 4
   * ,-------------------------------------------------------------------------.
   * | Esc | Calc|Webhm| Mail| Comp|     |     |     |     |     |PrtSc|       |
   * |-------------------------------------------------------------------------+
   * |      |     |     |     |     |     |     |     |     |     |     |      |
   * |-------------------------------------------------------------------------+
   * |       |    |     |     |     |     |     |     |     |     |     |     |
   * |-------------------------------------------------------------------------+
   * |     |     |     |     |      |          |       |MousL|MousD|MousU|MousR|
   * `-------------------------------------------------------------------------'
   */

LAYOUT( /* Left lower */
  KC_NO,   VD_1,    VD_2,    VD_3,    VD_4,    VD_5,    VD_6,    VD_7,    VD_8,    VD_9,    VD_0,   KC_NO,
  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,  KC_NO,
  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,  RESET,
  _______, _______, _______, _______, _______,     _______,      _______, _______, _______, _______, _______
),
};
