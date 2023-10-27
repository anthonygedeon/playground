#include <stdio.h>

int main(void) {
	printf("Enter a two-digit number: ");
	int number;
	scanf("%d", &number);

	int last_digit = number % 10;
	int first_digit = number / 10;
	printf("The reversal is: %d%d\n", last_digit, first_digit);
	return 0;
}
