#include <stdio.h>

#define MAX_F 300

float f_to_c(float f);

int main() {
  float celsius;                             
  for (int i = MAX_F; i > 0; i -= 20) {
     celsius = f_to_c(i);
     printf("%3.0d\t%.1f\n", i, celsius);      
  }
}                                                       

float f_to_c(float f) {
	return (5.0/9.0) * (f-32.0);
}
