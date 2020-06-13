#pragma once

// place overrides here

// added to avoid unwanted mod combinations when typing mod-tap or layer-tap keys faster
#define IGNORE_MOD_TAP_INTERRUPT
#define PERMISSIVE_HOLD
// WATCHOUT might break tapping toggle
#define TAPPING_FORCE_HOLD
//#define RETRO_TAPPING

#ifdef FRIEMEN_ERGO52_HANDWIRED
#undef FRIEMEN_ERGO52_HANDWIRED
#endif
