#include <stdio.h>

int main() {
  // count the total amount for ' ', '\t', '\n'
  int c;

  int nw, nt, nb;
  while((c = getchar()) != EOF) {
    if (c == '\n') 
      nw += 1;
    if (c == ' ') 
      nb += 1;
    if (c == '\t') 
      nt += 1;
  }
  printf("Lines: %i, Tabs: %i, Spaces: %i\n", nw, nt, nb);
  
  return 0;
}