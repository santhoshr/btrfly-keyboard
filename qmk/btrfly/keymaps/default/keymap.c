#include QMK_KEYBOARD_H

// Fillers to make layering more clear

#define ____ KC_TRNS
#define _BASE 0
#define _SYM 1
#define _NAVNUM 2
#define _EXT 3
#define _FN 4

/*
enum {
  TD_ESC_CAPS = 0
};
*/


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Base (qwerty)
 * +-----------------------------------------+               +-----------------------------------------+
 * |      |   q  |   w  |   e  |   r  |   t  |               |   y  |   u  |   i  |   o  |   p  |      |
 * |------+------+------+------+------+------|               |------+------+------+------+------+------|
 * |      |   a  |   s  |   d  |   f  |   g  |               |   h  |   j  |   k  |   l  |   ;  |      |
 * |------+------+------+------+------+------|               |------+------+------+------+------+------|
 * |      |   z  |   x  |   c  |   v  |   b  |               |   n  |   m  |   ,  |   .  |   /  |      |
 * +------+------+------+------+-------------+               +-------------+------+------+------+------+
 *               |      |      |                                           |      |      |
 *               +-------------+------+                             +------+-------------+
 *                             |      |                             |      |
 *                             +------+                             +------+
 *                                    +-------------+ +-------------+
 *                                    |      |      | |      |      |
 *                                    |------+------| |------+------|
 *                                    |      |      | |      |      |
 *                                    +-------------+ +-------------+
 */
        [_BASE] = LAYOUT( \
        KC_Q, KC_W, KC_E, KC_R, KC_T,                 KC_Y, KC_U, KC_I, KC_O, KC_P, \
        KC_A, KC_S, KC_D, KC_F, KC_G,                 KC_H, KC_J, KC_K, KC_L, KC_SCLN, \
        KC_Z, KC_X, KC_C, KC_V, KC_B,                 KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, \
              KC_MINS, KC_EQL,                                    KC_PGUP, KC_PGDN, \
                            MO(_SYM),                 KC_ENT,\
              TT(_NAVNUM), KC_LSHIFT,                 KC_SPC, TT(_NAVNUM), \
      		    KC_LCTL, KC_LALT,                 KC_ESC, KC_BSPC \
                      ),


        [_SYM] = LAYOUT( \
        KC_CIRC, KC_UNDS, KC_NO, KC_NO, KC_NO,        KC_EXLM, KC_LT, KC_GT, KC_EQL, KC_SCOLON, \
        KC_BSLS, KC_SLSH, KC_AT, KC_NO, KC_NO,        KC_QUES, KC_LPRN, KC_RPRN, KC_MINUS, KC_COLON, \
        KC_HASH, KC_GRV, KC_TILD, KC_DLR, KC_AMPR,             KC_PLUS, KC_PERC, KC_DQT, KC_QUOT, KC_MPLY, \
               KC_TRNS, KC_TRNS,                                        KC_TRNS, KC_TRNS, \
                                      KC_TRNS,        KC_TRNS,
                             KC_TRNS, KC_TRNS,        KC_TRNS, KC_TRNS,
                             KC_TRNS, KC_TRNS,        KC_TRNS, KC_TRNS \
                     ),

        [_NAVNUM] = LAYOUT( \
        KC_ESC, KC_PGUP, KC_UP, KC_PGDN, KC_UNDO,     KC_KP_SLASH, KC_KP_7, KC_KP_8, KC_KP_9, KC_KP_MINUS, \
        KC_HOME, KC_LEFT, KC_DOWN, KC_RIGHT, KC_END,  KC_KP_ASTERISK, KC_KP_4, KC_KP_5, KC_KP_6, KC_KP_PLUS,  \
        KC_NO, KC_TAB, KC_CUT, KC_COPY, KC_PASTE,     KC_KP_0, KC_KP_1, KC_KP_2, KC_KP_3, KC_KP_DOT, \
               KC_TRNS, KC_TRNS,                                        KC_TRNS, KC_TRNS, \
                                          KC_LGUI,    KC_KP_ENTER,                  \
                                 KC_TRNS, KC_TRNS,    KC_TRNS, KC_TRNS, \
                                 KC_TRNS, KC_TRNS,    KC_TRNS, KC_TRNS  \
                      ),

        [_EXT] = LAYOUT( \
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,            KC_PIPE, KC_LBRC, KC_RBRC, KC_NO, KC_NO, \
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,            KC_NO, KC_LCBR, KC_RCBR, KC_NO, KC_NO, \
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,            KC_NO, KC_NO, KC_NO, KC_NO, KC_WWW_REFRESH, \
               KC_NO, KC_NO,                                        KC_NO, KC_NO, \
			  KC_TRNS,                    KC_TRNS,
			  KC_TRNS, KC_TRNS,           KC_TRNS, KC_TRNS,
			  KC_TRNS, KC_TRNS,           KC_TRNS, KC_TRNS \
                     ),

        [_FN] = LAYOUT( \
                     KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,            KC_F12, KC_F7, KC_F8, KC_F9, KC_NO, \
                     KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,            KC_F11, KC_F4, KC_F5, KC_F6, KC_NO, \
                     KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,            KC_F10, KC_F1, KC_F2, KC_F3, KC_NO, \
                            KC_TRNS, KC_TRNS,                                        KC_TRNS, KC_TRNS, \
                                          KC_TRNS,                 KC_TRNS,
                                          KC_TRNS, KC_TRNS,        KC_TRNS, KC_TRNS,
                                          KC_TRNS, KC_TRNS,        KC_TRNS, KC_TRNS \
                      ),

};


void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

/*
qk_tap_dance_action_t tap_dance_actions[] = {
  //Tap once for Esc, twice for Caps Lock
  [TD_ESC_CAPS]  = ACTION_TAP_DANCE_DOUBLE(KC_ESC, KC_CAPS)
// Other declarations would go here, separated by commas, if you have them
};
*/

// Initialize variable holding the binary
// representation of active modifiers.
uint8_t mod_state;
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // Store the current modifier state in the variable for later reference
    mod_state = get_mods();
    switch (keycode) {

    case MO(_SYM):
	{
        static bool key_registered;
        if (record->event.pressed) {
            if (mod_state & MOD_MASK_SHIFT) {
                del_mods(MOD_MASK_SHIFT);
                layer_on(_EXT);
                key_registered = true;
                set_mods(mod_state);
                return false;
            }
        } else {
            if (key_registered) {
                layer_off(_EXT);
                key_registered = false;
                return false;
            }
        }
        }
        return true;
    case MO(_NAVNUM):
	{
        static bool key_registered;
        if (record->event.pressed) {
            if (mod_state & MOD_MASK_SHIFT) {
                del_mods(MOD_MASK_SHIFT);
                layer_on(_FN);
                key_registered = true;
                set_mods(mod_state);
                return false;
            }
        } else {
            if (key_registered) {
                layer_off(_FN);
                key_registered = false;
                return false;
            }
        }
        }
        return true;
    case KC_LSHIFT:
    case KC_RSHIFT:
	{
        static bool key_registered;
        if (record->event.pressed) {
            if (layer_state_is(_SYM) || layer_state_is(_NAVNUM)) {
                del_mods(MOD_MASK_SHIFT);
		if (layer_state_is(_SYM)) {
                  layer_on(_EXT);
                } else if (layer_state_is(_NAVNUM)) {
                  layer_on(_FN);
                }
                key_registered = true;
                set_mods(mod_state);
                return false;
            }
        } else {
            if (key_registered) {
		if (layer_state_is(_SYM)) {
                  layer_off(_EXT);
                } else if (layer_state_is(_NAVNUM)) {
                  layer_off(_FN);
                }
                key_registered = false;
                return false;
            }
        }
        }
        return true;
    case KC_BSPC:
        {
        // Initialize a boolean variable that keeps track
        // of the delete key status: registered or not?
        static bool delkey_registered;
        if (record->event.pressed) {
            // Detect the activation of either shift keys
            if (mod_state & MOD_MASK_SHIFT) {
                // First temporarily canceling both shifts so that
                // shift isn't applied to the KC_DEL keycode
                del_mods(MOD_MASK_SHIFT);
                register_code(KC_DEL);
                // Update the boolean variable to reflect the status of KC_DEL
                delkey_registered = true;
                // Reapplying modifier state so that the held shift key(s)
                // still work even after having tapped the Backspace/Delete key.
                set_mods(mod_state);
                return false;
            }
        } else { // on release of KC_BSPC
            // In case KC_DEL is still being sent even after the release of KC_BSPC
            if (delkey_registered) {
                unregister_code(KC_DEL);
                delkey_registered = false;
                return false;
            }
        }
        // Let QMK process the KC_BSPC keycode as usual outside of shift
        return true;
    }

    }
    return true;
};

