#include <stdio.h>

#define MAX_F 300

#define F_TO_C(f) (5.0/9.0) * (f-32.0)

int main() {
  float celsius;                             
  for (int i = MAX_F; i > 0; i -= 20) {
     celsius = F_TO_C(i);
     printf("%3.0d\t%.1f\n", i, celsius);      
  }
}                                                       

