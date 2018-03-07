/** Kabuki Toolkit
    @version 0.x
    @file    ~/source/crabs/clock.h
    @author  Cale McCollough <cale.mccollough@gmail.com>
    @license Copyright (C) 2017-2018 Cale McCollough <calemccollough@gmail.com>;
             All right reserved (R). Licensed under the Apache License, Version 
             2.0 (the "License"); you may not use this file except in 
             compliance with the License. You may obtain a copy of the License 
             [here](http://www.apache.org/licenses/LICENSE-2.0). Unless C
             required by applicable law or agreed to in writing, software
             distributed under the License is distributed on an "AS IS" BASIS,
             WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or 
             implied. See the License for the specific language governing 
             permissions and limitations under the License.
*/

#pragma once
#include <stdafx.h>

#ifndef HEADER_FOR_CRABS_CLOCK
#define HEADER_FOR_CRABS_CLOCK

#include "memory.h"

#if MAJOR_SEAM >= 1 && MINOR_SEAM >= 3

/** Reads a time or time delta from a a char starting with an '@' sign..
    @param input  The char to parse.
    @param hour   The location to write the number of hours to.
    @param minute The location to write the number of minutes to.
    @param Second The location to write the number of seconds to.
    @return The offset The end of where the parser exited successfully at.

    @code
    @4        (This is 4AM)
    @4PM      (No space required)
    @4:20P    (Or M)
    @4:20 PM
    @16:20
    @4:20 am
    @4:20a.m.
    @4:20:00
    @4:20:00AM
    @16:20:00
    @endcode

KABUKI const char* TextReadTime (const char* input, int* hour, int* minute,
                                  int* second);*/

/** Converts a keyboard input to char and deletes the char. 

KABUKI const char* TextReadTime (const char* input, tm* std_tm);*/

/** Converts a keyboard input to a time_t.
KABUKI const char* TextReadTime (const char* input, time_t& result); */

/** Converts a keyboard input to a time_t.
KABUKI char* TextReadTime (char* input, time_t& result); */

/** Writes the given std_tm to the char buffer.
KABUKI char* TextWriteTime (char* text, char* end, tm* std_tm); */

/** Writes the given time to the char buffer.
KABUKI char* TextWriteTime (char* text, char* end, time_t t); */

namespace _ {

/** Creates a timestamp of the current time. */

enum {
    kNumSecondsMin     = 60 * 60,
    kNumSecondsMinute = 60 * kNumSecondsMin,
    kNumSecondsPerDay = 24 * kNumSecondsMinute,
    kTimeEpoch = 1900,
};

/** Gets the current microsecond timestamp. */
inline time_us_t ClockTimestampNow () {
    //std::chrono::microseconds us (1);
    //chrono_timestamp ts = time_point_cast<microseconds>(system_clock::now ());
    return 0;
}



#if USING_TEXT_SCRIPT

/** Portable std::tm. */
KABUKI std::tm* ClockLocalTime (std::tm* std_tm, std::time_t const& time);

/** Generates a timestamp from a Unix timestamp and 32-bit microsecond
    timestamp.
*/
KABUKI time_us_t ClockPackTimestamp (time_t unixTime, int32_t microseconds);

/** Gets the seconds since January 1, 1970. */
KABUKI time_t ClockGetSeconds (time_us_t t);

/** Gets the microsecond time. */
KABUKI int32_t ClockGetMicroseconds (time_us_t timestamp);

/** Gets the number of days in a months. 
    @todo Maybe get some open-source date utility? */
KABUKI int ClockNumDaysMonth (time_t t);

/** Gets the number of days in a months. 
    @param month The month index 0-11.
    @param year   */
KABUKI int ClockNumDaysMonth (int month, int year = 1);

/** Gets the abbreviated day of the week char of the given day number 1-7. */ 
KABUKI const char* ClockDayOfWeek (int day_number);

/** Gets the abbreviated day of the week char of the given day number 1-7. */ 
KABUKI char ClockDayOfWeekInitial (int day_number);

/** Compares the two the time and prints the results. */
KABUKI int ClockCompareTimes (time_t time_a, time_t time_b);

/** Compares the given time_t to the time and prints the results. */
KABUKI int ClockCompareTimes (time_t t, int year, int month, int day,
                              int hour, int minute, int second);

/** Zeros out the calendar_time struct.
    @param calendar_time A calendar time struct to zero out. */
KABUKI void ClockZeroTime (tm* std_tm);

#endif  //< #if USING_TEXT_SCRIPT

KABUKI time_t ClockTime (int year, int month, int day, int  hour = 0,
                         int minute = 0, int second = 0);

}       //< namespace _
#endif  //< #if MAJOR_SEAM >= 1 && MINOR_SEAM >= 3
#endif  //< HEADER_FOR_CRABS_CLOCK

/*
HANDLE gDoneEvent;

VOID CALLBACK TimerRoutine(PVOID lpParam, BOOLEAN TimerOrWaitFired)
{
    if (lpParam == NULL)
    {
        printf("TimerRoutine lpParam is NULL\n");
    }
    else
    {
        // lpParam points to the argument; in this case it is an int

        printf("Timer routine called. Parameter is %d.\n", 
                *(int*)lpParam);
        if(TimerOrWaitFired)
        {
            printf("The wait timed out.\n");
        }
        else
        {
            printf("The wait event was signaled.\n");
        }
    }

    SetEvent(gDoneEvent);
}

int main()
{
    HANDLE hTimer = NULL;
    HANDLE hTimerQueue = NULL;
    int arg = 123;

    // Use an event object to track the TimerRoutine execution
    gDoneEvent = CreateEvent(NULL, TRUE, FALSE, NULL);
    if (NULL == gDoneEvent)
    {
        printf("CreateEvent failed (%d)\n", GetLastError());
        return 1;
    }

    // Create the timer queue.
    hTimerQueue = CreateTimerQueue();
    if (NULL == hTimerQueue)
    {
        printf("CreateTimerQueue failed (%d)\n", GetLastError());
        return 2;
    }

    // Set a timer to call the timer routine in 10 seconds.
    if (!CreateTimerQueueTimer( &hTimer, hTimerQueue, 
            (WAITORTIMERCALLBACK)TimerRoutine, &arg , 10000, 0, 0))
    {
        printf("CreateTimerQueueTimer failed (%d)\n", GetLastError());
        return 3;
    }

    // TODO: Do other useful work here 

    printf("Call timer routine in 10 seconds...\n");

    // Wait for the timer-queue thread to complete using an event 
    // object. The thread will signal the event at that time.

    if (WaitForSingleObject(gDoneEvent, INFINITE) != WAIT_OBJECT_0)
        printf("WaitForSingleObject failed (%d)\n", GetLastError());

    CloseHandle(gDoneEvent);

    // Delete all timers in the timer queue.
    if (!DeleteTimerQueue(hTimerQueue))
        printf("DeleteTimerQueue failed (%d)\n", GetLastError());

    return 0;
}


template<uint year, uint month, uint day, uint  hour = 0, uint minute = 0,
    uint second = 0>
    time_t TestTime (char* buffer, int buffer_size) {
    if (buffer == nullptr)
        return 0;
    time_t t;
    time (&t);
    tm* moment = localtime (&t);
    if (!moment) {
        std::cout << "\n\n Created invalid test moment: " << moment << '\n';
        return 0;
    }
    moment->tm_year = year - kTimeEpoch;
    moment->tm_mon = month - 1;
    moment->tm_mday = day;
    moment->tm_hour = hour;
    moment->tm_min = minute;
    moment->tm_sec = second;

    if (!PrintDateTimeText (buffer, buffer_size, moment)) {
        std::cout << "\nError making timestamp";

        return 0;
    }
    std::cout << "< Creating test time: ";
    PrintDateTime (moment);
    t = mktime (moment);
    if (t < 0) {
        std::cout << "< Invalid " << t << '\n';
        return 0;
    } else {
        std::cout << '\n';
    }
    return t;
}*/