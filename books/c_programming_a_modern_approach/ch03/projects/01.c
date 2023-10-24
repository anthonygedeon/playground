#include <stdio.h>

int main(void) {
	printf("Enter a date (mm/dd/yy): ");

	int date_mm = 0, date_dd = 0, date_yy = 0;
	scanf("%d/%d/%d", &date_mm, &date_dd, &date_yy);
	printf("You entered the date %d%.2d%.2d\n", 
			date_yy, date_mm, date_dd);

	return 0;
}

