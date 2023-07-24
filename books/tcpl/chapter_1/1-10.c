// Write a program to copy its input to its output, replacing each tab by \t , 
// each backspace by \b , and each backslash by \\ . 
// This makes tabs and backspaces visible in an unambiguous way.

#include <stdio.h>
int main() {
  int can_print_char = 1;
  
  int ch;
  while ((ch = getchar()) != EOF) {
    if (ch == ' ') {
      putchar('\\');
      putchar('b');
      can_print_char = 0;
    } 
    if (ch == '\t') {
      putchar('\\');
      putchar('t');
      can_print_char = 0;
    } 
    if (ch == '\\') {
      putchar('\\');
      putchar('\\');
      can_print_char = 0;
    } 
    if (can_print_char == 1) {
      putchar(ch);
    } 
    can_print_char = 1; // reset
  } 
  return 0;
}