#include "ergodox_ez.h"
#include "debug.h"
#include "action_layer.h"

#define BASE 0 // default layer(qwerty)
#define SYMB 1 // symbols
#define MDIA 2 // media keys
#define SPEC 3 // macro layer
//Custom swedish macro defines
#define MACRO_SE_AT    M(1) // Macro for @
#define MACRO_SE_LMP   M(2) // Macro for {
#define MACRO_SE_RMP   M(3) // Macro for }
#define MACRO_SE_PIPE  M(4) // Macro for |
#define MACRO_SE_DOL   M(5) // Macro for $
#define MACRO_SE_LPAR  M(6) // Macro for (
#define MACRO_SE_RPAR  M(7) // Macro for )
#define MACRO_SE_GRV   M(8) // Macro for `
#define MACRO_SE_CIRC  M(9) // Macro for ^
#define MACRO_SE_LBR   M(10) // Macro for [
#define MACRO_SE_RBR   M(11) // Macro for ]
#define MACRO_SE_TILD  M(12) // Macro for ~
#define MACRO_SE_AND   M(13) // Macro for &
#define MACRO_SE_BSLSH M(14) // Macro for backslash
#define MACRO_IJ_GEN_M M(15) // Macro intellij for generating methods
#define MACRO_IJ_GEN_C M(16) // Macro intellij for generating methods
#define MACRO_IJ_GENGS M(17) // Macro intellij for generating methods
#define MACRO_IJ_CMNT  M(18) // Macro intellij for comment
#define MACRO_IJ_BCMNT M(19) // Macro intellij for block comment
#define MACRO_IJ_BACK  M(20) // Macro intellij for going back in the visited history
#define MACRO_IJ_FRWRD M(21) // Macro intellij for going forward in the visited history
#define MACRO_IJ_TEST  M(22) // Macro intellij for generating test
#define MACRO_IJ_TGL_T M(23) // Macro intellij for toggling tool views
#define MACRO_IJ_SRND  M(24) // Macro intellij for surround with
#define MACRO_IJ_EXT_M M(25) // Macro intellij for extract method
#define MACRO_IJ_EXT_V M(26) // Macro intellij for extract variable
#define MACRO_IJ_EXT_C M(27) // Macro intellij for extract property
#define MACRO_VM_LN_UP M(28) // Macro vim for moving line up
#define MACRO_VM_LN_DN M(29) // Macro vim for moving line down
#define MACRO_VM_DUPLN M(30) // Macro vim for duplicating current line
#define MACRO_VM_PASTE M(31) // Macro vim for duplicating current line
#define MACRO_IJ_GENAL M(32) // Macro vim for duplicating current line

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Keymap 0: Basic layer
   *
   * ,--------------------------------------------------.           ,--------------------------------------------------.
   * |  Grv   |   1  |   2  |   3  |   4  |   5  | Mute |           |  =   |   6  |   7  |   8  |   9  |   0  |   -    |
   * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
   * |  Tab   |   Q  |   W  |   E  |   R  |   T  | ~L3  |           | ~L3  |   Y  |   U  |   I  |   O  |   P  |   [    |
   * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
   * |  ~L1   |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |; / L2|' / Cmd |
   * |--------+------+------+------+------+------| Hyper|           | Meh  |------+------+------+------+------+--------|
   * | LShift |Z/Ctrl|   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |//Ctrl|        |
   * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
   *   |Alt   |  \   | Lgui | Left | Right|                                       |  Up  | Down | RAlt |   ]  | ~L1  |
   *   `----------------------------------'                                       `----------------------------------'
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
  [BASE] = KEYMAP(  // layer 0 : default
                  // left hand
                  KC_GRV,         KC_1,         KC_2,    KC_3,    KC_4,    KC_5,   KC_MUTE,
                  KC_TAB,         KC_Q,         KC_W,    KC_E,    KC_R,    KC_T,   MO(SPEC),
                  KC_FN1,         KC_A,         KC_S,    KC_D,    KC_F,    KC_G,
                  KC_LSFT,        CTL_T(KC_Z),  KC_X,    KC_C,    KC_V,    KC_B,   ALL_T(KC_NO),
                  KC_LALT,        KC_NUBS,      KC_LGUI, KC_LEFT, KC_RGHT,

                  ALT_T(KC_APP), KC_HOME,
                  KC_DELT,
                  KC_SPC, KC_BSPC, CTL_T(KC_ESC),

                  // right hand
                  KC_EQL,       KC_6,    KC_7,    KC_8,    KC_9,              KC_0,             KC_MINS,
                  MO(SPEC),     KC_Y,    KC_U,    KC_I,    KC_O,              KC_P,             KC_LBRC,
                  KC_H,         KC_J,    KC_K,    KC_L,    LT(MDIA, KC_SCLN), GUI_T(KC_QUOT),
                  MEH_T(KC_NO), KC_N,    KC_M,    KC_COMM, KC_DOT,            CTL_T(KC_SLSH),   KC_BSLS,
                  KC_UP,        KC_DOWN, KC_RALT, KC_RBRC, KC_FN1,

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
   * |        |   %  |   ^  |   [  |   ]  |   ~  |      |           |      |   &  |   1  |   2  |   3  |   \  |        |
   * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
   *   |      |      |      |      |      |                                       |   ~  |    . |   0  |   =  |      |
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
  [SYMB] = KEYMAP(
                  // left hand
                  KC_TRNS,KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_TRNS,
                  KC_TRNS,KC_EXLM,MACRO_SE_AT, MACRO_SE_LMP, MACRO_SE_RMP, MACRO_SE_PIPE,KC_TRNS,
                  KC_TRNS,KC_HASH,MACRO_SE_DOL, MACRO_SE_LPAR, MACRO_SE_RPAR, MACRO_SE_GRV,
                  KC_TRNS,KC_PERC,MACRO_SE_CIRC, MACRO_SE_LBR, MACRO_SE_RBR, MACRO_SE_TILD, KC_TRNS,
                  KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
                  KC_TRNS,KC_TRNS,
                  KC_TRNS,
                  KC_TRNS,KC_TRNS,KC_TRNS,
                  // right hand
                  KC_TRNS, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
                  KC_TRNS, KC_UP,   KC_7,   KC_8,   KC_9,   KC_PAST, KC_F12,
                  KC_DOWN, KC_4,   KC_5,   KC_6,   KC_PPLS, KC_TRNS,
                  KC_TRNS, MACRO_SE_AND, KC_1,   KC_2,   KC_3,   MACRO_SE_BSLSH, KC_TRNS,
                  MACRO_SE_TILD, KC_DOT, KC_0,   KC_EQL, KC_TRNS,
                  KC_TRNS, KC_TRNS,
                  KC_TRNS,
                  KC_TRNS, KC_TRNS, KC_TRNS
                  ),
  /* Keymap 2: Media and mouse keys
   *
   * ,--------------------------------------------------.           ,--------------------------------------------------.
   * |        |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  | F10  |  F11   |
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
  // MEDIA AND MOUSE"
  [MDIA] = KEYMAP(
                  KC_TRNS, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_TRNS,
                  KC_TRNS, KC_TRNS, KC_BTN1, KC_MS_U, KC_BTN2, KC_WH_U, KC_TRNS,
                  KC_TRNS, KC_BTN3, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D,
                  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                  KC_TRNS, KC_TRNS,
                  KC_TRNS,
                  KC_TRNS, KC_TRNS, KC_TRNS,
                  // right hand
                  KC_TRNS,  KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
                  KC_TRNS,  KC_TRNS, KC_MPLY, KC_VOLU, KC_TRNS, KC_TRNS, KC_F12,
                  KC_TRNS, KC_MPRV, KC_VOLD, KC_MNXT, KC_TRNS, KC_TRNS,
                  KC_TRNS,  KC_TRNS, KC_TRNS, KC_MUTE, KC_TRNS, KC_TRNS, KC_TRNS,
                  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                  KC_TRNS, KC_TRNS,
                  KC_TRNS,
                  KC_TRNS, KC_TRNS, KC_WBAK
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
   * |        |      |      |IJCMNT|IJEXTV|IJBCMT|      |           |      |      |IJEXTM|      |      |      |        |
   * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
   *   |      |      |      |IJBACK|IJFWRD|                                       |VIMLNU|VIMLND|      |      |IJGenAll|
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
  [SPEC] = KEYMAP(
                  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                  KC_TRNS, KC_TRNS, KC_TRNS, MACRO_IJ_GEN_C, MACRO_IJ_GENGS, MACRO_IJ_TEST, KC_TRNS,
                  KC_TRNS, KC_TRNS, MACRO_IJ_SRND, MACRO_VM_DUPLN, MACRO_IJ_EXT_C, MACRO_IJ_GEN_M,
                  KC_TRNS, KC_TRNS, KC_TRNS, MACRO_IJ_CMNT, MACRO_IJ_EXT_V, MACRO_IJ_BCMNT, KC_TRNS,
                  KC_TRNS, KC_TRNS, KC_TRNS, MACRO_IJ_BACK, MACRO_IJ_FRWRD,
                  KC_TRNS, KC_TRNS,
                  KC_TRNS,
                  KC_TRNS, KC_TRNS, KC_TRNS,
                  // right hand
                  KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                  KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, MACRO_VM_PASTE, KC_TRNS,
                  MACRO_IJ_TGL_T,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                  KC_TRNS,  KC_TRNS, MACRO_IJ_EXT_M, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                  MACRO_VM_LN_UP,  MACRO_VM_LN_DN, KC_TRNS, KC_TRNS, MACRO_IJ_GENAL,
                  KC_TRNS,  KC_TRNS,
                  KC_TRNS,
                  KC_TRNS, KC_TRNS, KC_WBAK
                  ),
};

enum macro_id {
  SE_AT    = 1,  // Macro for @
  SE_LMP   = 2,  // Macro for {
  SE_RMP   = 3,  // Macro for }
  SE_PIPE  = 4,  // Macro for |
  SE_DOL   = 5,  // Macro for $
  SE_LPAR  = 6, // Macro for (
  SE_RPAR  = 7, // Macro for )
  SE_GRV   = 8, // Macro for `
  SE_CIRC  = 9, // Macro for ^
  SE_LBR   = 10, // Macro for [
  SE_RBR   = 11, // Macro for ]
  SE_TILD  = 12, // Macro for ~
  SE_AND   = 13, // Macro for &
  SE_BSLSH = 14, // Macro for backslash
  IJ_GEN_M = 15, // Macro for intellij generating methods
  IJ_GEN_C = 16, // Macro for intellij generate constructor
  IJ_GENGS = 17, // Macro for intellij generate getters/setters
  IJ_CMNT  = 18, // Macro for intellij comment
  IJ_BCMNT = 19, // Macro for intellij block comment
  IJ_BACK  = 20, // Macro for intellij going back in the visited history
  IJ_FRWRD = 21, // Macro for intellij going forward in the visited history
  IJ_TEST  = 22, // Macro for intellij generating test
  IJ_TGL_T = 23, // Macro for intellij toggling tool views
  IJ_SRND  = 24, // Macro for intellij surround with
  IJ_EXT_M = 25, // Macro for intellij backslash
  IJ_EXT_V = 26, // Macro for intellij backslash
  IJ_EXT_C = 27, // Macro for intellij backslash
  VM_LN_UP = 28, // Macro for vim moving line up
  VM_LN_DN = 29, // Macro for vim moving line down
  VM_DUPLN = 30, // Macro for vim duplicating current line
  VM_PASTE = 31, // Macro for vim paste
  IJ_GENAL = 32  // Macro for intellij generate toString and equals/hashcode
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
  case SE_AT:
    return (event.pressed ? MACRO( D(RALT), T(2), U(RALT), END ) : MACRO_NONE);
  case SE_LMP:
    return (event.pressed ? MACRO( D(RALT), T(7), U(RALT), END ) : MACRO_NONE);
  case SE_RMP:
    return (event.pressed ? MACRO( D(RALT), T(0), U(RALT), END ) : MACRO_NONE);
  case SE_PIPE:
    return (event.pressed ? MACRO( D(RALT), T(NUBS), U(RALT), END ) : MACRO_NONE);
  case SE_DOL:
    return (event.pressed ? MACRO( D(RALT), T(4), U(RALT), END ) : MACRO_NONE);
  case SE_LPAR:
    return (event.pressed ? MACRO( D(LSFT), T(8), U(LSFT), END ) : MACRO_NONE);
  case SE_RPAR:
    return (event.pressed ? MACRO( D(LSFT), T(9), U(LSFT), END ) : MACRO_NONE);
  case SE_GRV:
    return (event.pressed ? MACRO( D(LSFT), T(EQL), T(SPC), U(LSFT),  END ) : MACRO_NONE);
  case SE_CIRC:
    return (event.pressed ? MACRO( D(LSFT), T(RBRC), U(LSFT), T(SPC), END ) : MACRO_NONE);
  case SE_LBR:
    return (event.pressed ? MACRO( D(RALT), T(8), U(RALT), END ) : MACRO_NONE);
  case SE_RBR:
    return (event.pressed ? MACRO( D(RALT), T(9), U(RALT), END ) : MACRO_NONE);
  case SE_TILD:
    return (event.pressed ? MACRO( D(RALT), T(RBRC), U(RALT), T(SPC), END ) : MACRO_NONE);
  case SE_AND:
    return (event.pressed ? MACRO( D(LSFT), T(6), U(LSFT), END ) : MACRO_NONE);
  case SE_BSLSH:
    return (event.pressed ? MACRO( D(RALT), T(MINS), U(RALT), END ) : MACRO_NONE);
  case IJ_GEN_M:
    return (event.pressed ? MACRO( D(LALT), T(INSERT), U(LALT), END ) : MACRO_NONE);
  case IJ_GEN_C:
    return (event.pressed ? MACRO( D(LALT), T(INSERT), U(LALT), T(ENT), END ) : MACRO_NONE);
  case IJ_GENGS:
    return (event.pressed ? MACRO( D(LALT), T(INSERT), U(LALT), T(DOWN), T(DOWN), T(DOWN), T(ENT), END ) : MACRO_NONE);
  case IJ_GENAL:
    return (event.pressed ? MACRO(D(LALT), W(100), T(INSERT), W(100), U(LALT), W(100), T(DOWN), W(100), T(DOWN), W(100), T(DOWN), W(100),
                                  T(DOWN), W(100), T(DOWN), W(100), T(ENT), W(100), T(ENT), W(100),
                                  D(LALT), W(100), T(INSERT), W(100), U(LALT), W(100), T(DOWN), W(100), T(DOWN), W(100), T(DOWN), W(100),
                                  T(DOWN), W(100), T(ENT), W(100), T(ENT), W(100), T(ENT), W(100), T(ENT), W(200),
                                  D(LALT), W(100), T(INSERT), W(100), U(LALT), W(100), T(DOWN), W(100), T(DOWN), W(100), T(DOWN), W(100),
                                  T(ENT), W(100), D(LCTRL), W(100), T(A), W(100), U(LCTRL), W(100), T(ENT), W(100),
                                  D(LALT), W(100), T(INSERT), W(100), U(LALT), W(100),
                                  T(ENT), W(100), D(LCTRL), W(100), T(A), W(100), U(LCTRL), W(100), T(ENT), W(100),
                                  END ) : MACRO_NONE);
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
  }
  return MACRO_NONE;
};

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {

};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

  uint8_t layer = biton32(layer_state);

  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();
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
    //case 4:
    //  ergodox_right_led_1_on();
    //  ergodox_right_led_2_on();
    //  break;
    //case 5:
    //  ergodox_right_led_1_on();
    //  ergodox_right_led_3_on();
    //  break;
    //case 6:
    //  ergodox_right_led_2_on();
    //  ergodox_right_led_3_on();
    //  break;
    //case 7:
    //  ergodox_right_led_1_on();
    //  ergodox_right_led_2_on();
    //  ergodox_right_led_3_on();
    //  break;
  default:
    // none
    break;
  }

};
