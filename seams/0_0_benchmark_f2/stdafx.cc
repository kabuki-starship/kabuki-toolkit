/* Kabuki Toolkit @version 0.x
@link    https://github.com/kabuki-starship/kabuki-toolkit.git
@file    ~/seams/0_0_benchmark_f2/stdafx.cc
@author  Cale McCollough <cale.mccollough@gmail.com>
@license Copyright (C) 2014-2017 Cale McCollough <calemccollough.github.io>;
All right reserved (R). Licensed under the Apache License, Version 2.0 (the
"License"); you may not use this file except in compliance with the License.
You may obtain a copy of the License at www.apache.org/licenses/LICENSE-2.0.
Unless required by applicable law or agreed to in writing, software distributed
under the License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
CONDITIONS OF ANY KIND, either express or implied. See the License for the
specific language governing permissions and limitations under the License. */

#include <stdafx.h>

#if SEAM > 0 && SEAM <= SEAM_COUNT

#include <f2/ttest.h>

namespace _ {
TestCase TestSEAM_0_0_0(const char* args) { return TestCase(); }

TestCase TestSEAM_0_0_2(const char* args) { return TestCase(); }

static SeamMajor seam_major_1 = MajorSeams<&TestSEAM_0_0_0, &TestSEAM_0_0_1>(
    0, 0, seam_major_1.GetMinorSeamCount());

static SeamMajor seam_major_2 = MajorSeams<&TestSEAM_0_0_0, &TestSEAM_0_0_1>(
    0, 0, seam_major_1.GetMinorSeamCount());

static SeamPage seam_page_1 =
    PageSeams<&seam_major_1, &seam_major_2>(1, seam_page_1.GetMajorSeamCount());

}  // namespace _

int main(int arg_count, char** args) { return seam_page_1.Run(args); }

#endif  //< #if SEAM > 0 && SEAM <= SEAM_COUNT
