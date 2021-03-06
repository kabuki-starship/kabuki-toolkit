/* Kabuki Toolkit @version 0.x
@link    https://github.com/KabukiStarship/KT.git
@file    /Pro/Git.hpp
@author  Cale McCollough <https://cookingwithcale.org>
@license Copyright (C) 2014-20 Cale McCollough; all right reserved (R).
This Source Code Form is subject to the terms of the Mozilla Public License,
v. 2.0. If a copy of the MPL was not distributed with this file, You can
obtain one at <https://mozilla.org/MPL/2.0/>. */
#pragma once
#include <_Config.h>
#if SEAM >= KABUKI_PRO_1
#ifndef KABUKI_TOOLKIT_PRO_GIT
#define KABUKI_TOOLKIT_PRO_GIT
namespace _ {

/* A git repoistory. */
class Git : public Operand {
  const CHA* repo_address_;

 public:
  Git();

  template <typename Printer>
  Printer& Print(Printer& o) {
    return o << "\nGit:";
  }

  /* Script2 operations. */
  virtual const Op* Star(wchar_t index, Expr* expr) {
    void* args[1];
    enum { kSize = 254 };
    CHA buffer[kSize + 1];
    switch (index) {
      case '?': {
        static const Op cThis = {"Sloth", OpFirst(' '), OpLast(' '), "git",
                                 '}',     ';',          ' ',         false,
                                 nullptr, nullptr,      nullptr};
        return &cThis;
      }
      case ' ': {
        static const Op kClone = {
            "clone", Params<1, TKN, 255>(),
            0,       "Push Operation that occurs upon updating the toolkit.",
            '}',     ';',
            ' ',     false,
            0,       0,
            0};
        if (!expr) return &kClone;
        Print(buffer, buffer + 255, "git clone ");
        if (!ExprArgs(expr, kClone, Args(args, &buffer[10])))
          return expr->result;
        system(&buffer[9]);
        return 0;
      }
    }
    return nullptr;
  }
};
}  // namespace _
#endif
#endif
