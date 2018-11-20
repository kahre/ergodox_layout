#include "ergodox_ez.h"
#include "debug.h"
#include "action_layer.h"

#define ___ KC_TRNS

#define BASE 0 // default layer(qwerty)
#define SYMB 1 // symbols
#define MDIA 2 // media keys
#define SPEC 3 // macro layer
#define MOVE 4 // movement layer
#define GAME 5 // game layer

// Custom macro defines
#define M_GRV      M(1)  // Macro for `
#define M_CIRC     M(2)  // Macro for ^
#define M_TILD     M(3)  // Macro for ~
#define M_IJ_GEN_M M(4)  // Macro intellij for generating methods
#define M_IJ_GEN_C M(5)  // Macro intellij for generating constructor 
#define M_IJ_GENGS M(6)  // Macro intellij for generating getters and setters 
#define M_IJ_CMNT  M(7)  // Macro intellij for comment
#define M_IJ_BCMNT M(8)  // Macro intellij for block comment
#define M_IJ_BACK  M(9)  // Macro intellij for going back in the visited history
#define M_IJ_FRWRD M(10) // Macro intellij for going forward in the visited history
#define M_IJ_TEST  M(11) // Macro intellij for generating test
#define M_IJ_TGL_T M(12) // Macro intellij for toggling tool views
#define M_IJ_SRND  M(13) // Macro intellij for surround with
#define M_IJ_EXT_M M(14) // Macro intellij for extract method
#define M_IJ_EXT_V M(15) // Macro intellij for extract variable
#define M_IJ_EXT_C M(16) // Macro intellij for extract property
#define M_VM_LN_UP M(17) // Macro vim for moving line up
#define M_VM_LN_DN M(18) // Macro vim for moving line down
#define M_VM_DUPLN M(19) // Macro vim for duplicating current line
#define M_VM_PASTE M(20) // Macro vim paste
#define M_VM_SEMI  M(21) // Macro for vim append semicolon
#define M_VM_TOP   M(22) // Macro for vim go to top 
#define M_VM_BTM   M(23) // Macro for vim go to bottom
#define M_VM_START M(24) // Macro for vim go to start of line 
#define M_VM_END   M(25) // Macro for vim go to end of line 

#undef TAPPING_TERM
#define TAPPING_TERM 300

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Keymap 0: Basic layer
   *
   * ,---------------------------------------------  -------.           ,----------------------------------------------------.
   * |  Grv   |    1   |    2   |   3  |   4  |   5  | Mute |           |  ´   |   6  |   7  |   8  |   9  |   0    |   +    |
   * |--------+--------+--------+------+------+-------------|           |------+------+------+------+------+--------+--------|
   * |Tab     |    Q   |    W   |   E  |   R  |   T  | ~SPEC|           | ~GAME|   Y  |   U  |   I  |   O  |   P    |   Å    |
   * |--------+--------+--------+------+------+------|      |           |      |------+------+------+------+--------+--------|
   * |ESC/CTRL|A/~MOVE |S/~SYMB |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |Ö/~MEDIA| Ä/Cmd  |
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
                  CTL_T(KC_ESC),   LT(MOVE, KC_A), LT(SYMB, KC_S), KC_D,    KC_F,    KC_G,
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
                                         KC_UP,   KC_DOWN, KC_RALT, KC_RBRC,           KC_FN1,

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
   *   |      |      |      |      |      |                                       |   ~  |   0  |   .  |   =  |      |
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
                  ___, KC_HASH, RALT(KC_4), LSFT(KC_8), LSFT(KC_9), M_GRV,
                  ___, KC_PERC, M_CIRC,     RALT(KC_8), RALT(KC_9), M_TILD,        ___,
                  ___, ___,     ___,        ___,        ___,
                  
		                                                              ___, ___,
                                                                                   ___, 
                                                                         ___, ___, ___,
                  
									 
		  // right hand
                  ___, KC_F6,      KC_F7,  KC_F8,  KC_F9,  KC_F10,        KC_F11,
                  ___, KC_UP,      KC_7,   KC_8,   KC_9,   KC_PAST,       KC_F12,
                       KC_DOWN,    KC_4,   KC_5,   KC_6,   KC_PPLS,       ___,
                  ___, LSFT(KC_6), KC_1,   KC_2,   KC_3,   RALT(KC_MINS), KC_CAPSLOCK,
                                   M_TILD, KC_0,   KC_DOT, KC_EQL,        ___,

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
                  ___, ___, ___,       M_IJ_GEN_C, M_IJ_GENGS, M_IJ_TEST,  ___,
                  ___, ___, M_IJ_SRND, M_VM_DUPLN, M_IJ_EXT_C, M_IJ_GEN_M,
                  ___, ___, ___,       M_IJ_CMNT,  M_IJ_EXT_V, M_IJ_BCMNT, ___,
                  ___, ___, ___,       M_IJ_BACK,  M_IJ_FRWRD,

                                                                      ___, ___,
                                                                           ___,
                                                                 ___, ___, ___,
                  
								 
		  // right hand
                  ___, ___,        ___,        ___,        ___, ___,        ___,
                  ___, ___,        ___,        ___,        ___, M_VM_PASTE, ___,
                       M_IJ_TGL_T, ___,        ___,        ___, ___,        ___,
                  ___, ___,        M_IJ_EXT_M, M_VM_SEMI,  ___, ___,        ___,
                                   M_VM_LN_UP, M_VM_LN_DN, ___, ___,        ___,
                  
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
                  ___, M_VM_START, M_VM_BTM, M_VM_TOP,  M_VM_END, ___, ___,
                       KC_LEFT,    KC_DOWN,  KC_UP,     KC_RGHT,  ___, ___,
                  ___, ___,        ___,      M_VM_SEMI, ___,      ___, ___,
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
                  ___, KC_A, KC_S, ___, ___, ___,
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


enum macro_id {
  SE_GRV   = 1, // Macro for `
  SE_CIRC  = 2, // Macro for ^
  SE_TILD  = 3,  // Macro for ~
  IJ_GEN_M = 4,  // Macro for intellij generating methods
  IJ_GEN_C = 5,  // Macro for intellij generate constructor
  IJ_GENGS = 6,  // Macro for intellij generate getters/setters
  IJ_CMNT  = 7,  // Macro for intellij comment
  IJ_BCMNT = 8,  // Macro for intellij block comment
  IJ_BACK  = 9,  // Macro for intellij going back in the visited history
  IJ_FRWRD = 10, // Macro for intellij going forward in the visited history
  IJ_TEST  = 11, // Macro for intellij generating test
  IJ_TGL_T = 12, // Macro for intellij toggling tool views
  IJ_SRND  = 13, // Macro for intellij surround with
  IJ_EXT_M = 14, // Macro for intellij extract method
  IJ_EXT_V = 15, // Macro for intellij extract variable
  IJ_EXT_C = 16, // Macro for intellij extract constant
  VM_LN_UP = 17, // Macro for vim moving line up
  VM_LN_DN = 18, // Macro for vim moving line down
  VM_DUPLN = 19, // Macro for vim duplicating current line
  VM_PASTE = 20, // Macro for vim paste
  VM_SEMI = 21, // Macro for vim append semicolon
  VM_TOP = 22, // Macro for vim append semicolon
  VM_BTM = 23, // Macro for vim append semicolon
  VM_START = 24, // Macro for vim append semicolon
  VM_END = 25, // Macro for vim append semicolon
};

const uint16_t PROGMEM fn_actions[] = {
  [1] = ACTION_LAYER_MOMENTARY(SYMB),  // FN1 - Momentary Layer 1 (Symbols)
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  keyevent_t event = record->event;
  // MACRODOWN only works in this function
  switch(id) {
  case 0:
    if (record->event.pressed) {
      register_code(KC_RSFT);
    } else {
      unregister_code(KC_RSFT);
    }
    break;
  case SE_GRV:
    return (event.pressed ? MACRO( D(LSFT), T(EQL), T(SPC), U(LSFT),  END ) : MACRO_NONE);
  case SE_CIRC:
    return (event.pressed ? MACRO( D(LSFT), T(RBRC), U(LSFT), T(SPC), END ) : MACRO_NONE);
  case SE_TILD:
    return (event.pressed ? MACRO( D(RALT), T(RBRC), U(RALT), T(SPC), END ) : MACRO_NONE);
  case IJ_GEN_M:
    return (event.pressed ? MACRO( D(LALT), T(INSERT), U(LALT), END ) : MACRO_NONE);
  case IJ_GEN_C:
    return (event.pressed ? MACRO( D(LALT), T(INSERT), U(LALT), T(ENT), END ) : MACRO_NONE);
  case IJ_GENGS:
    return (event.pressed ? MACRO( D(LALT), T(INSERT), U(LALT), T(DOWN), T(DOWN), T(DOWN), T(ENT), END ) : MACRO_NONE);
  case IJ_CMNT:
    return (event.pressed ? MACRO( D(LCTRL), T(PSLS), U(LCTRL), END ) : MACRO_NONE);
  case IJ_BCMNT:
    return (event.pressed ? MACRO( D(LCTRL), D(LSFT), T(PSLS), U(LSFT), U(LCTRL), END ) : MACRO_NONE);
  case IJ_BACK:
    return (event.pressed ? MACRO( D(LCTRL), D(LALT), T(LEFT), U(LCTRL), U(LALT), END ) : MACRO_NONE);
  case IJ_FRWRD:
    return (event.pressed ? MACRO( D(LCTRL), D(LALT), T(RGHT), U(LCTRL), U(LALT), END ) : MACRO_NONE);
  case IJ_TEST:
    return (event.pressed ? MACRO( D(LCTRL), D(LSFT), T(T), U(LCTRL), U(LSFT), END ) : MACRO_NONE);
  case IJ_TGL_T:
    return (event.pressed ? MACRO( D(LCTRL), D(LSFT), T(F12), U(LCTRL), U(LSFT), END ) : MACRO_NONE);
  case IJ_SRND:
    return (event.pressed ? MACRO( D(LCTRL), D(LALT), T(T), U(LCTRL), U(LALT), END ) : MACRO_NONE);
  case IJ_EXT_M:
    return (event.pressed ? MACRO( D(LCTRL), D(LALT), T(M), U(LCTRL), U(LALT), END ) : MACRO_NONE);
  case IJ_EXT_V:
    return (event.pressed ? MACRO( D(LCTRL), D(LALT), T(V), U(LCTRL), U(LALT), END ) : MACRO_NONE);
  case IJ_EXT_C:
    return (event.pressed ? MACRO( D(LCTRL), D(LALT), T(C), U(LCTRL), U(LALT), END ) : MACRO_NONE);
  case VM_LN_UP:
    return (event.pressed ? MACRO( T(ESC), T(D), T(D), T(UP), D(LSFT), T(P), U(LSFT), END ) : MACRO_NONE);
  case VM_LN_DN:
    return (event.pressed ? MACRO( T(ESC), T(D), T(D), T(P), END ) : MACRO_NONE);
  case VM_DUPLN:
    return (event.pressed ? MACRO( T(ESC), T(Y), T(Y), T(P), END ) : MACRO_NONE);
  case VM_PASTE:
    return (event.pressed ? MACRO( T(ESC), D(LSFT), T(2), T(BSLS), T(P), U(LSFT), END ) : MACRO_NONE);
  case VM_SEMI:
    return (event.pressed ? MACRO( T(ESC), D(RALT), T(4), U(RALT), T(A), D(LSFT), T(COMM), U(LSFT), END ) : MACRO_NONE);
  case VM_TOP:
    return (event.pressed ? MACRO( T(ESC), T(G), T(G), END ) : MACRO_NONE);
  case VM_BTM:
    return (event.pressed ? MACRO( T(ESC), D(LSFT), T(G), T(G), U(LSFT), END ) : MACRO_NONE);
  case VM_START:
    return (event.pressed ? MACRO( T(ESC), T(0), END ) : MACRO_NONE);
  case VM_END:
    return (event.pressed ? MACRO( T(ESC), D(LSFT), T(A), U(LSFT), T(ESC), END ) : MACRO_NONE);
  }
  return MACRO_NONE;
};

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {

};

bool caps = false;

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

  uint8_t layer = biton32(layer_state);

  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();
  if(caps) {
    ergodox_right_led_1_on();
    ergodox_right_led_2_on();
  } else {
    switch (layer) {
    case SYMB: // 1
      ergodox_right_led_1_on();
      break;
    case MDIA: // 2
      ergodox_right_led_2_on();
      break;
    case SPEC: // 3
      ergodox_right_led_3_on();
      break;
    case MOVE: // 4
      ergodox_right_led_2_on();
      ergodox_right_led_3_on();
      break;
      //case 5:
      //  ergodox_right_led_1_on();
      //  ergodox_right_led_3_on();
      //  break;
      //case 6:
      //  ergodox_right_led_1_on();
      //  ergodox_right_led_2_on();
      //  ergodox_right_led_3_on();
      //  break;
    default:
      // none
      break;
    }
  }
};

void led_set_user(uint8_t led) {
  caps = led & (1 << USB_LED_CAPS_LOCK);
}

