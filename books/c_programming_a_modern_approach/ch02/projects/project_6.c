#include <stdio.h>

int main(void) {
	int x = 0;
	scanf("%i", &x);
	int polynomial = (((3 * x + 2) * x - 5) * x + 7) * x - 6;
	printf("%i\n", polynomial);

	return 0;
}
