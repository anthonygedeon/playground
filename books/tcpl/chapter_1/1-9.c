#include <stdio.h>

void main(void) {
        int c;
        int state = 0;

        while((c = getchar()) != EOF) {
                if (state == 1 && c == ' ') {
                        c = '\0';
                }

                if (c == ' ' || c == '\0') {
                        state = 1;
                } else {
                        state = 0;
                }

                putchar(c);
        }
}
