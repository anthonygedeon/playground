#include <stdio.h>

void main(void) {
    int c;

    while((c = getchar()) != EOF) {

        if (c != ' ' && c != '\n' && c != '\t') {
                putchar(c);
        } else {
                printf("\n");
        }
            
    }

}
