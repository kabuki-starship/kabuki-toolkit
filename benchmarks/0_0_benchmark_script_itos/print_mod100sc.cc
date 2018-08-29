/** Kabuki Toolkit @version 0.x
@file    $kabuki-toolkit/kabuki/crabs/crabs_console.cc
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
#include "print_itos.h"

#if DEBUG
inline void PrintBinary(uint32_t value) {
  enum { kSize = sizeof(uint32_t) * 8 };

  std::cout << "\n    ";
  for (int i = kSize; i > 0; --i) {
    char c = (char)('0' + (value >> (kSize - 1)));
    std::cout << c;
    value = value << 1;
  }
}

inline void PrintBinaryTable(uint32_t value) {
  enum { kSize = sizeof(uint32_t) * 8 };

  std::cout << "\n    ";
  for (int i = kSize; i > 0; --i) {
    char c = (char)('0' + (value >> (kSize - 1)));
    std::cout << c;
    value = value << 1;
  }
  std::cout << "\n    bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb"
               "\n    33222222222211111111110000000000"
               "\n    10987654321098765432109876543210"
               "\n    ||  |  |   |  |  |   |  |  |   |"
               "\n    |1  0  0   0  0  0   0  0  0   0"
               "\n    |0  9  8   7  6  5   4  3  2   1";
}

#define PRINTF(format, ...) printf(format, __VA_ARGS__)
#define PUTCHAR(c) putchar(c)
#define PRINT_PRINTED                                                   \
  sprintf_s(buffer, 24, "%u", value);                                   \
  *text_end = 0;                                                        \
  printf("\n    Printed \"%s\" leaving value:\"%s\":%u", begin, buffer, \
         (uint)strlen(buffer))
#define PRINT_BINARY PrintBinary(value)
#define PRINT_BINARY_TABLE PrintBinaryTable(value)
#else
#define PRINTF(x, ...)
#define PUTCHAR(c)
#define PRINT_PRINTED
#define PRINT_BINARY
#define PRINT_BINARY_TABLE
#endif

namespace _ {

void PrintLine(char c) {
  std::cout << '\n';
  for (int i = 80; i > 0; --i) std::cout << c;
}

char* Print(uint32_t value, char* text, char* text_end) {
  // Lookup table for powers of 10.
  static const uint32_t k10ToThe[]{1,         10,         100,         1000,
                                   10000,     100000,     1000000,     10000000,
                                   100000000, 1000000000, ~(uint32_t)0};

  /** Lookup table of ASCII char pairs for 00, 01, ..., 99.
      To convert this algorithm to big-endian, flip the digit pair bytes. */
  static const uint16_t kDigits00To99[100] = {
      0x3030, 0x3130, 0x3230, 0x3330, 0x3430, 0x3530, 0x3630, 0x3730, 0x3830,
      0x3930, 0x3031, 0x3131, 0x3231, 0x3331, 0x3431, 0x3531, 0x3631, 0x3731,
      0x3831, 0x3931, 0x3032, 0x3132, 0x3232, 0x3332, 0x3432, 0x3532, 0x3632,
      0x3732, 0x3832, 0x3932, 0x3033, 0x3133, 0x3233, 0x3333, 0x3433, 0x3533,
      0x3633, 0x3733, 0x3833, 0x3933, 0x3034, 0x3134, 0x3234, 0x3334, 0x3434,
      0x3534, 0x3634, 0x3734, 0x3834, 0x3934, 0x3035, 0x3135, 0x3235, 0x3335,
      0x3435, 0x3535, 0x3635, 0x3735, 0x3835, 0x3935, 0x3036, 0x3136, 0x3236,
      0x3336, 0x3436, 0x3536, 0x3636, 0x3736, 0x3836, 0x3936, 0x3037, 0x3137,
      0x3237, 0x3337, 0x3437, 0x3537, 0x3637, 0x3737, 0x3837, 0x3937, 0x3038,
      0x3138, 0x3238, 0x3338, 0x3438, 0x3538, 0x3638, 0x3738, 0x3838, 0x3938,
      0x3039, 0x3139, 0x3239, 0x3339, 0x3439, 0x3539, 0x3639, 0x3739, 0x3839,
      0x3939,
  };

  static const char kMsbShift[] = {
      4, 7, 11, 14, 17, 21, 24, 27, 30,
  };

  if (!text) {
    return nullptr;
  }
  if (text >= text_end) {
    return nullptr;
  }

  const uint32_t* power_of_ten;
  uint16_t* text16;
  char index,  //< Temp multi-purpose variable.
      length;
  uint16_t digits;  //<
  uint32_t comparator, offset;

#if DEBUG
  // Write a bunches of xxxxxx to the buffer for debug purposes.
  for (int i = 0; i <= 21; ++i) {
    *(text + i) = 'x';
  }
  *(text + 21) = 0;
  char* begin = text;
  char buffer[256];
  uint32_t smallest_value, largest_value;
  double range, lower_probability, upper_probability;

  static const char kRangeShift[] = {
      4, 7, 10, 14, 17, 20, 24, 27, 30,
  };
#endif

  if (value < 10) {
    PRINTF("\n    Range:[0, 9] length:1 ");
    if (text + 1 >= text_end) {
      return nullptr;
    }
    *text++ = '0' + (char)value;
    PRINT_PRINTED;
    return text;
  }
  if (value < 100) {
    PRINTF("\n    Range:[10, 99] length:2 ");
    if (text + 2 >= text_end) {
      return nullptr;
    }
    *reinterpret_cast<uint16_t*>(text) = kDigits00To99[value];
    PRINT_PRINTED;
    return text + 2;
  }
  digits = value % 100;
  if (value >> 17) {
    if (value >> 24) {
      if (value >> 30) {
        power_of_ten = &k10ToThe[10];
        length = 10;
      } else if (value >> 27) {
        power_of_ten = &k10ToThe[9];
        length = 9;
      } else {  // if (value >> 24) {
        power_of_ten = &k10ToThe[8];
        length = 8;
      }
    } else if (value >> 20) {
      power_of_ten = &k10ToThe[7];
      length = 7;
    } else {  // if (value >> 17) {
      power_of_ten = &k10ToThe[6];
      length = 6;
    }
  } else if (value >> 14) {
    power_of_ten = &k10ToThe[5];
    length = 5;
  } else if (value >> 10) {
    power_of_ten = &k10ToThe[4];
    comparator = *power_of_ten;
#if DEBUG
    length = 4;
    smallest_value = 1 << (kRangeShift[length - 2]);
    largest_value = (~(uint32_t)0) >> (32 - (kRangeShift[length - 1]));

    printf("\n    B. Range:[%u, %u]:%u comparator:%u", smallest_value,
           largest_value, largest_value - smallest_value, comparator);

    range = (double)(largest_value - smallest_value);
    lower_probability =
        100.0 * (1.0 - ((double)(comparator - smallest_value)) / range);
    upper_probability =
        100.0 * (1.0 - ((double)(largest_value - comparator)) / range);
#endif
    if (value >= comparator) {
      PRINTF("\n    B. Range:[%u, %u] length:%u probablity:%f%%", comparator,
             (1 << (kRangeShift[length - 1])) - 1, (uint)length,
             lower_probability);
      *text++ = '1';
      PRINT_PRINTED;
      value -= comparator;
    } else {
      PRINTF("\n    B. Range:[%u, %u] length:%u probablity:%f%%",
             1 << (kRangeShift[length - 2]), comparator, (uint)length,
             lower_probability);
    }
    text16 = reinterpret_cast<uint16_t*>(text + 2);
    *text16-- = kDigits00To99[digits];
    *text16 = kDigits00To99[value / 100];
    PRINT_PRINTED;
    return text + 4;
  } else {
    offset = 1000;
    if (value >= offset) {
      PRINTF("\n    Range:[1000, 1024] length:4");
      if (text + 4 >= text_end) {
        return nullptr;
      }
      text16 = reinterpret_cast<uint16_t*>(text + 2);
      *text16-- = kDigits00To99[digits];
      *text16 = (((uint16_t)'1') | (((uint16_t)'0') << 8));
      PRINT_PRINTED;
      return text + 4;
    }
    PRINTF("\n    Range:[100, 999] length:3");
    if (text + 3 >= text_end) {
      return nullptr;
    }
    *reinterpret_cast<uint16_t*>(text + 1) = kDigits00To99[digits];
    value /= 100;
    *text = (char)value + '0';
    PRINT_PRINTED;
    return text + 3;
  }

  comparator = *power_of_ten--;

#if DEBUG
  smallest_value = 1 << (kRangeShift[length - 2]);
  largest_value = (~(uint32_t)0) >> (32 - (kRangeShift[length - 1]));

  printf("\n    Range:[%u, %u]:%u comparator:%u", smallest_value, largest_value,
         largest_value - smallest_value, comparator);

  range = (double)(largest_value - smallest_value);
  lower_probability =
      100.0 * (1.0 - ((double)(comparator - smallest_value)) / range);
  upper_probability =
      100.0 * (1.0 - ((double)(largest_value - comparator)) / range);
#endif

  if (value >= comparator) {
    if (text >= text_end) {
      return nullptr;
    }
    text_end = text + length + 1;
    PRINTF("\n    A.) Range:[%u, %u] length:%u probablity:%f%%", comparator,
           (1 << (kRangeShift[length - 1])) - 1, (uint)length,
           lower_probability);
    value -= comparator;
    *text++ = '1';
    PRINT_PRINTED;
    text16 = reinterpret_cast<uint16_t*>(text_end - 2);
    *text16-- = kDigits00To99[digits];
    PRINT_PRINTED;
    value /= 100;
    length -= 2;
    if (length & 1) goto OddLoop;
  } else {
    PRINTF("\n    B.) Range:[%u, %u] length:%u probablity:%f%%",
           1 << (kRangeShift[length - 2]), comparator, (uint)length,
           lower_probability);
    if (text + length >= text_end) {
      return nullptr;
    }
    text_end = text + length;
    value /= 100;
    text16 = reinterpret_cast<uint16_t*>(text_end - 2);
    *text16-- = kDigits00To99[digits];
    PRINT_PRINTED;
    length -= 2;
    if (length & 1) {
    OddLoop:
      PRINTF("\n\n    Odd modulo 100 loop with value:%u and length:%u", value,
             (uint)length);
      --length;
      while (length > 0) {
        index = value % 100;
        digits = kDigits00To99[index];
        *text16-- = digits;
        value /= 100;
        length -= 2;
        PRINTF("\n    [%u]:%c%c value:%u", (uint)length, (uint)index,
               (char)(digits >> 8), value);
        PRINT_PRINTED;
      }
      text = reinterpret_cast<char*>(text16) + 1;
      *text = (char)value + '0';
      PRINTF("\n    [%u]:%c final", (uint)length, (char)value + '0');
      PRINT_PRINTED;
      return text_end;
    }
  }

  PRINTF("\n\n    Even modulo 100 loop with value:%u and length:%u", value,
         (uint)length);
  length -= 2;
  while (length > 0) {
    index = value % 100;
    digits = kDigits00To99[value % 100];
    *text16-- = digits;
    value /= 100;
    length -= 2;
    PRINTF("\n    [%u]:%u", (uint)length, (uint)index);
    PRINT_PRINTED;
  }
  digits = kDigits00To99[value];
  *text16 = digits;
  PRINTF("\n    [%u]:%u final", (uint)length, (uint)value);
  PRINT_PRINTED;
  return text_end;
}

}  // namespace _
#undef PRINTF
#undef PRINT_PRINTED