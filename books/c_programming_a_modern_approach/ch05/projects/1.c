#include <stdio.h>

int main(void) {
	printf("Enter a number: ");
	int digits;
	scanf("%d", &digits);
	
	int digit_count = 0;
	if (digits >= 100) {
		digit_count = 3;
	} else if (digits >= 10) {
		digit_count = 2;
	} else {
		digit_count = 1;
	}

	printf("The number %d has %d digits\n", digits, digit_count);

	return 0;
}
