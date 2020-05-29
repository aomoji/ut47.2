#include QMK_KEYBOARD_H

enum user_macro {
	LOWER,
	RAISE,
	ADJUST,
};
#define M_LOWER  MACROTAP(LOWER)
#define M_RAISE  MACROTAP(RAISE)
#define M_ADJUST  MACROTAP(ADJUST)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[0] = LAYOUT(	KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC,
					KC_LCTL, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_ENT,
					KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, SFT_T(KC_QUOT),
					KC_NO, KC_CAPS, KC_LALT, KC_LGUI, M_RAISE, LT(3, KC_SPC), M_LOWER, KC_RGUI, RGUI(KC_SPACE), RSFT(KC_TAB), KC_TAB
				),
	[1] = LAYOUT(	LCTL(LGUI(KC_Q)), KC_NO, KC_NO, KC_GRV, KC_BSLS, KC_LBRC, KC_RBRC, KC_MINS, KC_EQL, KC_NO, KC_NO, KC_BSPC,
					KC_TRNS, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_TRNS,
					KC_TRNS, LGUI(LSFT(LCTL(KC_4))), LGUI(LSFT(KC_4)), KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO,
					KC_NO, KC_NO, KC_LALT, KC_LGUI, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO
				),
	[2] = LAYOUT(	KC_ESC, KC_NO, KC_NO, KC_TILD, KC_PIPE, KC_LCBR, KC_RCBR, KC_UNDS, KC_PLUS, KC_NO, KC_NO, RESET,
					KC_TRNS, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_TRNS,
					KC_TRNS, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_NO,
					KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_MPLY, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO
				),
	[3] = LAYOUT(	KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_LANG2, KC_LANG1, LALT(KC_LEFT), LALT(KC_RIGHT), RGUI(KC_SPACE), KC_NO, KC_NO,
					KC_TRNS, KC__VOLUP, KC__VOLDOWN, KC_AUDIO_MUTE, LGUI(KC_RBRC), KC_NO, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_NO, KC_NO,
					KC_TRNS, KC_F15, KC_F14, LGUI(LSFT(KC_C)), KC_NO, LGUI(KC_LBRC), KC_NO, RSFT(KC_TAB),KC_TAB, KC_NO, KC_NO, KC_NO,
					KC_NO, KC_NO, KC_LALT, KC_LGUI, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO
				),
};


const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  dprintf( "record.\n"
           "  event.pressed = %u\n"
           "  tap.count = %u\n"
           "  tap.interrupted = %u\n"
              , record->event.pressed
              , record->tap.count
              , record->tap.interrupted );
  dprintf( "id = %u\n", id );
  dprintf( "opt = %u\n", opt );

  switch(id) {
	case LOWER: {
      return MACRO_TAP_HOLD_LAYER( record, MACRO(TYPE(KC_NO), END), 1 );
    } break;

	case RAISE: {
      return MACRO_TAP_HOLD_LAYER( record, MACRO(TYPE(KC_NO), END), 2 );
    } break;

	case ADJUST: {
      return MACRO_TAP_HOLD_LAYER( record, MACRO(TYPE(KC_SPC), END), 3 );
    } break;
  }
  return MACRO_NONE;
};
