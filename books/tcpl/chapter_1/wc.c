#include <stdio.h>

int main() {
  int nl = 0;
  int nc = 0;
  int nw = 0;

  int is_word = 0;
  int escapes = 0;

  int c;
  while ((c = getchar()) != EOF) {
    if (c == '\n') {
      nl += 1;
    }

    if (c == '\n' || c == '\t' || c == ' ') {
      is_word = 1;
      escapes += 1;
    } else if (c != '\n' && c != '\t' && c != ' ') {
      is_word = 0;
      escapes = 0;
    }

    // BUG: When string starts with a space, it counts as a word => " This is a word" Words: 5
    if (is_word && escapes == 1) {
      nw += 1;
    }
    nc += 1;
  }

  printf("Newlines: %i\tWords: %i\tChars: %i\n", nl, nw, nc);

  return 0;
}