#include <stdio.h>

#define TWENTY_BILL 20
#define TEN_BILL 10
#define FIVE_BILL 5
#define ONE_BILL 1

int main(void) {
	printf("Enter a dollar amount: ");
	int amount = 0;
	scanf("%i", &amount);

	int a = amount / TWENTY_BILL;
	int aa = a * TWENTY_BILL;
	int aaa = amount - aa;
	amount = aaa;

	int b = amount / TEN_BILL;
	int bb = b * TEN_BILL;
	int bbb = amount - bb;
	amount = bbb;

	int c = amount / FIVE_BILL;
	int cc = c * FIVE_BILL;
	int ccc = amount - cc;
	amount = ccc;

	int d = amount / ONE_BILL;
	int dd = d * ONE_BILL;
	int ddd = amount - dd;

	printf("$20 Bills: %i\n", a);
	printf("$10 Bills: %i\n", b);
	printf("$5 Bills: %i\n", c);
	printf("$1 Bills: %i\n", d);

	return 0;
}
