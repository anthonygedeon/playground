// Write a program to copy its input to its output, replacing
// each string of one or more blanks by a single blank.

#include <stdio.h>

int main() {
  int is_locked = 1; // locked = 1, unlock = 0
  int ch;
  while ((ch = getchar()) != EOF) {
    // unlock: can print characters again
    if (ch != ' ') {
      is_locked = 1;
    }

    if (is_locked == 1) {
      printf("%c", ch);
      // lock: no longer can print blanks after the first blank
      if (ch == ' ') {
        is_locked = 0;
      }
    }
  }

  return 0;
}