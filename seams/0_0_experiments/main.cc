#include <stdafx.h>
#include <cstdio>
#include <iostream>

using namespace std;

namespace _ {
/* Converts int main(int,char**) arguments back into a string.
@return false if there are no args to convert.
@param arg_count The number of arguments.
@param args      The arguments. */
bool ArgsToString(int args_count, char** args) {
  if (args_count <= 1) return false;
  if (args_count == 2) return true;
  for (int i = 2; i < args_count; ++i) {
    char* cursor = args[i];
    while (*cursor) cursor--;
    *cursor = ' ';
  }
  return true;
}
}  // namespace _

int main(int args_count, char** args) {
  cout << "\n\nTesting ArgsToString...\n";

  if (args_count <= 1) return 1;
  cout << "\nArguments:\n";
  for (int i = 0; i < args_count; ++i) {
    char* arg = args[i];
    printf("\ni:%i\"%s\" 0x%p", i, arg, arg);
  }
  cout << "\n\nContiguous Args:\n";
  char* end = args[args_count - 1];
  while (*end) ++end;
  cout << "\n\nContiguous Args:\n";
  char* cursor = args[0];
  while (cursor != end) {
    char c = *cursor++;
    if (c == 0)
      cout << '`';
    else if (c < ' ')
      cout << '~';
    else
      cout << c;
  }
  cout << "\n\nPrinting argument string...\n";
  _::ArgsToString(args_count, args);
  cout << "\n" << args[1];
  return 0;
}
