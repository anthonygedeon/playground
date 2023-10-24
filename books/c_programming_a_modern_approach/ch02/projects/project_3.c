#include <stdio.h>
#include <math.h>

int main(void) {
	int radius = 0;
	scanf("%i", &radius);
	float sphere_volume = 4.0f / 3.0 * M_PI * powf(radius, 3.0);
	printf("%f.2\n", sphere_volume);
	return 0;
}
