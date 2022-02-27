#include <stdio.h>

// In C, instead of using true and false for conditions, it uses 0 and 1.
void main(void) {
        int c;
        
        while(c = getchar() != EOF) // c = getchar() != EOF is c = (getchar() != EOF)
            printf("%d\n", c);
       printf("%d - at EOF\n", c);
}
