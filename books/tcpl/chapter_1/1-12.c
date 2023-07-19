#include <stdio.h>

int main() {
  int is_locked = 1; // locked = 1, unlock = 0
  int is_word = 0;
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
      	printf("\n");
      }
    }
  }

  return 0;
}
