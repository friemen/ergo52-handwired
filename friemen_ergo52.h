#ifndef FRIEMEN_ERGO52_HANDWIRED_H
#define FRIEMEN_ERGO52_HANDWIRED_H

#include "quantum.h"

// The first section contains all of the arguments
// The second converts the arguments into a two-dimensional array
#define LAYOUT( \
  k01, k02, k03, k04, k05, k06, k07, k08, k09, k10, k11, k12, \
  k13, k14, k15, k16, k17, k18, k19, k20, k21, k22, k23, k24, \
  k25, k26, k27, k28, k29, k30, k31, k32, k33, k34, k35, k36, \
  k37, k38, k39, k40, k41, k42, k43, k44, k45, k46, k47, k48, \
                      k49, k50, k51, k52 \
)  \
{ \
 /* R1 */  { k01, k02, k03, k04, k05, k06, k07, k08, k09, k10, k11, k12 }, \
 /* R2 */  { k13, k14, k15, k16, k17, k18, k19, k20, k21, k22, k23, k24 }, \
 /* R3 */  { k25, k26, k27, k28, k29, k30, k31, k32, k33, k34, k35, k36 }, \
 /* R4 */  { k37, k38, k39, k40, k41, k42, k43, k44, k45, k46, k47, k48 }, \
 /* R5 */  {  0,   0,   0,   0, k49, k50, k51, k52,   0,   0,   0,   0  }  \
}

           /* C1   C2   C3   C4   C5   C6   C7   C8   C9   C10  C11  C12 */

#endif
