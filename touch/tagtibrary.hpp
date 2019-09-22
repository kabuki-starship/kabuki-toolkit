/* Kabuki Toolkit @version 0.x
@link    https://github.com/kabuki-starship/kabuki.toolkit.git
@file    /touch/taglibrary.hpp
@author  Cale McCollough <https://calemccollough.github.io>
@license Copyright (C) 2014-9 Cale McCollough; all right reserved (R). 
This Source Code Form is subject to the terms of the Mozilla Public License, 
v. 2.0. If a copy of the MPL was not distributed with this file, You can 
obtain one at https://mozilla.org/MPL/2.0/. */

#pragma once
#include <module_config.h>
#if SEAM >= KABUKI_TOOLKIT_AV_1
#ifndef KABUKI_TOOLKIT_AV_TAGLIBRARY
#define KABUKI_TOOLKIT_AV_TAGLIBRARY

#include "tag.hpp"

namespace _ {

/* A container of Strings sorted alphabetically.
    This object owns the memory for the Strings. Each time a patch is added,
    each tag is added, a pointer to the CH1 is passed back.
*/
class TagLibrary {
 public:
  /* Creates an empty tag library. */
  TagLibrary();

  /* Gets the tag CH1, and adds it to the collection if it doesn't exist.
      @return Gets null if the tags list doesn't contain the Tag, and
          non-null if the Tag was added successfully. */
  CH1 GetOrAddTag(CH1 tag) {
    /*
    if (StringCompare (tag, ""))
        return nullptr;
    for_each (tags.begin (), tags.end (), [] (TStrand<>& AString) {
        if (AString.compare (Tag) == 0) return AString;
    });
    */
    return nullptr;
  }

  /* Sorts the tags alphabetically for fast binary search. */
  void Sort() {
    // sort (tags_.begin (), tags_.end ());
  }

  /* Gets the number of tags. */
  SI4 GetNumTags() { return tags_.count; }

  /* Prints this object to a Expr. */
  template<typename Printer>
  Printer& Print(Printer& o) { o << "\nFoo:"; }

 private:
  TArray<Tag*> tags_;  //< Collection of tag Strings.
};
}       // namespace _
#endif  //< KABUKI_TOOLKIT_AV_TAGLIBRARY
#endif  //< #if SEAM >= KABUKI_TOOLKIT_AV_1