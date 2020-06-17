#pragma once

// place overrides here

// Config options for mod tap and layer tap

// see also https://docs.qmk.fm/#/tap_hold

#define TAPPING_TERM 200  // default is 200 ms

/* Permissive hold: Makes tap and hold keys work better for fast typists, or when you’ve set TAPPING_TERM to a high value. */
#define PERMISSIVE_HOLD

/* Ignore Mod Tap Interrupt: Alters the behaviour of tap and hold keys in a similar but different way than Permissive hold. */
#define IGNORE_MOD_TAP_INTERRUPT

/* Tapping Force Hold: Allows you to have the given keycode repeat when tapping and then holding the modifier key for a second time. */
// WATCHOUT might break tapping toggle
#define TAPPING_FORCE_HOLD

/* Retro Tapping: Sends the keycode instead of the modifier when you have held the modifier without pressing another key. */
//#define RETRO_TAPPING


/*
 From my tests, the options mean the following

 PERMISSIVE_HOLD = Always the modified output

 IGNORE_MOD_TAP_INTERRUPT = Always both keys, unless you hold both
 keys for at least TAPPING_TERM

 PERMISSIVE_HOLD + IGNORE_MOD_TAP_INTERRUPT = Modified output if the
 other key is released before the tap key, or if both keys are held
 longer than TAPPING_TERM. So both keys are output when releasing the
 tap key before the other key and held less than TAPPING_TERM

*/


// Tests
// quickly type the word 'layer'
// quickly type 'A'

#ifdef FRIEMEN_ERGO52_HANDWIRED
#undef FRIEMEN_ERGO52_HANDWIRED
#endif
