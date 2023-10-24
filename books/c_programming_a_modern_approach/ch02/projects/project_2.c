#include <stdio.h>
#include <math.h>

int main(void) {
	float sphere_volume = 4.0f / 3.0 * M_PI * powf(10, 3.0);
	printf("%f.2\n", sphere_volume);
	return 0;
}
