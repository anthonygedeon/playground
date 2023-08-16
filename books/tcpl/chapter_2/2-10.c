#include <stdio.h>

int lower(int c);

int main(void) {
  printf("Lowercase: %c\n", lower('H'));
  return 0;
}

int lower(int c) {
  return (c >= 'A' && c <= 'Z') ? ((c - 'A') % 65) + 'a' : c;
}
