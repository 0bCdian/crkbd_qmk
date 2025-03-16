#include QMK_KEYBOARD_H
#if __has_include("keymap.h")
    #include "keymap.h"
#endif

// Tap dance declarations

// Define a type for the tap dance states
typedef enum {
    TD_NONE,
    TD_SINGLE_TAP,
    TD_SINGLE_HOLD,
    TD_DOUBLE_TAP
} td_state_t;

typedef struct {
    bool is_press_action;
    td_state_t state;
} td_tap_t;

// Function to determine current tap dance state
td_state_t cur_dance(tap_dance_state_t *state) {
    if (state->count == 1) {
        if (!state->pressed) return TD_SINGLE_TAP;
        else return TD_SINGLE_HOLD;
    } else if (state->count == 2) return TD_DOUBLE_TAP;
    else return TD_NONE;
}

// Initialize tap state
static td_tap_t key_tap_state = {
    .is_press_action = true,
    .state = TD_NONE
};

void thumb_3(tap_dance_state_t *state, void *user_data) {
    key_tap_state.state = cur_dance(state);
    switch (key_tap_state.state) {
        case TD_SINGLE_TAP:
            tap_code(KC_MINS);
            break;
        case TD_SINGLE_HOLD:
            // Momentarily activate your layer
            layer_on(3); // Replace YOUR_LAYER with your layer number
            break;
        case TD_DOUBLE_TAP:
            // Toggle your layer
            layer_invert(3); // Replace YOUR_LAYER with your layer number
            break;
        default:
            break;
    }
}

void thumb_3_reset(tap_dance_state_t *state, void *user_data) {
    // If the key was held down and now is released, turn off the layer
    if (key_tap_state.state == TD_SINGLE_HOLD) {
        layer_off(3); // Replace YOUR_LAYER with your layer number
    }
    key_tap_state.state = TD_NONE;
}

void thumb_5(tap_dance_state_t *state, void *user_data) {
    key_tap_state.state = cur_dance(state);
    switch (key_tap_state.state) {
        case TD_SINGLE_TAP:
            tap_code(KC_ESC);
            break;
        case TD_SINGLE_HOLD:
            layer_on(1);
            break;
        case TD_DOUBLE_TAP:
            layer_invert(1);
            break;
        default:
            break;
    }
}

void thumb_5_reset(tap_dance_state_t *state, void *user_data) {
    if (key_tap_state.state == TD_SINGLE_HOLD) {
        layer_off(1);
    }
    key_tap_state.state = TD_NONE;
}

void thumb_6(tap_dance_state_t *state, void *user_data) {
    key_tap_state.state = cur_dance(state);
    switch (key_tap_state.state) {
        case TD_SINGLE_TAP:
            tap_code(KC_DEL);
            break;
        case TD_SINGLE_HOLD:
            layer_on(2);
            break;
        case TD_DOUBLE_TAP:
            layer_invert(2);
            break;
        default:
            break;
    }
}

void thumb_6_reset(tap_dance_state_t *state, void *user_data) {
    if (key_tap_state.state == TD_SINGLE_HOLD) {
        layer_off(2);
    }
    key_tap_state.state = TD_NONE;
}



enum  {
    DEL_NUM = 0,
    ESC_SYM,
    DSH_HPR,
};


tap_dance_action_t tap_dance_actions[] = {
    [DEL_NUM] =ACTION_TAP_DANCE_FN_ADVANCED(NULL,thumb_6,thumb_6_reset),
    [ESC_SYM] = ACTION_TAP_DANCE_FN_ADVANCED(NULL,thumb_5,thumb_5_reset),
    [DSH_HPR] = ACTION_TAP_DANCE_FN_ADVANCED(NULL,thumb_3,thumb_3_reset),
};
// Custom keycodes
#define DOT_EXLM LT(0, KC_DOT)
#define COMM_PIPE LT(0, KC_COMM)
// Left hand homerowmods
#define GUI_A LGUI_T(KC_A)
#define ALT_S LALT_T(KC_S)
#define CTL_D LCTL_T(KC_D)
#define SFT_F LSFT_T(KC_F)

// Right-hand home row mods
#define SFT_J RSFT_T(KC_J)
#define CTL_K RCTL_T(KC_K)
#define ALT_L LALT_T(KC_L)
#define GUI_SCLN LGUI_T(KC_SCLN)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
//        ┌────────────┬───────┬───────┬───────────────┬───────┬─────────────┐   ┌─────┬─────────────┬─────────────┬──────────┬──────────┬──────┐
//        │ LT(2, esc) │   q   │   w   │       e       │   r   │      t      │   │  y  │      u      │      i      │    o     │    p     │ bspc │
//        ├────────────┼───────┼───────┼───────────────┼───────┼─────────────┤   ├─────┼─────────────┼─────────────┼──────────┼──────────┼──────┤
//        │    tab     │ GUI_A │ ALT_S │     CTL_D     │ SFT_F │      g      │   │  h  │    SFT_J    │    CTL_K    │  ALT_L   │ GUI_SCLN │  '   │
//        ├────────────┼───────┼───────┼───────────────┼───────┼─────────────┤   ├─────┼─────────────┼─────────────┼──────────┼──────────┼──────┤
//        │   OSL(4)   │   z   │   x   │       c       │   v   │      b      │   │  n  │  LT(3, m)   │  COMM_PIPE  │ DOT_EXLM │    /     │  `   │
//        └────────────┴───────┴───────┼───────────────┼───────┼─────────────┤   ├─────┼─────────────┼─────────────┼──────────┴──────────┴──────┘
//                                     │ OSM(MOD_RALT) │  spc  │ TD(DSH_HPR) │   │ ent │ TD(ESC_SYM) │ TD(DEL_NUM) │
//                                     └───────────────┴───────┴─────────────┘   └─────┴─────────────┴─────────────┘
[0] = LAYOUT_split_3x6_3(
      LT(2, KC_ESC) , KC_Q  , KC_W  , KC_E          , KC_R   , KC_T        ,     KC_Y   , KC_U        , KC_I        , KC_O     , KC_P     , KC_BSPC,
      KC_TAB        , GUI_A , ALT_S , CTL_D         , SFT_F  , KC_G        ,     KC_H   , SFT_J       , CTL_K       , ALT_L    , GUI_SCLN , KC_QUOT,
      OSL(4)        , KC_Z  , KC_X  , KC_C          , KC_V   , KC_B        ,     KC_N   , LT(3, KC_M) , COMM_PIPE   , DOT_EXLM , KC_SLSH  , KC_GRV ,
                                      OSM(MOD_RALT) , KC_SPC , TD(DSH_HPR) ,     KC_ENT , TD(ESC_SYM) , TD(DEL_NUM)
),

//        ┌───────┬───┬───┬─────┬───┬───┐   ┌─────────┬─────────┬─────────┬─────────┬─────────┬──────┐
//        │ TO(0) │ # │ @ │  {  │ } │ % │   │ LCTL(c) │ LCTL(v) │ LCTL(x) │ LCTL(x) │ LCTL(z) │ bspc │
//        ├───────┼───┼───┼─────┼───┼───┤   ├─────────┼─────────┼─────────┼─────────┼─────────┼──────┤
//        │  tab  │ ! │ & │  (  │ ) │ = │   │ CW_TOGG │  lsft   │  lctl   │  lalt   │    ;    │  '   │
//        ├───────┼───┼───┼─────┼───┼───┤   ├─────────┼─────────┼─────────┼─────────┼─────────┼──────┤
//        │  no   │ ^ │ $ │  [  │ ] │ \ │   │ RCS(c)  │ RCS(v)  │ RCS(x)  │ RCS(x)  │ LCTL(z) │      │
//        └───────┴───┴───┼─────┼───┼───┤   ├─────────┼─────────┼─────────┼─────────┴─────────┴──────┘
//                        │     │ | │ - │   │         │  TO(0)  │         │
//                        └─────┴───┴───┘   └─────────┴─────────┴─────────┘
[1] = LAYOUT_split_3x6_3(
      TO(0)  , KC_HASH , KC_AT   , KC_LCBR , KC_RCBR , KC_PERC      ,     LCTL(KC_C) , LCTL(KC_V) , LCTL(KC_X) , LCTL(KC_X) , LCTL(KC_Z) , KC_BSPC,
      KC_TAB , KC_EXLM , KC_AMPR , KC_LPRN , KC_RPRN , KC_EQUAL     ,     CW_TOGG    , KC_LSFT    , KC_LCTL    , KC_LALT    , KC_SCLN    , KC_QUOT,
      KC_NO  , KC_CIRC , KC_DLR  , KC_LBRC , KC_RBRC , KC_BACKSLASH ,     RCS(KC_C)  , RCS(KC_V)  , RCS(KC_X)  , RCS(KC_X)  , LCTL(KC_Z) , KC_TRNS,
                                   KC_TRNS , KC_PIPE , KC_MINS      ,     KC_TRNS    , TO(0)      , KC_TRNS
),

//        ┌───────┬───┬───┬─────┬───┬──────┐   ┌──────┬──────┬───────┬──────┬─────────┬──────┐
//        │ TO(0) │ [ │ 7 │  8  │ 9 │  /   │   │ pgup │ home │  up   │ end  │ CW_TOGG │ bspc │
//        ├───────┼───┼───┼─────┼───┼──────┤   ├──────┼──────┼───────┼──────┼─────────┼──────┤
//        │  tab  │ ; │ 4 │  5  │ 6 │  =   │   │ pgdn │ left │ down  │ rght │   del   │  no  │
//        ├───────┼───┼───┼─────┼───┼──────┤   ├──────┼──────┼───────┼──────┼─────────┼──────┤
//        │  no   │ _ │ 1 │  2  │ 3 │ kp_* │   │  no  │  no  │   ,   │  .   │   no    │  no  │
//        └───────┴───┴───┼─────┼───┼──────┤   ├──────┼──────┼───────┼──────┴─────────┴──────┘
//                        │     │ 0 │      │   │      │      │ TO(0) │
//                        └─────┴───┴──────┘   └──────┴──────┴───────┘
[2] = LAYOUT_split_3x6_3(
      TO(0)  , KC_LBRC , KC_7 , KC_8    , KC_9 , KC_SLSH ,     KC_PGUP , KC_HOME , KC_UP   , KC_END  , CW_TOGG , KC_BSPC,
      KC_TAB , KC_SCLN , KC_4 , KC_5    , KC_6 , KC_EQL  ,     KC_PGDN , KC_LEFT , KC_DOWN , KC_RGHT , KC_DEL  , KC_NO  ,
      KC_NO  , KC_UNDS , KC_1 , KC_2    , KC_3 , KC_PAST ,     KC_NO   , KC_NO   , KC_COMM , KC_DOT  , KC_NO   , KC_NO  ,
                                KC_TRNS , KC_0 , KC_TRNS ,     KC_TRNS , KC_TRNS , TO(0)
),

//        ┌───────────┬─────────┬─────────┬─────────┬─────────┬───────────┐   ┌───────────┬────────────┬────────────┬────────────┬──────┬──────┐
//        │   TO(0)   │ LGUI(q) │ LGUI(7) │ LGUI(8) │ LGUI(9) │    no     │   │    no     │     no     │  LGUI(up)  │     no     │  no  │ bspc │
//        ├───────────┼─────────┼─────────┼─────────┼─────────┼───────────┤   ├───────────┼────────────┼────────────┼────────────┼──────┼──────┤
//        │ LGUI(tab) │   no    │ LGUI(4) │ LGUI(5) │ LGUI(6) │ LGUI(spc) │   │ LGUI(spc) │ LGUI(left) │ LGUI(down) │ LGUI(rght) │ lgui │  no  │
//        ├───────────┼─────────┼─────────┼─────────┼─────────┼───────────┤   ├───────────┼────────────┼────────────┼────────────┼──────┼──────┤
//        │    no     │   no    │ LGUI(1) │ LGUI(2) │ LGUI(3) │ LGUI(ent) │   │    no     │     no     │     ,      │     .      │  no  │  no  │
//        └───────────┴─────────┴─────────┼─────────┼─────────┼───────────┤   ├───────────┼────────────┼────────────┼────────────┴──────┴──────┘
//                                        │         │ LGUI(0) │   TO(0)   │   │ LGUI(ent) │            │            │
//                                        └─────────┴─────────┴───────────┘   └───────────┴────────────┴────────────┘
[3] = LAYOUT_split_3x6_3(
      TO(0)        , LGUI(KC_Q) , LGUI(KC_7) , LGUI(KC_8) , LGUI(KC_9) , KC_NO        ,     KC_NO        , KC_NO         , LGUI(KC_UP)   , KC_NO         , KC_NO   , KC_BSPC,
      LGUI(KC_TAB) , KC_NO      , LGUI(KC_4) , LGUI(KC_5) , LGUI(KC_6) , LGUI(KC_SPC) ,     LGUI(KC_SPC) , LGUI(KC_LEFT) , LGUI(KC_DOWN) , LGUI(KC_RGHT) , KC_LGUI , KC_NO  ,
      KC_NO        , KC_NO      , LGUI(KC_1) , LGUI(KC_2) , LGUI(KC_3) , LGUI(KC_ENT) ,     KC_NO        , KC_NO         , KC_COMM       , KC_DOT        , KC_NO   , KC_NO  ,
                                               KC_TRNS    , LGUI(KC_0) , TO(0)        ,     LGUI(KC_ENT) , KC_TRNS       , KC_TRNS
),

//        ┌───────┬─────┬────┬─────┬───────┬────────┐   ┌─────┬──────┬──────┬──────┬──────┬─────┐
//        │ TO(0) │ f12 │ f7 │ f8  │  f9   │  pscr  │   │ no  │  no  │  no  │  no  │  no  │ del │
//        ├───────┼─────┼────┼─────┼───────┼────────┤   ├─────┼──────┼──────┼──────┼──────┼─────┤
//        │  no   │ f11 │ f4 │ f5  │  f6   │  ins   │   │ no  │ lsft │ lctl │ ralt │ lgui │ no  │
//        ├───────┼─────┼────┼─────┼───────┼────────┤   ├─────┼──────┼──────┼──────┼──────┼─────┤
//        │ TO(0) │ f10 │ f1 │ f2  │  f3   │ LSG(e) │   │ no  │  no  │  no  │  no  │  no  │ no  │
//        └───────┴─────┴────┼─────┼───────┼────────┤   ├─────┼──────┼──────┼──────┴──────┴─────┘
//                           │     │ TO(0) │        │   │     │      │      │
//                           └─────┴───────┴────────┘   └─────┴──────┴──────┘
[4] = LAYOUT_split_3x6_3(
      TO(0) , KC_F12 , KC_F7 , KC_F8   , KC_F9 , KC_PSCR   ,     KC_NO   , KC_NO   , KC_NO   , KC_NO   , KC_NO   , KC_DEL,
      KC_NO , KC_F11 , KC_F4 , KC_F5   , KC_F6 , KC_INS    ,     KC_NO   , KC_LSFT , KC_LCTL , KC_RALT , KC_LGUI , KC_NO ,
      TO(0) , KC_F10 , KC_F1 , KC_F2   , KC_F3 , LSG(KC_E) ,     KC_NO   , KC_NO   , KC_NO   , KC_NO   , KC_NO   , KC_NO ,
                               KC_TRNS , TO(0) , KC_TRNS   ,     KC_TRNS , KC_TRNS , KC_TRNS
)
};
const char chordal_hold_layout[MATRIX_ROWS][MATRIX_COLS] PROGMEM =
    LAYOUT(
        'L', 'L', 'L', 'L', 'L', 'L',  'R', 'R', 'R', 'R', 'R', 'R',
        'L', 'L', 'L', 'L', 'L', 'L',  'R', 'R', 'R', 'R', 'R', 'R',
        'L', 'L', 'L', 'L', 'L', 'L',  'R', 'R', 'R', 'R', 'R', 'R',
                       'L', 'L', 'L',  'R', 'R', 'R'
    );
static bool process_tap_or_long_press_key(
    keyrecord_t* record, uint16_t long_press_keycode) {
  if (record->tap.count == 0) {  // Key is being held.
    if (record->event.pressed) {
      tap_code16(long_press_keycode);
    }
    return false;  // Skip default handling.
  }
  return true;  // Continue default handling.
}

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
    switch(keycode){
        case DOT_EXLM:
            return process_tap_or_long_press_key(record,KC_EXLM);
        case COMM_PIPE:
            return process_tap_or_long_press_key(record,KC_PIPE);
    };

  return true;
};

// Define homerowmods speeds per key
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    // List of keycodes with a custom tapping term
    switch (keycode) {
        case LSFT_T(KC_F):
        case LCTL_T(KC_D):
        case RSFT_T(KC_J):
        case RCTL_T(KC_K):
            return TAPPING_TERM - 40;
        default:
            return TAPPING_TERM;
    }
};

uint16_t get_quick_tap_term(uint16_t keycode, keyrecord_t* record) {
  // If you quickly hold a tap-hold key after tapping it, the tap action is
  // repeated. Key repeating is useful e.g. for Vim navigation keys, but can
  // lead to missed triggers in fast typing. Here, returning 0 means we
  // instead want to "force hold" and disable key repeating.
  switch (keycode) {
       case RSFT_T(KC_J):
       case RCTL_T(KC_K):
       case LGUI(KC_L):
      return QUICK_TAP_TERM;  // Enable key repeating.
    default:
      return 0;  // Otherwise, force hold and disable key repeating.
  }
};

bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        // Immediately select the hold action when another key is tapped.
        case LSFT_T(KC_F):
            return true;
        case RSFT_T(SFT_J):
            return true;
        // Do not select the hold action when another key is tapped.
        default:
            return false;
    }
};



/* KEYBOARD PET START */

/* settings */
#    define MIN_WALK_SPEED      10
#    define MIN_RUN_SPEED       40

/* advanced settings */
#    define ANIM_FRAME_DURATION 200  // how long each frame lasts in ms
#    define ANIM_SIZE           96   // number of bytes in array. If you change sprites, minimize for adequate firmware size. max is 1024

/* timers */
uint32_t anim_timer = 0;

/* current frame */
uint8_t current_frame = 0;

/* status variables */
int   current_wpm = 0;
led_t led_usb_state;

bool isSneaking = false;
bool isJumping  = false;
bool showedJump = true;

#ifdef OLED_ENABLE
/* logic */
static void render_luna(int LUNA_X, int LUNA_Y) {
    /* Sit */
    static const char PROGMEM sit[2][ANIM_SIZE] = {/* 'sit1', 32x22px */
                                                   {
                                                       0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x1c, 0x02, 0x05, 0x02, 0x24, 0x04, 0x04, 0x02, 0xa9, 0x1e, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x10, 0x08, 0x68, 0x10, 0x08, 0x04, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x06, 0x82, 0x7c, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x04, 0x0c, 0x10, 0x10, 0x20, 0x20, 0x20, 0x28, 0x3e, 0x1c, 0x20, 0x20, 0x3e, 0x0f, 0x11, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                                   },

                                                   /* 'sit2', 32x22px */
                                                   {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x1c, 0x02, 0x05, 0x02, 0x24, 0x04, 0x04, 0x02, 0xa9, 0x1e, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x90, 0x08, 0x18, 0x60, 0x10, 0x08, 0x04, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x0e, 0x82, 0x7c, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x04, 0x0c, 0x10, 0x10, 0x20, 0x20, 0x20, 0x28, 0x3e, 0x1c, 0x20, 0x20, 0x3e, 0x0f, 0x11, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}};

    /* Walk */
    static const char PROGMEM walk[2][ANIM_SIZE] = {/* 'walk1', 32x22px */
                                                    {
                                                        0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x20, 0x10, 0x90, 0x90, 0x90, 0xa0, 0xc0, 0x80, 0x80, 0x80, 0x70, 0x08, 0x14, 0x08, 0x90, 0x10, 0x10, 0x08, 0xa4, 0x78, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x08, 0xfc, 0x01, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x18, 0xea, 0x10, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x1c, 0x20, 0x20, 0x3c, 0x0f, 0x11, 0x1f, 0x03, 0x06, 0x18, 0x20, 0x20, 0x3c, 0x0c, 0x12, 0x1e, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                                    },

                                                    /* 'walk2', 32x22px */
                                                    {
                                                        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x20, 0x20, 0x20, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x10, 0x28, 0x10, 0x20, 0x20, 0x20, 0x10, 0x48, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0x20, 0xf8, 0x02, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x03, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x10, 0x30, 0xd5, 0x20, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x20, 0x30, 0x0c, 0x02, 0x05, 0x09, 0x12, 0x1e, 0x02, 0x1c, 0x14, 0x08, 0x10, 0x20, 0x2c, 0x32, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                                    }};

    /* Run */
    static const char PROGMEM run[2][ANIM_SIZE] = {/* 'run1', 32x22px */
                                                   {
                                                       0x00, 0x00, 0x00, 0x00, 0xe0, 0x10, 0x08, 0x08, 0xc8, 0xb0, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x40, 0x40, 0x3c, 0x14, 0x04, 0x08, 0x90, 0x18, 0x04, 0x08, 0xb0, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0xc4, 0xa4, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc8, 0x58, 0x28, 0x2a, 0x10, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0e, 0x09, 0x04, 0x04, 0x04, 0x04, 0x02, 0x03, 0x02, 0x01, 0x01, 0x02, 0x02, 0x04, 0x08, 0x10, 0x26, 0x2b, 0x32, 0x04, 0x05, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00,
                                                   },

                                                   /* 'run2', 32x22px */
                                                   {
                                                       0x00, 0x00, 0x00, 0xe0, 0x10, 0x10, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x80, 0x78, 0x28, 0x08, 0x10, 0x20, 0x30, 0x08, 0x10, 0x20, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x04, 0x08, 0x10, 0x11, 0xf9, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x10, 0xb0, 0x50, 0x55, 0x20, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x0c, 0x10, 0x20, 0x28, 0x37, 0x02, 0x1e, 0x20, 0x20, 0x18, 0x0c, 0x14, 0x1e, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                                   }};

    /* Bark */
    static const char PROGMEM bark[2][ANIM_SIZE] = {/* 'bark1', 32x22px */
                                                    {
                                                        0x00, 0xc0, 0x20, 0x10, 0xd0, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x40, 0x3c, 0x14, 0x04, 0x08, 0x90, 0x18, 0x04, 0x08, 0xb0, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x04, 0x08, 0x10, 0x11, 0xf9, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc8, 0x48, 0x28, 0x2a, 0x10, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x0c, 0x10, 0x20, 0x28, 0x37, 0x02, 0x02, 0x04, 0x08, 0x10, 0x26, 0x2b, 0x32, 0x04, 0x05, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                                    },

                                                    /* 'bark2', 32x22px */
                                                    {
                                                        0x00, 0xe0, 0x10, 0x10, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x40, 0x40, 0x2c, 0x14, 0x04, 0x08, 0x90, 0x18, 0x04, 0x08, 0xb0, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x04, 0x08, 0x10, 0x11, 0xf9, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0x48, 0x28, 0x2a, 0x10, 0x0f, 0x20, 0x4a, 0x09, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x0c, 0x10, 0x20, 0x28, 0x37, 0x02, 0x02, 0x04, 0x08, 0x10, 0x26, 0x2b, 0x32, 0x04, 0x05, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                                    }};

    /* Sneak */
    static const char PROGMEM sneak[2][ANIM_SIZE] = {/* 'sneak1', 32x22px */
                                                     {
                                                         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x40, 0x40, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x40, 0x40, 0x80, 0x00, 0x80, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1e, 0x21, 0xf0, 0x04, 0x02, 0x02, 0x02, 0x02, 0x03, 0x02, 0x02, 0x04, 0x04, 0x04, 0x03, 0x01, 0x00, 0x00, 0x09, 0x01, 0x80, 0x80, 0xab, 0x04, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x1c, 0x20, 0x20, 0x3c, 0x0f, 0x11, 0x1f, 0x02, 0x06, 0x18, 0x20, 0x20, 0x38, 0x08, 0x10, 0x18, 0x04, 0x04, 0x02, 0x02, 0x01, 0x00, 0x00, 0x00, 0x00,
                                                     },

                                                     /* 'sneak2', 32x22px */
                                                     {
                                                         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x40, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0xa0, 0x20, 0x40, 0x80, 0xc0, 0x20, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3e, 0x41, 0xf0, 0x04, 0x02, 0x02, 0x02, 0x03, 0x02, 0x02, 0x02, 0x04, 0x04, 0x02, 0x01, 0x00, 0x00, 0x00, 0x04, 0x00, 0x40, 0x40, 0x55, 0x82, 0x7c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x20, 0x30, 0x0c, 0x02, 0x05, 0x09, 0x12, 0x1e, 0x04, 0x18, 0x10, 0x08, 0x10, 0x20, 0x28, 0x34, 0x06, 0x02, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00,
                                                     }};

    /* animation */
    void animate_luna(void) {
        /* jump */
        if (isJumping || !showedJump) {
            /* clear */
            oled_set_cursor(LUNA_X, LUNA_Y + 2);
            oled_write("     ", false);

            oled_set_cursor(LUNA_X, LUNA_Y - 1);

            showedJump = true;
        } else {
            /* clear */
            oled_set_cursor(LUNA_X, LUNA_Y - 1);
            oled_write("     ", false);

            oled_set_cursor(LUNA_X, LUNA_Y);
        }

        /* switch frame */
        current_frame = (current_frame + 1) % 2;

        /* current status */
        if (led_usb_state.caps_lock) {
            oled_write_raw_P(bark[current_frame], ANIM_SIZE);

        } else if (isSneaking) {
            oled_write_raw_P(sneak[current_frame], ANIM_SIZE);

        } else if (current_wpm <= MIN_WALK_SPEED) {
            oled_write_raw_P(sit[current_frame], ANIM_SIZE);

        } else if (current_wpm <= MIN_RUN_SPEED) {
            oled_write_raw_P(walk[current_frame], ANIM_SIZE);

        } else {
            oled_write_raw_P(run[current_frame], ANIM_SIZE);
        }
    }

#    if OLED_TIMEOUT > 0
    /* the animation prevents the normal timeout from occuring */
    if (last_input_activity_elapsed() > OLED_TIMEOUT && last_led_activity_elapsed() > OLED_TIMEOUT) {
        oled_off();
        return;
    } else {
        oled_on();
    }
#    endif

    /* animation timer */
    if (timer_elapsed32(anim_timer) > ANIM_FRAME_DURATION) {
        anim_timer = timer_read32();
        animate_luna();
    }
}

/* KEYBOARD PET END */



// Define layer names
const char *layer_names[] = {
    "Base",
    "Sym",
    "Num",
    "Hypr",
    "fn"
};

// Function to get the name of the current layer
const char* get_layer_name(void) {
    uint8_t layer = get_highest_layer(layer_state);
    if (layer < sizeof(layer_names) / sizeof(layer_names[0])) {
        return layer_names[layer];
    }
    return "Unknown";
};
static void render_logo(void) {
    static const char PROGMEM qmk_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF, 0xB0, 0xB1, 0xB2, 0xB3, 0xB4,
        0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF, 0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0x00
    };
    oled_write_P(qmk_logo, false);
};

static void print_logo_narrow(void) {
    /* wpm counter */
    uint8_t n = get_current_wpm();
    char    wpm_str[4];
    oled_set_cursor(0, 0);
    wpm_str[3] = '\0';
    wpm_str[2] = '0' + n % 10;
    wpm_str[1] = '0' + (n /= 10) % 10;
    wpm_str[0] = '0' + n / 10;
    oled_write(wpm_str, false);
    oled_set_cursor(0, 1);
    oled_write(" wpm", false);
};
// OLED update logic
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_master()) {
        return OLED_ROTATION_270;  // Rotates the slave side display 270 degrees
    }
    return rotation;  // Keep master side at default rotation
};
bool oled_task_user(void) {
    current_wpm   = get_current_wpm();
    led_usb_state = host_keyboard_led_state();
    if(is_keyboard_master()){
        print_logo_narrow();
        oled_set_cursor(0, 3);
        led_t led_state = host_keyboard_led_state();
        oled_write_P(led_state.num_lock ? PSTR("NUM ") : PSTR("    "), false);
            oled_write_P(led_state.caps_lock ? PSTR("CAP") : PSTR(" "), false);
        oled_write_P(led_state.scroll_lock ? PSTR("SCR ") : PSTR("    "), false);
        oled_set_cursor(0, 5);
        oled_write_ln("LAYER", false);
        oled_set_cursor(0, 6);
        oled_write_ln(get_layer_name(), false);
        render_luna(0, 13);
    }else{
        render_logo();  // Renders a static logo
        oled_scroll_left();  // Turns on scrolling
    }
    return false;
}

#endif // OLED_ENABLE
