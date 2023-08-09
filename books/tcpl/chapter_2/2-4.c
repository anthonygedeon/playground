#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void squeeze2(char s1[], char s2[]);

int main(void) {

  char a[] = "racecar";
  char b[] = "bumblebee";
  squeeze2(a, b);

  printf("%s\n", a);

  return EXIT_SUCCESS;
}

void squeeze2(char s1[], char s2[]) {
  int i;
  int j;

  for (i = 0, j = 0; s1[i] != '\0'; i++) {
  int matched = 1;
    for (int k = 0; s2[k] != '\0'; k++) {
      if (s1[i] == s2[k]) {
        matched = 0;
      }
    }
    if (matched) {
      s1[j++] = s1[i];
    }
  }

  s1[j] = '\0';
}
