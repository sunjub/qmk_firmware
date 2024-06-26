// Copyright 2022 Y.Sakamoto (@FREEWING-JP)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#include "quantum.h"

/* This is a shortcut to help you visually see your layout.
 *
 * The first section contains all of the arguments representing the physical
 * layout of the board and position of the keys.
 *
 * The second converts the arguments into a two-dimensional array which
 * represents the switch matrix.
 */
#define LAYOUT( \
    L00, L01, L02, L03, L04, \
    L10, L11, L12, L13, L14, \
    L20, L21, L22, L23, L24, \
    L30, L31, L32, L33, L34, \
    L40, L41, L42, L43, L44, \
    L50, L51, L52, L53, L54, \
    L60, L61, L62, L63, L64, \
    L70, L71, L72, L73, L74, \
    R00, R01, R02, R03, R04, \
    R10, R11, R12, R13, R14, \
    R20, R21, R22, R23, R24, \
    R30, R31, R32, R33, R34, \
    R40, R41, R42, R43, R44, \
    R50, R51, R52, R53, R54, \
    R60, R61, R62, R63, R64, \
    R70, R71, R72, R73, R74 \
) { \
    { L00, L01, L02, L03, L04 }, \
    { L10, L11, L12, L13, L14 }, \
    { L20, L21, L22, L23, L24 }, \
    { L30, L31, L32, L33, L34 }, \
    { L40, L41, L42, L43, L44 }, \
    { L50, L51, L52, L53, L54 }, \
    { L60, L61, L62, L63, L64 }, \
    { L70, L71, L72, L73, L74 }, \
    { R00, R01, R02, R03, R04 }, \
    { R10, R11, R12, R13, R14 }, \
    { R20, R21, R22, R23, R24 }, \
    { R30, R31, R32, R33, R34 }, \
    { R40, R41, R42, R43, R44 }, \
    { R50, R51, R52, R53, R54 }, \
    { R60, R61, R62, R63, R64 }, \
    { R70, R71, R72, R73, R74 } \
}
