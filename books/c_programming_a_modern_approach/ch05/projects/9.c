#include <stdio.h>

int main(void) {
	printf("Enter first date (mm/dd/yy): ");

	int date_mm_1 = 0, date_dd_1 = 0, date_yy_1 = 0;
	scanf("%d/%d/%d", &date_mm_1, &date_dd_1, &date_yy_1);

	printf("Enter second date (mm/dd/yy): ");
	int date_mm_2 = 0, date_dd_2 = 0, date_yy_2 = 0;
	scanf("%d/%d/%d", &date_mm_2, &date_dd_2, &date_yy_2);
	
	if (date_yy_1 > date_yy_2) {
		printf("%d/%d/%d is earlier than %d/%d/%d", 
				date_mm_2, date_dd_2, date_yy_2, date_mm_1, date_dd_1, date_yy_1);
	} else {
		printf("%d/%d/%d is earlier than %d/%d/%d", 
				date_mm_1, date_dd_1, date_yy_1, date_mm_2, date_dd_2, date_yy_2);

	}

	return 0;
}
