#include <stdio.h>

int main(void) {
	// 821 => 128
	printf("Enter a three-digit number: ");
	int number;
	scanf("%d", &number);

	int last_digit = number % 10;
	int first_digit = number % 100 / 10;
	int second_digit = number / 100;
	printf("The reversal is: %d%d%d\n", last_digit, first_digit, second_digit);
	return 0;
}
