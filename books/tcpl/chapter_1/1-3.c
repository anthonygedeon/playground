#include <stdio.h>                                              

void main() {
       float fahr;
       float celsius;
        
       int lower = 0;
       int upper = 300;
       int step = 20;

       fahr = lower;
       printf("|-------------------|\n");
       // headers
       printf("|-------------------|\n");
       while (fahr <= upper) {
                celsius = (5.0 / 9.0) * (fahr-32.0);
                printf("|%3.0f\t%12.5f|\n", fahr, celsius);
                fahr = fahr + step;
       }
}
