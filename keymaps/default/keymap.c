// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum custom_keycodes {
    TMUX_MACRO,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /*
     * Base Layout
     * ┌────┬───┬───┬───┬───┬───┬────┐                  ┌────┬───┬───┬───┬───┬───┬────┐
     * │ CL │ 1 │ 2 │ 3 │ 4 │ 5 │ 󰐪  │                  │ L1 │ 1 │ 2 │ 3 │ 4 │ 5 │    │
     * ├────┼───┼───┼───┼───┼───┼────┤                  ├────┼───┼───┼───┼───┼───┼────┤
     * │ ~~ │ ; │ , │ . │ P │ Y │   │                  │ L3 │ F │ G │ C │ R │ L │    │
     * ├────┼───┼───┼───┼───┼───┼────┤                  ├────┼───┼───┼───┼───┼───┼────┤
     * │ TG │ A │ O │ E │ U │ I │   │                  │ L4 │ D │ H │ T │ N │ S │    │
     * ├────┼───┼───┼───┼───┼───┼────┤                  ├────┼───┼───┼───┼───┼───┼────┤
     * │ 󰘶  │ ' │ Q │ J │ K │ X │   │                  │ 󰘶  │ B │ M │ W │ V │ Z │    │
     * └────┴───┼───┼───┼───┴───┴────┘                  └────┴───┴───┼───┼───┼───┴────┘
     *          │   │ ? │                                            │ ! │   │
     *          └───┴───┘                                            └───┴───┘
     *
     *          ┌───────┬───┐                               ┌───────┬────┐
     *          │   \   │ 󱁐 │                               │   \   │ 󰌑  │
     *          ├───────┼───┤                               ├───────┼────┤
     *          │ TG(1) │ A │                               │ SPACE │    │
     *          ├───────┼───┤                               ├───────┼────┤
     *          │   *   │ 󰘶 │                               │   *   │ 󰌒  │
     *          └───────┴───┘                               └───────┴────┘
     *                              \: Esc(tap)/Meta(held)
     *                              ___: Space
     *                              *: Tab(tap)/Ctrl(held)
     */

    [0] = LAYOUT(
            TO(0),          KC_1,           KC_2,               KC_3,               KC_4,       KC_5,       KC_PRINT_SCREEN,                        TO(1),              KC_6,           KC_7,                       KC_8,               KC_9,           KC_0,       KC_NO,
            KC_TILDE,       KC_SCLN,        KC_COMMA,           KC_DOT,             KC_P,       KC_Y,       KC_AUDIO_VOL_UP,                        TO(2),              KC_F,           KC_G,                       KC_C,               KC_R,           KC_L,       TMUX_MACRO,
            TG(4),          KC_A,           KC_O,               KC_E,               KC_U,       KC_I,       KC_AUDIO_VOL_DOWN,                      KC_NO,              KC_D,           KC_H,                       KC_T,               KC_N,           KC_S,       KC_NO,
            KC_LEFT_SHIFT,  KC_QUOTE,       KC_Q,               KC_J,               KC_K,       KC_X,       KC_AUDIO_MUTE,                          KC_NO,              KC_B,           KC_M,                       KC_W,               KC_V,           KC_Z,       KC_RIGHT_SHIFT,
                                            LGUI_T(KC_ESCAPE),  LT(3, KC_SPACE),    LCTL_T(KC_TAB),                                                                                     KC_LEFT_ALT,                KC_BACKSPACE,       KC_ENT
    ),

    /*
     *
     * LoL gaming layer
     *
     */
    [1] = LAYOUT(
            KC_TRANSPARENT, KC_1,           KC_2,               KC_3,               KC_4,       KC_5,       KC_P,                                   KC_NO,              KC_NO,          KC_NO,          KC_NO,          KC_NO,      KC_NO,      KC_NO,
            KC_TAB,         KC_Q,           KC_W,               KC_E,               KC_R,       KC_T,       KC_NO,                      KC_NO,          KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,          KC_NO,
            KC_ESCAPE,      KC_A,           KC_S,               KC_D,               KC_F,       KC_G,       KC_NO,                      TO(0),          KC_H,           KC_J,           KC_K,           KC_L,           KC_SCLN,       KC_NO,
            KC_LEFT_SHIFT,  KC_Z,           KC_X,               KC_C,               KC_V,       KC_B,       KC_M,                       KC_NO,          KC_N,           KC_M,           KC_COMMA,       KC_DOT,         KC_SLASH,   KC_NO,
                                            LALT_T(KC_A),       LT(4, KC_SPACE),    KC_LEFT_CTRL,                                                                                                     KC_NO,          KC_NO,      KC_NO
    ),

    /*
     *
     * General gaming layer
     *
     */

   [2] = LAYOUT(
            KC_TRANSPARENT, KC_1,           KC_2,               KC_3,       KC_4,       KC_5,       KC_NO,                      KC_NO,          KC_6,           KC_7,           KC_8,           KC_9,           KC_0,          KC_NO,
            KC_TAB,         KC_Q,           KC_W,               KC_E,       KC_R,       KC_T,       KC_NO,                      KC_NO,          KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,          KC_NO,
            KC_ESCAPE,      KC_A,           KC_S,               KC_D,       KC_F,       KC_G,       KC_NO,                      TO(0),          KC_H,           KC_J,           KC_K,           KC_L,           KC_SCLN,       KC_NO,
            KC_LEFT_SHIFT,  KC_Z,           KC_X,               KC_C,       KC_V,       KC_B,       KC_M,                       KC_NO,          KC_N,           KC_M,           KC_COMMA,       KC_DOT,         KC_SLASH,   KC_NO,
                                            KC_SPACE,           KC_NO,      KC_NO,                                                                                              KC_NO,          KC_NO,          KC_NO
    ),

    /*
     * Special chars (programming)
     *
     * ┌────┬───┬───┬───┬───┬───┬────┐                  ┌────┬───┬───┬───┬───┬───┬────┐
     * │    │ 1 │ 2 │ 3 │ 4 │ 5 │    │                  │ L3 │ 1 │ 2 │ 3 │ 4 │ 5 │    │
     * ├────┼───┼───┼───┼───┼───┼────┤                  ├────┼───┼───┼───┼───┼───┼────┤
     * │    │ ~ │ ` │ & │ [ │ < │    │                  │ L4 │ F │ G │ C │ R │ L │    │
     * ├────┼───┼───┼───┼───┼───┼────┤                  ├────┼───┼───┼───┼───┼───┼────┤
     * │ 00 │ : │ ' │ ( │ { │ * │    │                  │ L5 │ D │ H │ T │ N │ S │    │
     * ├────┼───┼───┼───┼───┼───┼────┤                  ├────┼───┼───┼───┼───┼───┼────┤
     * │ 󰘶  │ . │ - │ # │ ^ │ @ │    │                  │ 󰘶  │ B │ M │ W │ V │ Z │    │
     * └────┴───┼───┼───┼───┴───┴────┘                  └────┴───┴───┼───┼───┼───┴────┘
     *          │   │   │                                            │   │   │
     *          └───┴───┘                                            └───┴───┘
     *
     *          ┌───┬─────┐                                          ┌───┬─────┐
     *          │   │  󰘶  │                                          │   │  󰘶  │
     *          ├───┼─────┤                                          ├───┼─────┤
     *          │   │ Alt │                                          │ E │ Alt │
     *          ├───┼─────┤                                          ├───┼─────┤
     *          │   │ Del │                                          │   │ Del │
     *          └───┴─────┘                                          └───┴─────┘
     *
     */

    [3] = LAYOUT(
            KC_TRANSPARENT,     KC_NO,      KC_NO,          KC_NO,      KC_NO,              KC_NO,              KC_NO,                      KC_NO,          KC_NO,          KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,
            KC_NO,              KC_COMMA,   KC_GRAVE,       KC_AMPR,    KC_LBRC,            KC_LABK,            KC_NO,                      KC_NO,          KC_RABK,        KC_PIPE,    KC_BSLS,    KC_NO,      KC_NO,      KC_NO,
            KC_0,               KC_COLN,    KC_QUOTE,       KC_LPRN,    KC_LCBR,            KC_PLUS,            KC_NO,                      KC_NO,          KC_EQUAL,       KC_RCBR,    KC_RPRN,    KC_SLASH,   KC_SCLN,    KC_DLR,
            KC_TRANSPARENT,     KC_DOT,     KC_MINUS,       KC_HASH,    KC_CIRC,            KC_AT,              KC_NO,                      KC_NO,          KC_PERC,        KC_EXLM,    KC_UNDS,    KC_NO,      KC_NO,      KC_NO,
                                            KC_NO,          KC_NO,      KC_NO,                                                                                              KC_NO,      KC_NO,      KC_NO
    ),

    /*
     *
     * Number + F keys + arrows layer
     *
     */
    [4] = LAYOUT(
            KC_TRANSPARENT,     KC_NO,      KC_NO,              KC_NO,                  KC_NO,              KC_NO,      KC_NO,                                      KC_NO,          KC_NO,          KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,
            KC_NO,              KC_F1,      KC_F2,              KC_F3,                  KC_F4,              KC_F5,      KC_NO,                                      KC_NO,          KC_F6,          KC_F7,      KC_F8,      KC_F9,      KC_F10,     KC_NO,
            KC_TRANSPARENT,     KC_1,       KC_2,               KC_3,                   KC_4,               KC_5,       KC_NO,                                      KC_NO,          KC_6,           KC_7,       KC_8,       KC_9,       KC_0,       KC_NO,
            KC_LEFT_SHIFT,      KC_F11,     KC_NO,              KC_LEFT,                KC_DOWN,            KC_NO,     KC_NO,                                       KC_NO,          KC_NO,          KC_UP,      KC_RIGHT,   KC_F12,     KC_NO,      KC_RIGHT_SHIFT,
                                            KC_TRANSPARENT,     KC_TRANSPARENT,         KC_TRANSPARENT,                                                                                             KC_NO,      KC_NO,      KC_NO
    )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case TMUX_MACRO:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL(SS_TAP(X_B)));
            }
            break;

    }
    return true;
};
