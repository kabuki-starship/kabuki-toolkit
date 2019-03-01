/* Kabuki Toolkit @version 0.x
@link    https://github.com/kabuki-starship/kabuki_toolkit.git
@file    /kabuki/features/camera/01_bar.h
@author  Cale McCollough <https://calemccollough.github.io>
@license Copyright (C) 2014-2019 Cale McCollough <cale@astartup.net>;
All right reserved (R). This Source Code Form is subject to the terms of the 
Mozilla Public License, v. 2.0. If a copy of the MPL was not distributed with 
this file, You can obtain one at https://mozilla.org/MPL/2.0/. */

#pragma once
#include <pch.h>

#if SEAM == KABUKI_FEATURES_CAMERA_0
#include "test_debug.inl"
#else
#include "test_release.inl"
#endif

using namespace _;

namespace kabuki { namespace features { namespace camera {
inline const CH1* _1_Bar (CH1* seam_log, CH1* seam_end, const CH1* args) {
#if SEAM >= KABUKI_FEATURES_CAMERA_0
  TEST_BEGIN;

  PRINT_HEADING ("Testing Foo fun.");

#endif
  return 0;
}
} //< namespace camera
} //< namespace features
} //< namespace kabuki