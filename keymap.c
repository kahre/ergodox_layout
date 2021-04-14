#include "ergodox_ez.h"
#include "action_layer.h"

#define ___ KC_TRNS
//#define D(STUFF) SS_DOWN(STUFF)
//#define U(STUFF) SS_UP(STUFF)
//#define T(STUFF) SS_TAP(X_STUFF)

enum layers {
    BASE, // default layer(qwerty)
    SYMB, // symbols
    MDIA, // media keys
    SPEC, // macro layer
    MOVE, // movement layer
    GAME  // game layer
};

enum custom_keycodes {
#ifdef ORYX_CONFIGURATOR
  SE_GRV = EZ_SAFE_RANGE, // Macro for `
#else
  SE_GRV = SAFE_RANGE,
#endif
  SE_CIRC,             // Macro for ^
  SE_TILD,             // Macro for ~
  IJ_GEN_M,            // Macro for intellij generating methods
  IJ_GEN_C,            // Macro for intellij generate constructor
  IJ_GENGS,            // Macro for intellij generate getters/setters
  IJ_CMNT,             // Macro for intellij comment
  IJ_BCMNT,            // Macro for intellij block comment
  IJ_BACK,             // Macro for intellij going back in the visited history
  IJ_FRWRD,            // Macro for intellij going forward in the visited history
  IJ_TEST,             // Macro for intellij generating test
  IJ_TGL_T,            // Macro for intellij toggling tool views
  IJ_SRND,             // Macro for intellij surround with
  IJ_EXT_M,            // Macro for intellij extract method
  IJ_EXT_V,            // Macro for intellij extract variable
  IJ_EXT_C,            // Macro for intellij extract constant
  VM_LN_UP,            // Macro for vim moving line up
  VM_LN_DN,            // Macro for vim moving line down
  VM_DUPLN,            // Macro for vim duplicating current line
  VM_PASTE,            // Macro for vim paste
  VM_SEMI,             // Macro for vim append semicolon
  VM_TOP,              // Macro for vim append semicolon
  VM_BTM,              // Macro for vim append semicolon
  VM_START,            // Macro for vim append semicolon
  VM_END,              // Macro for vim append semicolon
};

//#undef TAPPING_TERM
//#define TAPPING_TERM 300

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Keymap 0: Basic layer
   *
   * ,---------------------------------------------  -------.           ,----------------------------------------------------.
   * |  Grv   |    1   |    2   |   3  |   4  |   5  | Mute |           |  ´   |   6  |   7  |   8  |   9  |   0    |   +    |
   * |--------+--------+--------+------+------+-------------|           |------+------+------+------+------+--------+--------|
   * |Tab     |    Q   |    W   |   E  |   R  |   T  | ~SPEC|           | ~GAME|   Y  |   U  |   I  |   O  |   P    |   Å    |
   * |--------+--------+--------+------+------+------|      |           |      |------+------+------+------+--------+--------|
   * |ESC/CTRL|A/~MOVE |S/~SYMB |   D  |   F  | G/ALT|------|           |------|   H  |   J  |   K  |   L  |Ö/~MEDIA| Ä/Cmd  |
   * |--------+--------+--------+------+------+------| !SYMB|           | @SYMB|------+------+------+------+--------+--------|
   * | LShift | Z/Ctrl |    X   |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |//Ctrl  | '/Rsft |
   * `--------+--------+--------+------+------+-------------'           `-------------+------+------+------+--------+--------'
   *   |Alt   |  <|>   | Lgui   | Left | Right|                                       |  Up  | Down | Ralt |   ¨    | ~SYMB|
   *   `--------------------------------------'                                       `------------------------------------'
   *                                        ,-------------.       ,--------------.
   *                                        | App  | Home |       | PgUp |  Alt   |
   *                                 ,------|------|------|       |------+--------+------.
   *                                 |      |      | Del  |       | PgDn |        |      |
   *                                 | Space|Backsp|------|       |------|  Tab   |Enter |
   *                                 |      |ace   |Esc/Ct|       | LGui |        |      |
   *                                 `--------------------'       `----------------------'
   */
  // If it accepts an argument (i.e, is a function), it doesn't need KC_.
  // Otherwise, it needs KC_*
  [BASE] = LAYOUT_ergodox(  // layer 0 : default
                  // left hand
                  KC_GRV,          KC_1,           KC_2,           KC_3,    KC_4,    KC_5,   KC_MUTE,
                  KC_TAB,          KC_Q,           KC_W,           KC_E,    KC_R,    KC_T,   MO(SPEC),
                  CTL_T(KC_ESC),   LT(MOVE, KC_A), LT(SYMB, KC_S), KC_D,    KC_F,    ALT_T(KC_G),
                  KC_LSFT,         CTL_T(KC_Z),    KC_X,           KC_C,    KC_V,    KC_B,   TG(SYMB),
                  KC_LALT,         KC_NUBS,        KC_LGUI,        KC_LEFT, KC_RGHT,

                                                                               ALT_T(KC_APP), KC_HOME,
                                                                                              KC_DELT,
								       KC_SPC,       KC_BSPC, KC_LCTL,



		  // right hand
                  KC_EQL,       KC_6,    KC_7,    KC_8,    KC_9,    KC_0,              KC_MINS,
                  DF(GAME),     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,              KC_LBRC,
                                KC_H,    KC_J,    KC_K,    KC_L,    LT(MDIA, KC_SCLN), RGUI_T(KC_QUOT),
                  OSL(SYMB),    KC_N,    KC_M,    KC_COMM, KC_DOT,  RCTL_T(KC_SLSH),   RSFT_T(KC_BSLS),
                                         KC_UP,   KC_DOWN, KC_RALT, KC_RBRC,           MO(SYMB),

                  KC_PGUP, KC_LALT,
                  KC_PGDN,
                  KC_LGUI, KC_TAB, KC_ENT
                    ),
  /* Keymap 1: Symbol Layer
   *
   * ,--------------------------------------------------.           ,--------------------------------------------------.
   * |        |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
   * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
   * |        |   !  |   @  |   {  |   }  |   |  |      |           |      |   Up |   7  |   8  |   9  |   *  |   F12  |
   * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
   * |        |   #  |   $  |   (  |   )  |   `  |------|           |------| Down |   4  |   5  |   6  |   +  |        |
   * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
   * |        |   %  |   ^  |   [  |   ]  |   ~  |      |           |      |   &  |   1  |   2  |   3  |   \  | CAPSLCK|
   * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
   *   |      |      |      |      |      |                                       |   0  |   0  |   .  |   =  |   ~  |
   *   `----------------------------------'                                       `----------------------------------'
   *                                        ,-------------.       ,-------------.
   *                                        |      |      |       |      |      |
   *                                 ,------|------|------|       |------+------+------.
   *                                 |      |      |      |       |      |      |      |
   *                                 |      |      |------|       |------|      |      |
   *                                 |      |      |      |       |      |      |      |
   *                                 `--------------------'       `--------------------'
   */
  // SYMBOLS
  [SYMB] = LAYOUT_ergodox(
                  // left hand
                  ___, KC_F1,   KC_F2,      KC_F3,      KC_F4,      KC_F5,         ___,
                  ___, KC_EXLM, RALT(KC_2), RALT(KC_7), RALT(KC_0), RALT(KC_NUBS), ___,
                  ___, KC_HASH, RALT(KC_4), LSFT(KC_8), LSFT(KC_9), SE_GRV,
                  ___, KC_PERC, SE_CIRC,     RALT(KC_8), RALT(KC_9), SE_TILD,        ___,
                  ___, ___,     ___,        ___,        ___,

		                                                              ___, ___,
                                                                                   ___,
                                                                         ___, ___, ___,


		  // right hand
                  ___, KC_F6,      KC_F7,  KC_F8,  KC_F9,  KC_F10,        KC_F11,
                  ___, KC_UP,      KC_7,   KC_8,   KC_9,   KC_PAST,       KC_F12,
                       KC_DOWN,    KC_4,   KC_5,   KC_6,   KC_PPLS,       ___,
                  ___, LSFT(KC_6), KC_1,   KC_2,   KC_3,   RALT(KC_MINS), KC_CAPSLOCK,
                                   KC_0,    KC_0,   KC_DOT, KC_EQL,       SE_TILD,

                  ___, ___,
                  ___,
                  ___, ___, ___
                  ),
  /* Keymap 2: Media and mouse keys
   *
   * ,--------------------------------------------------.           ,--------------------------------------------------.
   * | PRNTSC |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  | F10  |  F11   |
   * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
   * |        |      | Lclk | MsUp | Rclk |ScrlUp|      |           |      |      | Play |VolUp |      |      |  F12   |
   * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
   * |        | Mclk |MsLeft|MsDown|MsRght|ScrlDn|------|           |------|      | Prev |VolDn | Next |      |        |
   * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
   * |        |      |      |      |      |      |      |           |      |      |      | Mute |      |      |        |
   * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
   *   |      |      |      |      |      |                                       |      |      |      |      |      |
   *   `----------------------------------'                                       `----------------------------------'
   *                                        ,-------------.       ,-------------.
   *                                        |      |      |       |      |      |
   *                                 ,------|------|------|       |------+------+------.
   *                                 |      |      |      |       |      |      |Brwser|
   *                                 |      |      |------|       |------|      |Back  |
   *                                 |      |      |      |       |      |      |      |
   *                                 `--------------------'       `--------------------'
   */
  // MEDIA AND MOUSE
  [MDIA] = LAYOUT_ergodox(
                  KC_PSCR, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   ___,
                  ___,     ___,     KC_BTN1, KC_MS_U, KC_BTN2, KC_WH_U, ___,
                  ___,     KC_BTN3, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D,
                  ___,     ___,     ___,     ___,     ___,     ___,     ___,
                  ___,     ___,     ___,     ___,     ___,

		                                                   ___, ___,
                                                                        ___,
                                                              ___, ___, ___,


		  // right hand
                  ___, KC_F6, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
                  ___, ___,   KC_MPLY, KC_VOLU, ___,     ___,     KC_F12,
                       ___,   KC_MPRV, KC_VOLD, KC_MNXT, ___,     ___,
                  ___, ___,   ___,     KC_MUTE, ___,     ___,     ___,
                              ___,     ___,     ___,     ___,     ___,

		  ___, ___,
                  ___,
                  ___, ___, KC_WBAK
                  ),

  /* Keymap 3: Specials and macro layer
   *
   * ,--------------------------------------------------.           ,--------------------------------------------------.
   * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
   * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
   * |        |      |      |IJGenC|IJGeSe| IJTst|      |           |      |      |      |      |      |VIMPST|        |
   * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
   * |        |      |IJSrnd|VIMDUP|IJExtC| IJGen|------|           |------|IJTGLV|      |      |      |      |        |
   * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
   * |        |      |      |IJCMNT|IJEXTV|IJBCMT|      |           |      |      |IJEXTM|VISEMI|      |      |        |
   * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
   *   |      |      |      |IJBACK|IJFWRD|                                       |VIMLNU|VIMLND|      |      |        |
   *   `----------------------------------'                                       `------------------------------------'
   *                                        ,-------------.       ,-------------.
   *                                        |      |      |       |      |      |
   *                                 ,------|------|------|       |------+------+------.
   *                                 |      |      |      |       |      |      |      |
   *                                 |      |      |------|       |------|      |Brwsr |
   *                                 |      |      |      |       |      |      |  Bck |
   *                                 `--------------------'       `--------------------'
   */
  // Specials / Macro layer
  [SPEC] = LAYOUT_ergodox(
                  ___, ___, ___,       ___,        ___,        ___,        ___,
                  ___, ___, ___,       IJ_GEN_C, IJ_GENGS, IJ_TEST,  ___,
                  ___, ___, IJ_SRND, VM_DUPLN, IJ_EXT_C, IJ_GEN_M,
                  ___, ___, ___,       IJ_CMNT,  IJ_EXT_V, IJ_BCMNT, ___,
                  ___, ___, ___,       IJ_BACK,  IJ_FRWRD,

                                                                      ___, ___,
                                                                           ___,
                                                                 ___, ___, ___,


		  // right hand
                  ___, ___,        ___,        ___,        ___, ___,        ___,
                  ___, ___,        ___,        ___,        ___, VM_PASTE, ___,
                       IJ_TGL_T, ___,        ___,        ___, ___,        ___,
                  ___, ___,        IJ_EXT_M, VM_SEMI,  ___, ___,        ___,
                                   VM_LN_UP, VM_LN_DN, ___, ___,        ___,

		  ___, ___,
                  ___,
                  ___, ___, KC_WBAK
                  ),
  /* Keymap 4: Movement/VIM utility layer
   *
   * ,--------------------------------------------------.           ,--------------------------------------------------.
   * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
   * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
   * |        |      |      |      |      |      |      |           |      |VISTRT|VIBTM |VITOP |VIEND |      |        |
   * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
   * |        |      |      |      |      |      |------|           |------| Left | Down |  Up  |Right |      |        |
   * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
   * |        |      |      |      |      |      |      |           |      |      |      |VISEMI|      |      |        |
   * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
   *   |      |      |      |      |      |                                       |      |      |      |      |        |
   *   `----------------------------------'                                       `------------------------------------'
   *                                        ,-------------.       ,-------------.
   *                                        |      |      |       |      |      |
   *                                 ,------|------|------|       |------+------+------.
   *                                 |      |      |      |       |      |      |      |
   *                                 |      |      |------|       |------|      |      |
   *                                 |      |      |      |       |      |      |      |
   *                                 `--------------------'       `--------------------'
   */
  // Specials / Macro layer
  [MOVE] = LAYOUT_ergodox(
                  ___, ___, ___, ___, ___, ___, ___,
                  ___, ___, ___, ___, ___, ___, ___,
                  ___, ___, ___, ___, ___, ___,
                  ___, ___, ___, ___, ___, ___, ___,
                  ___, ___, ___, ___, ___,

		                           ___, ___,
 		                                ___,
                                      ___, ___, ___,


		  // right hand
                  ___, ___,        ___,      ___,       ___,      ___, ___,
                  ___, VM_START, VM_BTM, VM_TOP,  VM_END, ___, ___,
                       KC_LEFT,    KC_DOWN,  KC_UP,     KC_RGHT,  ___, ___,
                  ___, ___,        ___,      VM_SEMI, ___,      ___, ___,
                                   ___,      ___,       ___,      ___, ___,

		  ___, ___,
                  ___,
                  ___, ___, ___
                  ),

  /* Keymap 4: Gaming specific base layer, currently not doing much.
   *
   * ,--------------------------------------------------.           ,--------------------------------------------------.
   * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
   * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
   * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
   * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
   * |        |   A  |   S  |      |      |      |------|           |------|      |      |      |      |      |        |
   * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
   * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
   * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
   *   |      |      |      |      |      |                                       |      |      |      |      |        |
   *   `----------------------------------'                                       `------------------------------------'
   *                                        ,-------------.       ,-------------.
   *                                        |      |      |       |      |      |
   *                                 ,------|------|------|       |------+------+------.
   *                                 |      |      |      |       |      |      |      |
   *                                 |      |      |------|       |------|      |      |
   *                                 |      |      |      |       |      |      |      |
   *                                 `--------------------'       `--------------------'
   */
  [GAME] = LAYOUT_ergodox(
                  ___, ___,  ___,  ___, ___, ___, ___,
                  ___, ___,  ___,  ___, ___, ___, ___,
                  ___, KC_A, KC_S, ___, ___, KC_G,
                  ___, ___,  ___,  ___, ___, ___, ___,
                  ___, ___,  ___,  ___, ___,

		                             ___, ___,
                                                  ___,
                                        ___, ___, ___,


		  // right hand
                  ___,      ___, ___, ___, ___, ___, ___,
                  DF(BASE), ___, ___, ___, ___, ___, ___,
                  ___,      ___, ___, ___, ___, ___,
                  ___,      ___, ___, ___, ___, ___, ___,
                  ___,      ___, ___, ___, ___,

		  ___, ___,
                  ___,
                  ___, ___, ___
                  )
};

//const uint16_t PROGMEM fn_actions[] = {
//  [1] = ACTION_LAYER_MOMENTARY(SYMB),  // FN1 - Momentary Layer 1 (Symbols)
//};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if(!record->event.pressed)
        return true;
    switch(keycode) {
        case SE_GRV:
            SEND_STRING( SS_DOWN(X_LSFT) SS_TAP(X_EQL) SS_TAP(X_SPC) SS_UP(X_LSFT)  );
            return false;
        case SE_CIRC:
            SEND_STRING( SS_DOWN(X_LSFT) SS_TAP(X_RBRC) SS_UP(X_LSFT) SS_TAP(X_SPC) );
            return false;
        case SE_TILD:
            SEND_STRING( SS_DOWN(X_RALT) SS_TAP(X_RBRC) SS_UP(X_RALT) SS_TAP(X_SPC) );
            return false;
        case IJ_GEN_M:
            SEND_STRING( SS_DOWN(X_LALT) SS_TAP(X_INSERT) SS_UP(X_LALT) );
            return false;
        case IJ_GEN_C:
            SEND_STRING( SS_DOWN(X_LALT) SS_TAP(X_INSERT) SS_UP(X_LALT) SS_TAP(X_ENT) );
            return false;
        case IJ_GENGS:
            SEND_STRING( SS_DOWN(X_LALT) SS_TAP(X_INSERT) SS_UP(X_LALT) SS_TAP(X_DOWN) SS_TAP(X_DOWN) SS_TAP(X_DOWN) SS_TAP(X_ENT) );
            return false;
        case IJ_CMNT:
            SEND_STRING( SS_DOWN(X_LCTRL) SS_TAP(X_PSLS) SS_UP(X_LCTRL) );
            return false;
        case IJ_BCMNT:
            SEND_STRING( SS_DOWN(X_LCTRL) SS_DOWN(X_LSFT) SS_TAP(X_PSLS) SS_UP(X_LSFT) SS_UP(X_LCTRL) );
            return false;
        case IJ_BACK:
            SEND_STRING( SS_DOWN(X_LCTRL) SS_DOWN(X_LALT) SS_TAP(X_LEFT) SS_UP(X_LCTRL) SS_UP(X_LALT) );
            return false;
        case IJ_FRWRD:
            SEND_STRING( SS_DOWN(X_LCTRL) SS_DOWN(X_LALT) SS_TAP(X_RGHT) SS_UP(X_LCTRL) SS_UP(X_LALT) );
            return false;
        case IJ_TEST:
            SEND_STRING( SS_DOWN(X_LCTRL) SS_DOWN(X_LSFT) SS_TAP(X_T) SS_UP(X_LCTRL) SS_UP(X_LSFT) );
            return false;
        case IJ_TGL_T:
            SEND_STRING( SS_DOWN(X_LCTRL) SS_DOWN(X_LSFT) SS_TAP(X_F12) SS_UP(X_LCTRL) SS_UP(X_LSFT) );
            return false;
        case IJ_SRND:
            SEND_STRING( SS_DOWN(X_LCTRL) SS_DOWN(X_LALT) SS_TAP(X_T) SS_UP(X_LCTRL) SS_UP(X_LALT) );
            return false;
        case IJ_EXT_M:
            SEND_STRING( SS_DOWN(X_LCTRL) SS_DOWN(X_LALT) SS_TAP(X_M) SS_UP(X_LCTRL) SS_UP(X_LALT) );
            return false;
        case IJ_EXT_V:
            SEND_STRING( SS_DOWN(X_LCTRL) SS_DOWN(X_LALT) SS_TAP(X_V) SS_UP(X_LCTRL) SS_UP(X_LALT) );
            return false;
        case IJ_EXT_C:
            SEND_STRING( SS_DOWN(X_LCTRL) SS_DOWN(X_LALT) SS_TAP(X_C) SS_UP(X_LCTRL) SS_UP(X_LALT) );
            return false;
        case VM_LN_UP:
            SEND_STRING( SS_TAP(X_ESC) SS_TAP(X_D) SS_TAP(X_D) SS_TAP(X_UP) SS_DOWN(X_LSFT) SS_TAP(X_P) SS_UP(X_LSFT) );
            return false;
        case VM_LN_DN:
            SEND_STRING( SS_TAP(X_ESC) SS_TAP(X_D) SS_TAP(X_D) SS_TAP(X_P) );
            return false;
        case VM_DUPLN:
            SEND_STRING( SS_TAP(X_ESC) SS_TAP(X_Y) SS_TAP(X_Y) SS_TAP(X_P) );
            return false;
        case VM_PASTE:
            SEND_STRING( SS_TAP(X_ESC) SS_DOWN(X_LSFT) SS_TAP(X_2) SS_TAP(X_BSLS) SS_TAP(X_P) SS_UP(X_LSFT) );
            return false;
        case VM_SEMI:
            SEND_STRING( SS_TAP(X_ESC) SS_DOWN(X_RALT) SS_TAP(X_4) SS_UP(X_RALT) SS_TAP(X_A) SS_DOWN(X_LSFT) SS_TAP(X_COMM) SS_UP(X_LSFT) );
            return false;
        case VM_TOP:
            SEND_STRING( SS_TAP(X_ESC) SS_TAP(X_G) SS_TAP(X_G) );
            return false;
        case VM_BTM:
            SEND_STRING( SS_TAP(X_ESC) SS_DOWN(X_LSFT) SS_TAP(X_G) SS_TAP(X_G) SS_UP(X_LSFT) );
            return false;
        case VM_START:
            SEND_STRING( SS_TAP(X_ESC) SS_TAP(X_0) );
            return false;
        case VM_END:
            SEND_STRING( SS_TAP(X_ESC) SS_DOWN(X_LSFT) SS_TAP(X_A) SS_UP(X_LSFT) SS_TAP(X_ESC) );
            return false;
  }
  return true;
};

// Runs just one time when the keyboard initializes.
void keyboard_post_init_user(void) {
#ifdef RGBLIGHT_COLOR_LAYER_0
  rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif
};

// Runs whenever there is a layer state change.
layer_state_t layer_state_set_user(layer_state_t state) {
  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();

  uint8_t layer = get_highest_layer(state);
  switch (layer) {
      case 0:
        #ifdef RGBLIGHT_COLOR_LAYER_0
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
        #endif
        break;
      case 1:
        ergodox_right_led_1_on();
        #ifdef RGBLIGHT_COLOR_LAYER_1
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_1);
        #endif
        break;
      case 2:
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_2
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_2);
        #endif
        break;
      case 3:
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_3
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_3);
        #endif
        break;
      case 4:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_4
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_4);
        #endif
        break;
      case 5:
        ergodox_right_led_1_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_5
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_5);
        #endif
        break;
      case 6:
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_6
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
        #endif
        break;
      case 7:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_7
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_7);
        #endif
        break;
      default:
        break;
    }

  return state;
};
