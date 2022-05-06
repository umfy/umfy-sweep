/* Copyright 2015-2017 Jack Humbert
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


enum ferris_layers {
  _QWERTY,
  _COLEMAK,
  _NUMBER,
  _ARROWS,
  _SYMBOL,
  _SYSTEM,
  _MOUSE,
  _FMWARE
};

enum ferris_keycodes {
  QWERTY = SAFE_RANGE,
  COLEMAK,
  NORMAL
};



#define ARROWS TT(_ARROWS)
#define SYMBOL TT(_SYMBOL)
#define SYSTEM TT(_SYSTEM)
#define NUMBER TT(_NUMBER)
#define MOUSE TT(_MOUSE)
#define FMWARE MO(_FMWARE)

#define SFTENTR SFT_T(KC_ENT)

#define RALT_A  RALT_T(KC_A)
#define RALTSC  RALT_T(KC_SCLN)
#define RALT_O  RALT_T(KC_O)
#define ALT__S  ALT_T(KC_S)
#define ALT__L  ALT_T(KC_L)
#define ALT__R  ALT_T(KC_R)
#define ALT__I  ALT_T(KC_I)
#define GUI__G  GUI_T(KC_G)
#define GUI__H  GUI_T(KC_H)
#define GUI__M  GUI_T(KC_M)
#define SFT__D  SFT_T(KC_D)
#define SFT__K  SFT_T(KC_K)
#define SFT__S  SFT_T(KC_S)
#define SFT__E  SFT_T(KC_E)
#define CTL__F  CTL_T(KC_F)
#define CTL__J  CTL_T(KC_J)
#define CTL__T  CTL_T(KC_T)
#define CTL__N  CTL_T(KC_N)

#define ARR__P  LT(_ARROWS, KC_P)

#define CTLRGHT C(KC_RGHT)
#define CTLLEFT C(KC_LEFT)
#define CTL_X C(KC_X)
#define CTL_C C(KC_C)
#define CTL_D C(KC_D)
#define CTL_V C(KC_V)

/* COMBOS */
enum combos {
  sys_spc_NORM,
  sym_spc_NORM,
  fmw_spc_NORM,
  num_spc_NORM
};
const uint16_t PROGMEM sys_spc_norm_combo[] = {SYSTEM, KC_SPC, COMBO_END};
const uint16_t PROGMEM sym_spc_norm_combo[] = {SYMBOL, KC_SPC, COMBO_END};  
const uint16_t PROGMEM fmw_spc_norm_combo[] = {FMWARE, KC_SPC, COMBO_END};  
const uint16_t PROGMEM num_spc_norm_combo[] = {NUMBER, KC_SPC, COMBO_END};  

combo_t key_combos[COMBO_COUNT] = {
  [sys_spc_NORM] = COMBO(sys_spc_norm_combo, NORMAL),
  [sym_spc_NORM] = COMBO(sym_spc_norm_combo, NORMAL),
  [fmw_spc_NORM] = COMBO(fmw_spc_norm_combo, NORMAL),
  [num_spc_NORM] = COMBO(num_spc_norm_combo, NORMAL),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* ## Colemak

|   Q  |   W  |   F  |   P  |   B  |   J  |   L  |   U  |   Y  |   BSP|
|RA(A) | A(R) | S(S) | C(T) | G(G) | G(M) | C(N) | S(E) | A(I) |RA(O) |
|   Z  |   X  |  C   |   D  |   V  |   K  |   H  |   ,  |   .  |   /  |
                     |Symbol|Space |Number|Arrows|
 */

[_COLEMAK] = LAYOUT_split_3x5_2(
    KC_Q,    KC_W,    KC_F,   ARR__P, KC_B,    KC_J,    KC_L,   KC_U,    KC_Y,    KC_BSPC,
    RALT_A,  ALT__R,  SFT__S, CTL__T, GUI__G,  GUI__M,  CTL__N, SFT__E,  ALT__I,  RALT_O,
    KC_Z,    KC_X,    KC_C,   KC_D,   KC_V,    KC_K,    KC_H,   KC_COMM, KC_DOT,  KC_SLSH, 
                              SYMBOL, KC_SPC,  NUMBER,  ARROWS
),

/* ## Qwerty

|   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  |
|RA(A) | A(S) | S(D) | C(F) | G(G) | G(H) | C(J) | S(K) | A(L) |RA(;) |
|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |
                     |Symbol|Space |Number|Arrows|
 */

[_QWERTY] = LAYOUT_split_3x5_2(
    KC_Q,    KC_W,    KC_E,   KC_R,   KC_T,    KC_Y,    KC_U,   KC_I,    KC_O,    KC_P,  
    RALT_A,  ALT__S,  SFT__D, CTL__F, GUI__G,  GUI__H,  CTL__J, SFT__K,  ALT__L,  RALTSC, 
    KC_Z,    KC_X,    KC_C,   KC_V,   KC_B,    KC_N,    KC_M,   KC_COMM, KC_DOT,  KC_SLSH, 
                               SYMBOL, KC_SPC, NUMBER, ARROWS
),


/* ## Arrows

|  esc | bsp  |  del | \\/  | CAPS | PgUp | Home |  Up  | End  | bsp  |
| tab  | Alt  | Shift| Ctrl | Gui  |PgDown| Left | Down |Right | enter|
| enter|      |      |      |      | Ins  | C(<-)| Down |C(->) | esc  |
                     |system| space|mouse | \\/  |
 */

[_ARROWS] = LAYOUT_split_3x5_2(
    KC_ESC, KC_BSPC, KC_DEL,  _______, KC_CAPS, KC_PGUP, KC_HOME, KC_UP,   KC_END,  KC_BSPC,
    KC_TAB, KC_LALT, KC_LSFT, KC_LCTL, KC_LGUI, KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_ENT,
    KC_ENT, CTL_X  , CTL_C  , CTL_D  , CTL_V  , KC_INS , CTLLEFT, KC_DOWN, CTLRGHT, KC_ESC,
                               SYSTEM, _______, MOUSE  , _______
),

/* ## Symbol

|   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   (  |   )  | Bksp |
|  `   |  '   |  "   |  :   |  |   |  *   |  =   |  {   |  }   |  +   | 
|   _  |  [   |  ]   |  ;   |  \   |  /   |  -   |  <   |  >   |  ?   |
|      |      |      | \\/  | space|number|system|      |      |      |
 */

[_SYMBOL] = LAYOUT_split_3x5_2(
     KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_LPRN, KC_RPRN, KC_BSPC,  
     KC_GRV,  KC_QUOT, KC_DQUO, KC_COLN, KC_PIPE, KC_ASTR, KC_EQL,  KC_LCBR, KC_RCBR, KC_PPLS, 
     KC_UNDS, KC_LBRC, KC_RBRC, KC_SCLN, KC_BSLS, KC_SLSH, KC_PMNS, KC_LT,   KC_GT  , KC_QUES, 
                                _______, _______, _______, SYSTEM
),

/* ## Number

|  1   |  2   |  3   |  4   |  5   |   6  |  7   |  8   |  9   | Del  |
|  =   |   -  |   +  |  0   |   ,  |   *  |   4  |  5   |  6   |   +  |
|  ~   |   [  |  ]   |   .  |   ,  |   /  |   1  |  2   |  3   |   -  |
                     |symbol| space| \\/  |mouse |
 */

[_NUMBER] = LAYOUT_split_3x5_2(
     KC_1   , KC_2   , KC_3   , KC_4   , KC_5   , KC_6   , KC_7   , KC_8   , KC_9   , KC_BSPC,  
     KC_EQL,  KC_PMNS, KC_PPLS,  KC_0  , KC_COMM, KC_ASTR, KC_4   , KC_5   , KC_6   , KC_PPLS, 
     KC_TILD, KC_LBRC, KC_RBRC, KC_DOT , KC_COMM, KC_SLSH, KC_1   , KC_2   , KC_3   , KC_PMNS, 
                                _______, _______, _______, MOUSE 
),

/* ## Mouse 

| mb3  |  mb1 |  up  | mb2  |wh up |wh up |  mb1 |  up  | mb2  | mb3  |
|accel | left |down  |right |wh dwn|wh dwn| left |down  |right | accel|
| mb3  | wh l |down  |wh r  |      |      | wh l |down  | wh r | mb3  |
                     |fmware| space| \\/  | \\/  |
 */

 [_MOUSE] = LAYOUT_split_3x5_2(
     KC_BTN3, KC_BTN1, KC_MS_U, KC_BTN2, KC_WH_U, KC_WH_U, KC_BTN1, KC_MS_U, KC_BTN2, KC_BTN3,
     KC_ACL1, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D, KC_WH_D, KC_MS_L, KC_MS_D, KC_MS_R, KC_ACL1, 
     KC_BTN3, KC_WH_L, KC_MS_D, KC_WH_R, XXXXXXX, XXXXXXX, KC_WH_L, KC_MS_D, KC_WH_R, KC_BTN3, 
                                FMWARE, _______, _______, _______
),
/* ## System

|  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  | F10  |
|Pr_Scn| Alt  | Shift| Ctrl | Gui  | calc |my_pc |colemk|qwerty| F11  |
|mute  | vol- | vol+ | bti- | bri+ |      |P_Trac| Play |N_Trac| F12  |
                     | \\/  |      |      |  \\/ |
 */
 


[_SYSTEM] = LAYOUT_split_3x5_2(
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,
    KC_PSCR, KC_LALT, KC_LSFT, KC_LCTL, KC_LGUI, KC_RGUI, KC_RCTL, KC_RSFT, KC_LALT, KC_F11,
    KC_MUTE, KC_VOLD, KC_VOLU, KC_BRID, KC_BRIU, XXXXXXX, KC_MPRV, KC_MPLY, KC_MNXT, KC_F12,
                                _______, _______, FMWARE, _______
),

/* ## FMWare

|Reset |      |      |      |      |      |      |      |      |      |
|eeprom|      |qwerty|colemk|      |      |      |      |      |      |
| debug|      |      |combof|combon|      |      |      |      |      |
                     | \\/  |      | \\/  | \\/  |
 */

[_FMWARE] = LAYOUT_split_3x5_2(
     RESET,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
     EEP_RST, XXXXXXX, QWERTY , COLEMAK, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, 
     DEBUG,   XXXXXXX, XXXXXXX, CMB_OFF, CMB_ON , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, 
                                XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
)

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case QWERTY:
            set_single_persistent_default_layer(_QWERTY);
            return true;

        case COLEMAK:
            set_single_persistent_default_layer(_COLEMAK);
            return true;

        case NORMAL:
            layer_clear();
            return false;
    }
    return true;
}

bool get_tapping_force_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case SFTENTR:
        case RALT_A:
        case RALTSC:
        case RALT_O:
        case ALT__S:
        case ALT__L:
        case ALT__R:
        case ALT__I:
        case GUI__G:
        case GUI__H:
        case GUI__M:
        case SFT__D:
        case SFT__K:
        case SFT__S:
        case SFT__E:
        case CTL__F:
        case CTL__J:
        case CTL__T:
        case CTL__N:
        case ARR__P:
            return true;
        default:
            return false;
    }
}

bool get_ignore_mod_tap_interrupt(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case RALT_A:
        case RALTSC:
        case RALT_O:
        case ALT__S:
        case ALT__L:
        case ALT__R:
        case ALT__I:
        case GUI__G:
        case GUI__H:
        case GUI__M:
        case SFT__D:
        case SFT__K:
        case SFT__S:
        case SFT__E:
        case CTL__F:
        case CTL__J:
        case CTL__T:
        case CTL__N:
        case ARR__P:
            return true;
        default:
            return false;
    }
}
