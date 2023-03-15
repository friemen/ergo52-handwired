#ifndef CONFIG_H
#define CONFIG_H

/* #include "config_common.h" */

/* USB Device descriptor parameter */
/*#define VENDOR_ID       0xBB80*/
/*#define PRODUCT_ID      0x040D*/
/*#define DEVICE_VER      0x0001*/
/*#define MANUFACTURER    friemen*/
/*#define PRODUCT         Ergo 52 Handwired*/
/*#define DESCRIPTION     A QMK powered Atreus inspired keyboard*/

/* key matrix size */
#define MATRIX_ROWS 5
#define MATRIX_COLS 12

/* See also design/pro-micro-pinout.png */
/* Column mapping C1 .. C12 = Pro Micro pinout = QMK symbols */
/*  C1 =  16 = B2 */
/*  C2 =  10 = B6 */
/*  C3 =   9 = B5 */
/*  C4 =   8 = B4 */
/*  C5 =   7 = E6 */
/*  C6 =   6 = D7 */
/*  C7 =   5 = C6 */
/*  C8 =   4 = D4 */
/*  C9 =   3 = D0 */
/* C10 =   2 = D1 */
/* C11 = RX1 = D2 */
/* C12 = TX0 = D3 */
/* Row mapping R1 .. R5 = Pro Micro pinout = QMK symbols */
/*  R1 =  A2 = F5 */
/*  R2 =  A1 = F6 */
/*  R3 =  A0 = F7 */
/*  R4 =  15 = B1 */
/*  R5 =  14 = B3 */

#define MATRIX_ROW_PINS { F5, F6, F7, B1, B3 }
#define MATRIX_COL_PINS { B2, B6, B5, B4, E6, D7, C6, D4, D0, D1, D2, D3 }
/*#define UNUSED_PINS*/

/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION COL2ROW

/* Debounce reduces chatter (unintended double-presses) - set 0 if debouncing is not needed */
#define DEBOUNCE 5

/* define if matrix has ghost (lacks anti-ghosting diodes) */
//#define MATRIX_HAS_GHOST

/* number of backlight levels */

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
//#define LOCKING_SUPPORT_ENABLE
/* Locking resynchronize hack */
//#define LOCKING_RESYNC_ENABLE

#endif
