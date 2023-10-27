#include <stdio.h>

int main(void) {
	printf("Enter wind speed (int knots): ");
	int knots;
	scanf("%d", &knots);

	if (knots > 63) {
		printf("Hurricane\n");
	} else if (knots >= 48) {
		printf("Storm\n");
	} else if (knots >= 28) {
		printf("Gale\n");
	} else if (knots >= 4) {
		printf("Breeze\n");
	} else if (knots >= 1) {
		printf("Light air\n");
	} else {
		printf("Calm\n");
	}

	return 0;
}
