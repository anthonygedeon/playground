#include <stdio.h>

/* replce occurences of 'tab', 'backspace', '\'  with '\t' '', '\\' respectively */
void main(void) {
       int c;

        while((c = getchar()) != EOF) {
                if (c == '\t') {
                    printf("\\t");
                }
                if (c == '\b') {
                    printf("\\b");
                }
                if (c == '\\') {
                    printf("\\\\");
                }

                if (c != '\b') {
                        if (c != '\\') {
                                if (c != '\t') {
                                        putchar(c);
                                }
                        }
                }
        }
}
