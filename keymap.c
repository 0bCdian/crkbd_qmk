#include QMK_KEYBOARD_H
#include "features/achordion.h"
#if __has_include("keymap.h")
    #include "keymap.h"
#endif

// Define custom keys

// enum {
//     THUMB_1,
//     THUMB_3,
//     THUMB_5,
//     THUMB_6
// };
// void thumb1(tap_dance_state_t *state, void *user_data) {
//     if (state->count == 1) {
//         register_code16(OSL(4));
//     } else if (state->count == 2) {
//         register_code16(TG(4));
//     }
//
//     if (state->finished) {
//         if (state->count == 1) {
//             unregister_code16(OSL(4));
//         } else if (state->count == 2) {
//             unregister_code16(TG(4));
//         }
//     }
// }
//
// void thumb3(tap_dance_state_t *state, void *user_data) {
//     if (state->count == 1) {
//         register_code16(OSL(3));
//     } else if (state->count == 2) {
//         register_code16(TG(3));
//     }
//
//     if (state->finished) {
//         if (state->count == 1) {
//             unregister_code16(OSL(3));
//         } else if (state->count == 2) {
//             unregister_code16(TG(3));
//         }
//     }
// }
// void thumb5(tap_dance_state_t *state, void *user_data) {
//     if (state->count == 1) {
//         register_code16(OSL(1));
//     } else if (state->count == 2) {
//         register_code16(TG(1));
//     }
//
//     if (state->finished) {
//         if (state->count == 1) {
//             unregister_code16(OSL(1));
//         } else if (state->count == 2) {
//             unregister_code16(TG(1));
//         }
//     }
// }
// void thumb6(tap_dance_state_t *state, void *user_data) {
//     if (state->count == 1) {
//         register_code16(OSL(2));
//     } else if (state->count == 2) {
//         register_code16(TG(2));
//     }
//
//     if (state->finished) {
//         if (state->count == 1) {
//             unregister_code16(OSL(2));
//         } else if (state->count == 2) {
//             unregister_code16(TG(2));
//         }
//     }
// }
// // Similar functions for thumb5 and thumb6
//
// tap_dance_action_t tap_dance_actions[] = {
//     [THUMB_1] = ACTION_TAP_DANCE_FN(thumb1),
//     [THUMB_3] = ACTION_TAP_DANCE_FN(thumb3),
//     [THUMB_5] = ACTION_TAP_DANCE_FN(thumb5),
//     [THUMB_6] = ACTION_TAP_DANCE_FN(thumb6),
// };

#define GUI_A LGUI_T(KC_A)
#define ALT_S LALT_T(KC_S)
#define CTL_D LCTL_T(KC_D)
#define SFT_F LSFT_T(KC_F)

// Right-hand home row mods
#define SFT_J RSFT_T(KC_J)
#define CTL_K RCTL_T(KC_K)
#define ALT_L LALT_T(KC_L)
#define GUI_SCLN LGUI_T(KC_SCLN)

// Define thumb aliases
#define THUMB_2 KC_SPC
#define THUMB_4 KC_ENT


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
//        ┌───────────────┬───────┬───────┬────────┬─────────┬────────┐   ┌─────────┬────────┬────────┬───────┬──────────┬──────┐
//        │      esc      │   q   │   w   │   e    │    r    │   t    │   │    y    │   u    │   i    │   o   │    p     │ bspc │
//        ├───────────────┼───────┼───────┼────────┼─────────┼────────┤   ├─────────┼────────┼────────┼───────┼──────────┼──────┤
//        │      tab      │ GUI_A │ ALT_S │ CTL_D  │  SFT_F  │   g    │   │    h    │ SFT_J  │ CTL_K  │ ALT_L │ GUI_SCLN │  '   │
//        ├───────────────┼───────┼───────┼────────┼─────────┼────────┤   ├─────────┼────────┼────────┼───────┼──────────┼──────┤
//        │ OSM(MOD_RALT) │   z   │   x   │   c    │    v    │   b    │   │    n    │   m    │   ,    │   .   │    /     │  `   │
//        └───────────────┴───────┴───────┼────────┼─────────┼────────┤   ├─────────┼────────┼────────┼───────┴──────────┴──────┘
//                                        │ OSL(4) │ THUMB_2 │ OSL(3) │   │ THUMB_4 │ OSL(1) │ OSL(2) │
//                                        └────────┴─────────┴────────┘   └─────────┴────────┴────────┘
[0] = LAYOUT_split_3x6_3(
      KC_ESC        , KC_Q  , KC_W  , KC_E   , KC_R    , KC_T   ,     KC_Y    , KC_U   , KC_I    , KC_O   , KC_P     , KC_BSPC,
      KC_TAB        , GUI_A , ALT_S , CTL_D  , SFT_F   , KC_G   ,     KC_H    , SFT_J  , CTL_K   , ALT_L  , GUI_SCLN , KC_QUOT,
      OSM(MOD_RALT) , KC_Z  , KC_X  , KC_C   , KC_V    , KC_B   ,     KC_N    , KC_M   , KC_COMM , KC_DOT , KC_SLSH  , KC_GRV ,
                                      OSL(4) , THUMB_2 , OSL(3) ,     THUMB_4 , OSL(1) , OSL(2)
),

//        ┌───────┬───┬───┬──────┬───┬───┐   ┌─────────┬─────────┬────────┬─────────┬─────────┬───────┐
//        │  esc  │ # │ @ │  {   │ } │ % │   │ LCTL(c) │ LCTL(v) │   up   │ LCTL(x) │ LCTL(z) │ bspc  │
//        ├───────┼───┼───┼──────┼───┼───┤   ├─────────┼─────────┼────────┼─────────┼─────────┼───────┤
//        │  tab  │ ! │ & │  (   │ ) │ = │   │   no    │  left   │  down  │  rght   │    ;    │   '   │
//        ├───────┼───┼───┼──────┼───┼───┤   ├─────────┼─────────┼────────┼─────────┼─────────┼───────┤
//        │ TO(0) │ ^ │ $ │  [   │ ] │ \ │   │ RCS(c)  │ RCS(v)  │ RCS(x) │ RCS(x)  │ LCTL(z) │ TG(3) │
//        └───────┴───┴───┼──────┼───┼───┤   ├─────────┼─────────┼────────┼─────────┴─────────┴───────┘
//                        │ kp_* │ | │ - │   │  TO(0)  │  TG(1)  │   no   │
//                        └──────┴───┴───┘   └─────────┴─────────┴────────┘
[1] = LAYOUT_split_3x6_3(
      KC_ESC , KC_HASH , KC_AT   , KC_LCBR , KC_RCBR , KC_PERC      ,     LCTL(KC_C) , LCTL(KC_V) , KC_UP     , LCTL(KC_X) , LCTL(KC_Z) , KC_BSPC,
      KC_TAB , KC_EXLM , KC_AMPR , KC_LPRN , KC_RPRN , KC_EQUAL     ,     KC_NO      , KC_LEFT    , KC_DOWN   , KC_RGHT    , KC_SCLN    , KC_QUOT,
      TO(0)  , KC_CIRC , KC_DLR  , KC_LBRC , KC_RBRC , KC_BACKSLASH ,     RCS(KC_C)  , RCS(KC_V)  , RCS(KC_X) , RCS(KC_X)  , LCTL(KC_Z) , TG(3)  ,
                                   KC_PAST , KC_PIPE , KC_MINS      ,     TO(0)      , TG(1)      , KC_NO
),

//        ┌───────┬───┬───┬───┬───┬──────┐   ┌────┬───────┬───────┬──────┬──────┬──────┐
//        │  esc  │ [ │ 7 │ 8 │ 9 │  /   │   │ no │  no   │  no   │  no  │  no  │ bspc │
//        ├───────┼───┼───┼───┼───┼──────┤   ├────┼───────┼───────┼──────┼──────┼──────┤
//        │  tab  │ ; │ 4 │ 5 │ 6 │  =   │   │ no │ lsft  │ lctl  │ ralt │ lgui │  no  │
//        ├───────┼───┼───┼───┼───┼──────┤   ├────┼───────┼───────┼──────┼──────┼──────┤
//        │ TO(0) │ ` │ 1 │ 2 │ 3 │ kp_* │   │ no │  no   │   ,   │  .   │  no  │  no  │
//        └───────┴───┴───┼───┼───┼──────┤   ├────┼───────┼───────┼──────┴──────┴──────┘
//                        │ _ │ 0 │  -   │   │ no │ TO(0) │ TG(2) │
//                        └───┴───┴──────┘   └────┴───────┴───────┘
[2] = LAYOUT_split_3x6_3(
      KC_ESC , KC_LBRC , KC_7 , KC_8    , KC_9 , KC_SLSH ,     KC_NO , KC_NO   , KC_NO   , KC_NO   , KC_NO   , KC_BSPC,
      KC_TAB , KC_SCLN , KC_4 , KC_5    , KC_6 , KC_EQL  ,     KC_NO , KC_LSFT , KC_LCTL , KC_RALT , KC_LGUI , KC_NO  ,
      TO(0)  , KC_GRV  , KC_1 , KC_2    , KC_3 , KC_PAST ,     KC_NO , KC_NO   , KC_COMM , KC_DOT  , KC_NO   , KC_NO  ,
                                KC_UNDS , KC_0 , KC_MINS ,     KC_NO , TO(0)   , TG(2)
),

//        ┌───────────┬─────────┬─────────┬─────────┬─────────┬───────────┐   ┌───────────┬────────────┬────────────┬────────────┬──────┬──────┐
//        │    esc    │ LGUI(q) │ LGUI(7) │ LGUI(8) │ LGUI(9) │    no     │   │    no     │     no     │  LGUI(up)  │     no     │  no  │ bspc │
//        ├───────────┼─────────┼─────────┼─────────┼─────────┼───────────┤   ├───────────┼────────────┼────────────┼────────────┼──────┼──────┤
//        │ LGUI(tab) │   no    │ LGUI(4) │ LGUI(5) │ LGUI(6) │ LGUI(spc) │   │ LGUI(spc) │ LGUI(left) │ LGUI(down) │ LGUI(rght) │ lgui │  no  │
//        ├───────────┼─────────┼─────────┼─────────┼─────────┼───────────┤   ├───────────┼────────────┼────────────┼────────────┼──────┼──────┤
//        │   TO(0)   │   no    │ LGUI(1) │ LGUI(2) │ LGUI(3) │ LGUI(ent) │   │    no     │     no     │     ,      │     .      │  no  │  no  │
//        └───────────┴─────────┴─────────┼─────────┼─────────┼───────────┤   ├───────────┼────────────┼────────────┼────────────┴──────┴──────┘
//                                        │   no    │ LGUI(0) │   TG(3)   │   │ LGUI(ent) │   TO(0)    │   TG(4)    │
//                                        └─────────┴─────────┴───────────┘   └───────────┴────────────┴────────────┘
[3] = LAYOUT_split_3x6_3(
      KC_ESC       , LGUI(KC_Q) , LGUI(KC_7) , LGUI(KC_8) , LGUI(KC_9) , KC_NO        ,     KC_NO        , KC_NO         , LGUI(KC_UP)   , KC_NO         , KC_NO   , KC_BSPC,
      LGUI(KC_TAB) , KC_NO      , LGUI(KC_4) , LGUI(KC_5) , LGUI(KC_6) , LGUI(KC_SPC) ,     LGUI(KC_SPC) , LGUI(KC_LEFT) , LGUI(KC_DOWN) , LGUI(KC_RGHT) , KC_LGUI , KC_NO  ,
      TO(0)        , KC_NO      , LGUI(KC_1) , LGUI(KC_2) , LGUI(KC_3) , LGUI(KC_ENT) ,     KC_NO        , KC_NO         , KC_COMM       , KC_DOT        , KC_NO   , KC_NO  ,
                                               KC_NO      , LGUI(KC_0) , TG(3)        ,     LGUI(KC_ENT) , TO(0)         , TG(4)
),

//        ┌───────┬─────┬────┬───────┬───────┬────────┐   ┌────┬──────┬──────┬──────┬──────┬────┐
//        │  no   │ f12 │ f7 │  f8   │  f9   │  pscr  │   │ no │  no  │  no  │  no  │  no  │ no │
//        ├───────┼─────┼────┼───────┼───────┼────────┤   ├────┼──────┼──────┼──────┼──────┼────┤
//        │  no   │ f11 │ f4 │  f5   │  f6   │  ins   │   │ no │ lsft │ lctl │ ralt │ lgui │ no │
//        ├───────┼─────┼────┼───────┼───────┼────────┤   ├────┼──────┼──────┼──────┼──────┼────┤
//        │ TO(0) │ f10 │ f1 │  f2   │  f3   │ LSG(e) │   │ no │  no  │  no  │  no  │  no  │ no │
//        └───────┴─────┴────┼───────┼───────┼────────┤   ├────┼──────┼──────┼──────┴──────┴────┘
//                           │ TG(4) │ TO(0) │   no   │   │ no │  no  │  no  │
//                           └───────┴───────┴────────┘   └────┴──────┴──────┘
[4] = LAYOUT_split_3x6_3(
      KC_NO , KC_F12 , KC_F7 , KC_F8 , KC_F9 , KC_PSCR   ,     KC_NO , KC_NO   , KC_NO   , KC_NO   , KC_NO   , KC_NO,
      KC_NO , KC_F11 , KC_F4 , KC_F5 , KC_F6 , KC_INS    ,     KC_NO , KC_LSFT , KC_LCTL , KC_RALT , KC_LGUI , KC_NO,
      TO(0) , KC_F10 , KC_F1 , KC_F2 , KC_F3 , LSG(KC_E) ,     KC_NO , KC_NO   , KC_NO   , KC_NO   , KC_NO   , KC_NO,
                               TG(4) , TO(0) , KC_NO     ,     KC_NO , KC_NO   , KC_NO
)
};
bool process_record_user(uint16_t keycode, keyrecord_t* record) {
  if (!process_achordion(keycode, record)) { return false; }
  return true;
};

bool achordion_chord(uint16_t tap_hold_keycode,
                     keyrecord_t* tap_hold_record,
                     uint16_t other_keycode,
                     keyrecord_t* other_record) {

  // Also allow same-hand holds when the other key is in the rows below the
  // alphas. I need the `% (MATRIX_ROWS / 2)` because my keyboard is split.
  if (other_record->event.key.row % (MATRIX_ROWS / 2) >= 4) { return true; }

  // Otherwise, follow the opposite hands rule.
  return achordion_opposite_hands(tap_hold_record, other_record);
};

// uint16_t achordion_timeout(uint16_t tap_hold_keycode) {
//   switch (tap_hold_keycode) {
//     case TD(THUMB_1):
//     case THUMB_2:
//     case TD(THUMB_3):
//     case THUMB_4:
//     case TD(THUMB_5):
//     case TD(THUMB_6):
//       return 0;  // Bypass Achordion for these keys.
// }
//
//   return 800;  // Otherwise use a timeout of 400 ms.
// };

bool achordion_eager_mod(uint8_t mod) {
  switch (mod) {
    case MOD_LSFT:
    case MOD_RSFT:
    case MOD_LCTL:
    case MOD_RCTL:
      return true;  // Eagerly apply Shift and Ctrl mods.
    default:
      return false;
  }
}

void housekeeping_task_user(void) {
  achordion_task();
};

// Define homerowmods speeds per key
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    // List of keycodes with a custom tapping term
    switch (keycode) {
        case SFT_J:
        case CTL_K:
        case ALT_L:
        case THUMB_2:
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
       case KC_J:
       case KC_K:
       case KC_L:
      return QUICK_TAP_TERM;  // Enable key repeating.
    default:
      return 0;  // Otherwise, force hold and disable key repeating.
  }
};

bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        // Immediately select the hold action when another key is tapped.
        case SFT_F:
            return true;
        case SFT_J:
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
