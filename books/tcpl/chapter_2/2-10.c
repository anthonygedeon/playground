#include <stdio.h>

int lower(int c);

int main(void) {
  printf("Lowercase: %c\n", lower('H'));
  return 0;
}

int lower(int c) {
 // if (c >= 'A' && c <= 'Z') {
 //   return ((c - 'A') % 65) + 'a';
 // } else if (c >= 'a' && c <= 'z') {
 //   return c;
 // }
  return (c >= 'A' && c <= 'Z') ? ((c - 'A') % 65) + 'a' : -1;
}
