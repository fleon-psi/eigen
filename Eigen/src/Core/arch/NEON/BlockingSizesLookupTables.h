// This file is part of Eigen, a lightweight C++ template library
// for linear algebra.
//
// Copyright (C) 2015 Benoit Jacob <benoitjacob@google.com>
//
// This Source Code Form is subject to the terms of the Mozilla
// Public License v. 2.0. If a copy of the MPL was not distributed
// with this file, You can obtain one at http://mozilla.org/MPL/2.0/.

#ifndef EIGEN_NEON_BLOCKING_SIZES_LOOKUP_TABLES_H
#define EIGEN_NEON_BLOCKING_SIZES_LOOKUP_TABLES_H

namespace Eigen {
namespace internal {

/* The following lookup table was generated from measurements on a Nexus 5,
 * which has a Qualcomm Krait 400 CPU. This is very representative of current
 * 32bit (ARMv7) Android devices. On the other hand, I don't know how
 * representative that is outside of these conditions. Accordingly,
 * let's only use this lookup table on ARM 32bit on Android for now.
 *
 * Measurements were single-threaded, with Scalar=float, compiled with
 * -mfpu=neon-vfpv4, so the pmadd instruction used was VFMA.F32.
 *
 * The device was cooled, allowing it to run a the max clock speed throughout.
 * This may not be representative of real-world thermal conditions.
 *
 * The benchmark attempted to flush caches to test cold-cache performance.
 */
#if EIGEN_ARCH_ARM && EIGEN_OS_ANDROID
template<>
struct BlockingSizesLookupTable<float, float> {
  static const size_t BaseSize = 16;
  static const size_t NumSizes = 8;
  static const uint16_t* Data() {
    static const uint16_t data[512] = {
      0x444, 0x445, 0x446, 0x447, 0x448, 0x449, 0x447, 0x447,
      0x454, 0x455, 0x456, 0x457, 0x458, 0x459, 0x45a, 0x457,
      0x464, 0x465, 0x466, 0x467, 0x468, 0x469, 0x46a, 0x467,
      0x474, 0x475, 0x476, 0x467, 0x478, 0x479, 0x477, 0x478,
      0x474, 0x475, 0x476, 0x477, 0x478, 0x476, 0x476, 0x476,
      0x474, 0x475, 0x476, 0x477, 0x478, 0x479, 0x496, 0x496,
      0x474, 0x475, 0x476, 0x4a6, 0x4a5, 0x4a6, 0x4a5, 0x4a6,
      0x474, 0x475, 0x466, 0x4a6, 0x4a6, 0x4a6, 0x496, 0x4a6,
      0x544, 0x545, 0x546, 0x547, 0x548, 0x549, 0x54a, 0x54b,
      0x554, 0x555, 0x556, 0x557, 0x558, 0x559, 0x55a, 0x55b,
      0x564, 0x565, 0x566, 0x567, 0x568, 0x569, 0x56a, 0x56b,
      0x564, 0x565, 0x566, 0x567, 0x568, 0x569, 0x56a, 0x576,
      0x564, 0x565, 0x566, 0x567, 0x568, 0x569, 0x56a, 0x587,
      0x564, 0x565, 0x566, 0x567, 0x596, 0x596, 0x597, 0x596,
      0x564, 0x565, 0x566, 0x5a5, 0x5a6, 0x5a6, 0x596, 0x596,
      0x564, 0x565, 0x566, 0x596, 0x5a6, 0x596, 0x5a6, 0x5a6,
      0x644, 0x645, 0x646, 0x647, 0x648, 0x649, 0x64a, 0x64b,
      0x644, 0x655, 0x656, 0x657, 0x658, 0x659, 0x65a, 0x65b,
      0x664, 0x665, 0x666, 0x667, 0x668, 0x669, 0x65a, 0x667,
      0x674, 0x665, 0x666, 0x677, 0x678, 0x679, 0x67a, 0x675,
      0x684, 0x685, 0x686, 0x687, 0x678, 0x688, 0x687, 0x686,
      0x664, 0x665, 0x666, 0x657, 0x697, 0x696, 0x696, 0x697,
      0x664, 0x655, 0x686, 0x696, 0x685, 0x6a6, 0x686, 0x686,
      0x684, 0x675, 0x686, 0x685, 0x686, 0x696, 0x696, 0x696,
      0x744, 0x745, 0x746, 0x747, 0x748, 0x749, 0x74a, 0x746,
      0x754, 0x755, 0x756, 0x757, 0x758, 0x759, 0x75a, 0x757,
      0x764, 0x755, 0x756, 0x747, 0x768, 0x759, 0x75a, 0x767,
      0x744, 0x765, 0x766, 0x767, 0x768, 0x759, 0x778, 0x777,
      0x744, 0x745, 0x766, 0x767, 0x788, 0x788, 0x786, 0x788,
      0x754, 0x755, 0x766, 0x787, 0x787, 0x796, 0x787, 0x797,
      0x684, 0x695, 0x696, 0x6a5, 0x786, 0x786, 0x795, 0x796,
      0x684, 0x695, 0x686, 0x6a6, 0x786, 0x796, 0x786, 0x796,
      0x844, 0x845, 0x846, 0x847, 0x848, 0x849, 0x847, 0x848,
      0x844, 0x845, 0x846, 0x847, 0x848, 0x849, 0x857, 0x858,
      0x844, 0x865, 0x846, 0x847, 0x868, 0x849, 0x866, 0x867,
      0x844, 0x865, 0x846, 0x847, 0x878, 0x849, 0x877, 0x877,
      0x844, 0x845, 0x846, 0x867, 0x885, 0x887, 0x885, 0x887,
      0x784, 0x785, 0x786, 0x877, 0x885, 0x885, 0x896, 0x896,
      0x684, 0x695, 0x696, 0x885, 0x896, 0x885, 0x895, 0x895,
      0x694, 0x685, 0x6a6, 0x885, 0x885, 0x886, 0x896, 0x896,
      0x944, 0x945, 0x946, 0x947, 0x948, 0x847, 0x848, 0x848,
      0x944, 0x855, 0x756, 0x947, 0x858, 0x857, 0x858, 0x858,
      0x944, 0x945, 0x946, 0x867, 0x948, 0x866, 0x866, 0x867,
      0x944, 0x775, 0x976, 0x877, 0x877, 0x878, 0x877, 0x877,
      0x784, 0x785, 0x886, 0x887, 0x886, 0x986, 0x887, 0x887,
      0x784, 0x785, 0x786, 0x796, 0x885, 0x897, 0x896, 0x897,
      0x684, 0x695, 0x6a4, 0x886, 0x886, 0x896, 0x896, 0x896,
      0x6a4, 0x6a5, 0x696, 0x886, 0x886, 0x896, 0x896, 0x896,
      0x844, 0x845, 0x846, 0x847, 0x847, 0x847, 0x847, 0x847,
      0x854, 0x855, 0x856, 0x857, 0x857, 0x858, 0x857, 0x857,
      0x864, 0x865, 0x866, 0x867, 0x867, 0x866, 0x867, 0x867,
      0x774, 0x775, 0x876, 0x877, 0x877, 0x877, 0x877, 0x877,
      0x784, 0x785, 0x886, 0x887, 0x887, 0x887, 0x887, 0x887,
      0x784, 0x785, 0x786, 0x787, 0x887, 0x896, 0x897, 0x897,
      0x684, 0x6a5, 0x696, 0x886, 0x896, 0x896, 0x896, 0x896,
      0x694, 0x6a5, 0x6a5, 0x886, 0xa68, 0x896, 0x896, 0x896,
      0x844, 0x845, 0x846, 0x846, 0x847, 0x945, 0x847, 0x946,
      0x854, 0xb55, 0x856, 0x857, 0x857, 0x856, 0x857, 0x857,
      0x864, 0x865, 0x866, 0x867, 0x867, 0x867, 0x867, 0x867,
      0x864, 0x875, 0x876, 0x877, 0x877, 0x877, 0x877, 0x877,
      0x784, 0x885, 0x886, 0x886, 0x886, 0x887, 0x887, 0x887,
      0x784, 0x785, 0x786, 0x786, 0x886, 0x897, 0x897, 0x897,
      0x684, 0x695, 0x696, 0x886, 0x896, 0x896, 0x896, 0x896,
      0x684, 0x6a5, 0x696, 0xb57, 0x896, 0x896, 0x896, 0x896
    };
    return data;
  }
};
#endif

}
}

#endif // EIGEN_NEON_BLOCKING_SIZES_LOOKUP_TABLES_H
