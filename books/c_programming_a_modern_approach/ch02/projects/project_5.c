#include <stdio.h>

int main(void) {
	int x = 0;
	scanf("%i", &x);
	int polynomial = 3 * (x * x * x * x * x) +
		2 * (x * x * x * x) -
		5 * (x * x * x) -
		(x * x) + 7 * x - 6; 

	printf("%i\n", polynomial);
	return 0;
}
