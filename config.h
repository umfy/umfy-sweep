/* Copyright 2015-2021 Jack Humbert
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#define COMBO_COUNT 6

// General Configs
#define NO_ACTION_ONESHOT
#define FORCE_NKRO
#define TAPPING_TOGGLE 3

// Mouse Configs
#define MK_3_SPEED
#define MK_MOMENTARY_ACCEL
#define MK_C_OFFSET_1 6
#define MK_C_OFFSET_UNMOD 16
#define MK_C_OFFSET_2 26
// for MK_W lower is faster (Time between scroll steps)
#define MK_W_INTERVAL_UNMOD 80

// Tap-Hold Configs
#define TAPPING_TERM 230
#define PERMISSIVE_HOLD
#define IGNORE_MOD_TAP_INTERRUPT
#define IGNORE_MOD_TAP_INTERRUPT_PER_KEY
#define TAPPING_FORCE_HOLD
#define TAPPING_FORCE_HOLD_PER_KEY
