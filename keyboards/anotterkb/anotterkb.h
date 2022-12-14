#pragma once

#include "quantum.h"

#define LAYOUT_split_4x5( \
       L00, L01, L02, L03, L04,           R00, R01, R02, R03, R04, \
  L30, L10, L11, L12, L13, L14,           R10, R11, R12, R13, R14, R34, \
  L31, L20, L21, L22, L23, L24,           R20, R21, R22, R23, R24, R33,\
                      L32, L33, L34, R30, R31, R32 \
  ) \
  { \
    { L00, L01, L02, L03, L04 }, \
    { L10, L11, L12, L13, L14 }, \
    { L20, L21, L22, L23, L24 }, \
    { L30, L31, L32, L33, L34 }, \
    { R04, R03, R02, R01, R00 }, \
    { R14, R13, R12, R11, R10 }, \
    { R24, R23, R22, R21, R20 }, \
    { R34, R33, R32, R31, R30 } \
  }
