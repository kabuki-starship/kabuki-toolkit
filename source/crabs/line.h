/** Kabuki Toolkit
    @version 0.x
    @file    ~/source/crabs/hex.h
    @author  Cale McCollough <cale.mccollough@gmail.com>
    @license Copyright (C) 2017-2018 Cale McCollough <calemccollough@gmail.com>;
             All right reserved (R). Licensed under the Apache License, Version 
             2.0 (the "License"); you may not use this file except in 
             compliance with the License. You may obtain a copy of the License 
             [here](http://www.apache.org/licenses/LICENSE-2.0). Unless 
             required by applicable law or agreed to in writing, software
             distributed under the License is distributed on an "AS IS" BASIS,
             WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or 
             implied. See the License for the specific language governing 
             permissions and limitations under the License.
*/

#pragma once
#include <stdafx.h>
#if MAJOR_SEAM >= 1 && MINOR_SEAM >= 3

#ifndef HEADER_FOR_CRABS_LINE
#define HEADER_FOR_CRABS_LINE

#include "print.h"
#include "slot.h"


namespace _ {

/** Utility class for printing a text line with operator<<. */
class Line {
    public:

    int  column_count; //< Column count.
    char token;        //< Character to print.

    /** Constructor. */
    Line (char token, int column_count);
};

}       //< namespace _

inline _::Printer& operator<< (_::Printer& print, _::Line line) {
    char* cursor = _::PrintLine (line.token, line.column_count, print.cursor,
                                 print.end);
    if (!cursor)
        return print;
    print.cursor = cursor;
    return print;
}

#endif  //< HEADER_FOR_CRABS_LINE
#endif  //< MAJOR_SEAM >= 1 && MINOR_SEAM >= 3
