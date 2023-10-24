#include <stdio.h>

int main(void) {
	printf("Enter amount of loan: ");
	float balance = 0.0;
	scanf("%f", &balance);

	printf("Enter interest rate: ");
	float interest = 0.0;
	scanf("%f", &interest);
	interest = (interest / 100.0f) / 12;

	printf("Enter monthly payment: ");
	float payment = 0.0;
	scanf("%f", &payment);
	
	balance = (balance - payment) + (balance * interest);
	printf("Balance remaining after first payment: %.2f\n", balance);

	balance = (balance - payment) + (balance * interest);
	printf("Balance remaining after second payment: %.2f\n", balance);

	balance = (balance - payment) + (balance * interest);
	printf("Balance remaining after third payment: %.2f\n", balance);

	return 0;
}
