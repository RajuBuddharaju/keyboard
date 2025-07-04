// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include "aliases.h"
#include QMK_KEYBOARD_H
#include "quantum.h"

void keyboard_post_init_user(void) { 

  uprintf("Using firmware version: 0.0.0-alpha-0\n");
  
  #ifdef DEBUG
  
    /* print whether this is the master or slave */ {
      if (is_keyboard_master()) 
        uprintf("This is the master side\n");
      else 
        uprintf("This is the slave side\n");  
    }
    
    // /* Printing the hand this keyboard thinks it is */ {
    //   uint8_t hand = eeconfig_read_hand();
    //   if (hand == EEPROM_HAND_LEFT) 
    //     uprintf("This is the LEFT hand.\n");
    //   else if (hand == EEPROM_HAND_RIGHT)
    //     uprintf("This is the RIGHT hand.\n");
    //   else 
    //     uprintf("Hand is UNKNOWN.\n");
    // }
  #endif
  
}

enum _LAYERS {
    _COLMAK = 0
    , _NUMBERS
    , _NAVIGATION
    , _FUNCTION
    , _MEDIA
};

//
/*
 * So the thump cluster has the ability to switch to a different layer, and the home row acts a modifier when held.
 */
//

/** The keymap layers this keyboard has. */
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /*
     * ┌───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┐
     * │ Q │ W │ F │ P │ G │       │ J │ L │ U │ Y │ ; │
     * ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤
     * │ A │ R │ S │ T │ D │       │ H │ N │ E │ I │ O │
     * ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤
     * │ Z │ X │ C │ V │ B │       │ K │ M │ , │ . │ / │
     * └───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┘
     *           ┌───┐                   ┌───┐
     *           │ 󰁮 ├───┐           ┌───┤ 󰹾 │
     *           └───┤ 󱁐 ├───┐   ┌───┤ 󱞥 ├───┘
     *               └───┤ 󰞔 │   │ 󱊷 ├───┘
     *                   └───┘   └───┘
     */
        [_COLMAK] = LAYOUT_split_3x5_3(
        _SEM_C_,    _Y_,        _U_,        _L_,        _J_,                _B_,        _P_,        _F_,        _W_,        _Q_,
        RGUI_T(_O_), RALT_T(_I_), RCTL_T(_E_), RSFT_T(_N_), _M_,            _G_,        LSFT_T(_T_), LCTL_T(_S_), LALT_T(_R_), LGUI_T(_A_),
        _SLASH_,    _DOT_,      _COMMA_,    _H_,        _K_,                _V_,        _D_,        _C_,        _X_,        _Z_,
         LT(_FUNCTION, _TAB_),      LT(_NUMBERS, _SPACE_),    _ENTER_,                                    _DEL_,    LT(_NAVIGATION, _B_SPC_),   LT(_MEDIA, _ESC_)

    ),

    /*
     * ┌───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┐
     * │ [ │ 7 │ 8 │ 9 │ ] │       │   │   │   │   │   │
     * ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤
     * │ ' │ 4 │ 5 │ 6 │ = │       │   │   │   │   │   │
     * ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤
     * │ ` │ 1 │ 2 │ 3 │ \ │       │   │   │   │   │   │
     * └───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┘
     *           ┌───┐                   ┌───┐
     *           │ 󰁮 ├───┐           ┌───┤ 󰹾 │
     *           └───┤ 0 ├───┐   ┌───┤ 󱞥 ├───┘
     *               └───┤ - │   │ 󱊷 ├───┘
     *                   └───┘   └───┘
     */
        [_NUMBERS] = LAYOUT_split_3x5_3(
        ___,           ___,           ___,           ___,           ___,        _R_BRC_,           _9_,           _8_,           _7_,           _L_BRC_,
        RGUI_T(___), RALT_T(___), RCTL_T(___), RSFT_T(___),           ___,        _EQUAL_,           _6_,           _5_,           _4_,           _QUOTE_,
        ___,           ___,           ___,           ___,           ___,        _B_SLS_,           _3_,           _2_,           _1_,           _GRAVE_,
        _TAB_,      _SPACE_,    _ENTER_,                                    _MINUS_,    _0_,    _ESC_
    ),

        [_NAVIGATION] = LAYOUT_split_3x5_3(
        _UNDO_,     _CUT_,      _COPY_,     _PASTE_,    _REDO_,            ___,           ___,           ___,           ___,           ___,
        _RIGHT_,    _UP_,       _DOWN_,     _LEFT_,     _CAPSLOCK_,            ___,           LSFT_T(___), LCTL_T(___), LALT_T(___), LGUI_T(___),
        _END_,      _PGUP_,     _PGDN_,     _HOME_,     _INSERT_,            ___,           ___,           ___,           ___,           ___,
        _TAB_,      _SPACE_,    _ENTER_,                                 _DEL_,    _B_SPC_,    _ESC_
    ),

        [_FUNCTION] = LAYOUT_split_3x5_3(
        ___,           ___,           ___,           ___,           ___,        _PRTSC_,           _F09_,           _F08_,           _F07_,           _F12_,
        RGUI_T(___), RALT_T(___), RCTL_T(___), RSFT_T(___),           ___,        _SLCK_,           _F06_,           _F05_,           _F04_,           _F11_,
        ___,           ___,           ___,           ___,           ___,        _PAUSE_,           _F03_,           _F02_,           _F01_,           _F10_,
        _TAB_,      _SPACE_,    _ENTER_,                                    _DEL_,    _B_SLS_,    _ESC_
    ),

        [_MEDIA] = LAYOUT_split_3x5_3(
        ___,     ___,      ___,     ___,    ___,            ___,           ___,           ___,           ___,           ___,
        _MNXT_,    _VOLUP_,       _VOLDN_,     _MPRV_,     ___,            ___,           LSFT_T(___), LCTL_T(___), LALT_T(___), LGUI_T(___),
        ___,      ___,     ___,     ___,     ___,            ___,           ___,           ___,           ___,           ___,
        _TAB_,      _MPLY_,    _ENTER_,                                 _DEL_,    _B_SPC_,    _ESC_
    ),

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) uprintf("Keycode pressed: %u\n", keycode);
  else uprintf("Keycode released: %u\n", keycode);
  return true;
}

void matrix_scan_user(void) {
  for (uint8_t row = 0; row < MATRIX_ROWS; row++) {
    for (uint8_t col = 0; col < MATRIX_COLS; col++) {
      if (matrix_is_on(row, col)) {
        uprintf(
          "Current layer: %u. With key at row %u col %u being pressed. That key being %u\n", 
          biton32(layer_state), 
          row, 
          col, 
          keymaps[biton32(layer_state)][row][col]
        );
      }
    }
  }
}
