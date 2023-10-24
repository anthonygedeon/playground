#include <stdio.h>

int main(void) {
	int num1, num2, denom1, denom2, result_n, result_d;

	printf("Enter first fraction: ");
	scanf("%d / %d", &num1, &denom1);

	printf("Enter second fraction: ");
	scanf("%d / %d", &num2, &denom2);

	result_n = num1*denom2 + num2 * denom1;

	result_d = denom1 * denom2;
	printf("The sum is %d/%d\n", result_n, result_d);

	return 0;
}
