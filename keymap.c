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
  _COLEMAK,
  _QWERTY,
  _ARROWS,
  _SYMBOL,
  _NUMBER,
  _SYSTEM,
  _MOUSE,
  _FMWARE
};

enum ferris_keycodes {
  COLEMAK = SAFE_RANGE,
  QWERTY,
  NORMAL
};



#define ARROWS TT(_ARROWS)
#define SYMBOL TT(_SYMBOL)
#define SYSTEM TT(_SYSTEM)
#define NUMBER TT(_NUMBER)
#define MOUSE TT(_MOUSE)
#define FMWARE MO(_FMWARE)

#define RALT_R  RALT_T(KC_R)
#define RALT_I  RALT_T(KC_I)
#define RALT_S  ALT_T(KC_S)
#define RALT_L  RALT_T(KC_L)
#define ALT__A  ALT_T(KC_A)
#define ALT__O  ALT_T(KC_O)
#define ALT_SC  ALT_T(KC_SCLN)
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

#define ARRSPC  LT(_ARROWS, KC_SPC)
#define SYSSPC  LT(_SYSTEM, KC_SPC)

#define CTLRGHT C(KC_RGHT)
#define CTLLEFT C(KC_LEFT)
#define CTL_Z C(KC_Z)
#define CTL_Y C(KC_Y)
#define CTL_X C(KC_X)
#define CTL_C C(KC_C)
#define CTL_D C(KC_D)
#define CTL_V C(KC_V)

/* COMBOS */
enum combos {
  wfp_esc,
  luy_caps,
  hcd_enter
};

const uint16_t PROGMEM wfp_esc_combo[] = {KC_W, KC_F, KC_P, COMBO_END};  
const uint16_t PROGMEM luy_caps_combo[] = {KC_L, KC_U, KC_Y, COMBO_END};  
const uint16_t PROGMEM hcd_enter_combo[] = {KC_H, KC_COMM, KC_DOT, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  [wfp_esc] = COMBO(wfp_esc_combo, KC_ESC),
  [luy_caps] = COMBO(luy_caps_combo, KC_CAPS),
  [hcd_enter] = COMBO(hcd_enter_combo, KC_ENT),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* ## Colemak

|   Q  |   W  |   F  |P(arr)|   B  |   J  |   L  |   U  |   Y  |   BSP|
|RA(A) | A(R) | S(S) | C(T) | G(G) | G(M) | C(N) | S(E) | A(I) |RA(O) |
|   Z  |   X  |  C   |   D  |   V  |   K  |   H  |   ,  |   .  |   /  |
                     |Symbol|Space |Number|Arrows|
 */

[_COLEMAK] = LAYOUT_split_3x5_2(
    KC_Q,    KC_W,    KC_F,   KC_P  , KC_B,    KC_J,    KC_L,   KC_U,    KC_Y,    KC_BSPC,
    ALT__A,  RALT_R,  SFT__S, CTL__T, GUI__G,  GUI__M,  CTL__N, SFT__E,  RALT_I,  ALT__O,
    KC_Z,    KC_X,    KC_C,   KC_D,   KC_V,    KC_K,    KC_H,   KC_COMM, KC_DOT,  KC_SLSH, 
                              NUMBER, ARRSPC, ARROWS, SYMBOL
),

/* ## Qwerty

|   Q  |   W  |   E  |R(arr)|   T  |   Y  |   U  |   I  |   O  |   P  |
|RA(A) | A(S) | S(D) | C(F) | G(G) | G(H) | C(J) | S(K) | A(L) |RA(;) |
|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |
                     |Symbol|Space |Number|Arrows|
 */

[_QWERTY] = LAYOUT_split_3x5_2(
    KC_Q,    KC_W,    KC_E,   KC_R  , KC_T,    KC_Y,    KC_U,   KC_I,    KC_O,    KC_P,  
    ALT__A,  RALT_S,  SFT__D, CTL__F, GUI__G,  GUI__H,  CTL__J, SFT__K,  RALT_L,  ALT_SC, 
    KC_Z,    KC_X,    KC_C,   KC_V,   KC_B,    KC_N,    KC_M,   KC_COMM, KC_DOT,  KC_SLSH, 
                                NUMBER, ARRSPC, ARROWS, SYMBOL
),


/* ## Arrows

|  esc | bsp  |  del | \\/  | CAPS | PgUp | Home |  Up  | End  | bsp  |
| tab  | Alt  | Shift| Ctrl | Gui  |PgDown| Left | Down |Right | enter|
| enter|      |      |      |      | Ins  | C(<-)| Down |C(->) | esc  |
                     |system| space|mouse | \\/  |
 */

[_ARROWS] = LAYOUT_split_3x5_2(
    KC_ESC, KC_DEL,  KC_BSPC,  CTL_Z , CTL_Y  , KC_PGUP, KC_HOME, KC_UP,   KC_END,  KC_BSPC,
    KC_TAB, KC_LALT, KC_LSFT, KC_LCTL, KC_LGUI, KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_ENT,
    KC_ENT, CTL_X  , CTL_C  , CTL_D  , CTL_V  , KC_INS , CTLLEFT, KC_DOWN, CTLRGHT, KC_ESC,
                              MOUSE  , KC_SPC , NORMAL , NUMBER
),

/* ## Symbol

|   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   (  |   )  | Bksp |
|  `   |  '   |  "   |  :   |  |   |  *   |  =   |  {   |  }   |  +   | 
|   _  |  [   |  ]   |  ;   |  \   |  /   |  -   |  <   |  >   |  ?   |
|      |      |      | \\/  | space|number|system|      |      |      |
 */

[_SYMBOL] = LAYOUT_split_3x5_2(
     KC_EXLM, KC_LPRN, KC_RPRN, KC_PIPE, KC_PERC, KC_GRV , KC_AMPR, KC_LCBR, KC_RCBR, KC_BSPC,  
     KC_DLR,  KC_UNDS, KC_PMNS, KC_EQL , KC_BSLS, KC_PPLS, KC_COLN, KC_QUOT, KC_DQUO, KC_ENT , 
     KC_AT  , KC_LBRC, KC_RBRC, KC_HASH, KC_SLSH, KC_ASTR, KC_SCLN, KC_LT,   KC_GT  , KC_QUES, 
                                SYSTEM,  KC_SPC , NUMBER, NORMAL
),

/* ## Number

|  ≠   |   ²  |  ³   |  µ   |   °  |   0  |   7  |  8   |  9   | bsp  |
|  ±   |   ,  |   .  |  0   |   ·  |   *  |   4  |  5   |  6   |   +  |
|  ~   |   [  |  ]   |  =   |   ÷  |   /  |   1  |  2   |  3   |   -  |
                     |symbol| space| \\/  |mouse |
 */

[_NUMBER] = LAYOUT_split_3x5_2(
     KC_ESC , KC_LPRN, KC_RPRN ,KC_CIRC, XXXXXXX, KC_0   , KC_7   , KC_8   , KC_9   , KC_BSPC,  
     KC_PERC, KC_COMM, KC_DOT , KC_EQL , KC_TILD, KC_PPLS, KC_4   , KC_5   , KC_6   , KC_PMNS, 
     KC_ENT , KC_LBRC, KC_RBRC, KC_0   , XXXXXXX, KC_ASTR, KC_1   , KC_2   , KC_3   , KC_SLSH, 
                                 NORMAL, KC_SPC , KC_0   , SYSSPC
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
                                 NORMAL, KC_SPC, NORMAL, FMWARE
),
/* ## System

|      |P_Trac| Play |N_Trac|      |      |  F7  |  F8  |  F9  | F10  |
|Pr_Scn| Alt  | Shift| Ctrl | Gui  | Rgui |  F4  |  F5  |  F6  | F11  |
|mute  | vol- | vol+ | bti- | bri+ |      |  F1  |  F2  |  F3  | F12  |
                     | \\/  |      |      |  \\/ |
 */
 


[_SYSTEM] = LAYOUT_split_3x5_2(
    XXXXXXX, KC_MPRV, KC_MPLY, KC_MNXT, XXXXXXX, XXXXXXX, KC_F7,  KC_F8,  KC_F9,  KC_F10,
    KC_PSCR, KC_LALT, KC_LSFT, KC_LCTL, KC_LGUI, XXXXXXX, KC_F4,  KC_F5,  KC_F6,  KC_F11,
    KC_MUTE, KC_VOLD, KC_VOLU, KC_BRID, KC_BRIU, XXXXXXX, KC_F1,  KC_F2,  KC_F3,  KC_F12,
                                NORMAL, KC_SPC , FMWARE, NORMAL
),


/* ## FMWare

|Reset |      |      |      |      |      |      |      |      |      |
|eeprom|      |qwerty|colemk|      |      |      |      |      |      |
| debug|      |      |combof|combon|      |      |      |      |      |
                     | \\/  |      | \\/  | \\/  |
 */

[_FMWARE] = LAYOUT_split_3x5_2(
     RESET,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
     EEP_RST, XXXXXXX, QWERTY , COLEMAK, XXXXXXX, KC_RGUI, KC_RCTL, KC_RSFT, KC_RALT, XXXXXXX, 
     DEBUG,   XXXXXXX, XXXXXXX, CMB_OFF, CMB_ON , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, 
                                XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
)

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case COLEMAK:
            set_single_persistent_default_layer(_COLEMAK);
            return true;

        case QWERTY:
            set_single_persistent_default_layer(_QWERTY);
            return true;

        case NORMAL:
            layer_clear();
            return false;
    }
    return true;
}

bool get_tapping_force_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case RALT_R:
        case RALT_I:
        case RALT_S:
        case RALT_L:
        case ALT__A:
        case ALT__O:
        case ALT_SC:
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
            return true;
        default:
            return false;
    }
}

bool get_ignore_mod_tap_interrupt(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case RALT_R:
        case RALT_I:
        case RALT_S:
        case RALT_L:
        case ALT__A:
        case ALT__O:
        case ALT_SC:
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
            return true;
        default:
            return false;
    }
}
