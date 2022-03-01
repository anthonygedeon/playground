#include <stdio.h>

void main(void) {
    int c;    
    int space_c = 0;
    int tab_c = 0;
    int newline_c = 0;
       
    while((c = getchar()) != EOF) {
        if (c == '\n') {
            ++newline_c;
        }

        if (c == '\t') {
            ++tab_c;
        }

        if (c == ' ') {
            ++space_c;
        }
    }

    printf("Space: %d  New line: %d Tab: %d\n", space_c, newline_c, tab_c);
}
