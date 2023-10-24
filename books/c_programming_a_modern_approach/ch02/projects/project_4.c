#include <stdio.h>

#define SALES_TAX 5

int main(void) {
	printf("Enter an amount: ");
	float amount = 0;
	scanf("%f", &amount);
	float tax = amount * SALES_TAX / 100.0;
	printf("Wit tax added: $%.2f\n", amount + tax);

	return 0;
}
