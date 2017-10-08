/** The Chinese Room
    @version 0.x
    @file    ~/source/kabuki/chinese_room/include/unityper.h
    @author  Cale McCollough <cale.mccollough@gmail.com>
    @license Copyright (C) 2017 Cale McCollough<calemccollough.github.io>.
                            All right reserved (R).
             Licensed under the Apache License, Version 2.0 (the "License"); 
             you may not use this file except in compliance with the License. 
             You may obtain a copy of the License at
                        http://www.apache.org/licenses/LICENSE-2.0
             Unless required by applicable law or agreed to in writing, software
             distributed under the License is distributed on an "AS IS" BASIS,
             WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or 
             implied. See the License for the specific language governing 
             permissions and limitations under the License.
*/

#ifndef CHINESE_ROOM_MONOID_H
#define CHINESE_ROOM_MONOID_H

#include "error.h"
#include "types.h"
#include "address.h"
#include "array.h"
#include "utils.h"

namespace _ {

/** Clears the ring buffer by writing zeros to it. */
KABUKI void MonoidClear (byte* const begin, uint_t rx_start, 
                         byte* start, byte* const stop,
                         byte* const end, uint_t size);

/** Calculates the used ring buffer space.
    @param  Start The start of the data.
    @param  Stop  The stop of the data.
    @param  Size The size of the buffer. */
KABUKI uint_t MonoidLength (byte* start, byte* stop, uint_t size);

/** Calculates the space left in the given ring buffer.
    @param  Start The start of the data.
    @param  Stop  The stop of the data.
    @param  Size  The size of the buffer. */
KABUKI uint_t MonoidSpace (byte* start, byte* stop, uint_t size);

/** Copies a block from a ring-buffer to the given destination. */
KABUKI byte* MonoidWrite (void* source, byte* const begin,
                          byte* const start, byte* const stop,
                          byte* const end, size_t size);

/** Copies a block from a ring-buffer to the given destination. */
KABUKI byte* MonoidRead (void* destination, byte* const begin,
                         byte* const start, byte* const stop,
                         byte* const end, size_t size);

/** Copies a block from a ring-buffer to the given destination. */
KABUKI byte* SocketWrite (void* source, byte* const begin,
                          byte* const start, byte* const stop,
                          byte* const end, size_t size);

/** Copies a block from a ring-buffer to the given destination. */
KABUKI byte* MonoidRead (void* destination, byte* const begin,
                         byte* const start, byte* const stop,
                         byte* const end, size_t size);

/** A Tx ring-buffer.
    A sequence of A*B operations terminated by an ASCII CR char. All sequences get 
    evaluated down to an immutable set (by definition all sets are immutable), which 
    can be an empty set.

    # Monoid Format
    By default, all sequences are a set of one byte, all sets are linear, and all sets 
    may repeat.

    @code
    ESC VU8 1 BS CR
    @endcode
    A Tx ring-buffer is identical in structure to an Rx ring-buffer, but the stop becomes
    volatile and start is not volatile. */
struct Monoid {
    uint_t size;            //< The size of the monoid ring buffers.
    volatile uint_t start;  //< The starting index of the ring-buffer data.
    uint_t stop,            //< The stopping index of the ring-buffer data.
        read;               //< The address that the Rx device is reading from.
};

enum {
    kSlotHeaderSize = sizeof (Monoid) + sizeof (uintptr_t) -
    sizeof (Monoid) % sizeof (uintptr_t),
    //< Offset to the start of the ring buffer.
    kMinSocketSize = 32 + kSlotHeaderSize,
};

/** Gets the start of the Tx ring buffer. */
KABUKI byte* MonoidSlot (Monoid* tx);

KABUKI Monoid* MonoidInit (byte* buffer, uint_t size);

/** Initializes the tx buffer with the given buffer size. */
KABUKI Monoid* MonoidInit (Monoid* buffer, uint_t size);

/** Calculates the space left in the given ring buffer.
    @param  tx The Tx buffer. */
KABUKI uint_t MonoidSpace (Monoid* tx);

/** Gets the tx buffer space. */
KABUKI uint_t MonoidTxBufferLength (Monoid* tx);

/** Gets the end address of the tx buffer. */
KABUKI byte* MonoidEndAddress (Monoid* tx);

/** Prints a message with the given params to the given Tx slot.
    @param tx The Tx socket to write to.
    @param params The escape sequence to write.
    @param args The array of pointers to the stuff to write. */
KABUKI ticket_t Write (Monoid* tx, const char * address, const uint_t* params,
                       void** args);

/** Streams a tx byte.
    @param tx The tx monoid. */
KABUKI byte MonoidStreamByte (Monoid* tx);

/** Scans a message with the given params to the given Terminal.
    @param rx The monoid socket.
    @param params The parameters.
    @param args The arguments.
    @return Returns 0 upon success and an ErrorList ticket number upon failure. */
KABUKI ticket_t Read (Monoid* rx, const uint_t* params, void** args);

/** Prints the given Tx to the stdout. */
KABUKI void Print (Monoid* tx);

}       //< namespace _
#endif  //< CHINESE_ROOM_MONOID_H
