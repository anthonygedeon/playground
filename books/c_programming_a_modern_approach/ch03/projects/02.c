#include <stdio.h>

int main(void) {
	printf("Enter item number: ");
	int item_number = 0;
	scanf("%d", &item_number);

	printf("Enter unit price: ");
	float unit_price = 0;
	scanf("%f", &unit_price);

	printf("Enter a date (mm/dd/yy): ");
	int date_mm = 0, date_dd = 0, date_yy = 0;
	scanf("%d/%d/%d", &date_mm, &date_dd, &date_yy);

	printf("Item		Unit Price		Purchase Date\n");
	printf("%-6d		$%6.2f			%d/%d/%d\n", 
			item_number, unit_price, date_mm, date_dd, date_yy);

	return 0;
}
