#include <stdio.h>

int main(void) {
	printf("Enter phone number [(xxx) xxx-xxxx]: ");
	int area_code = 0;
	int telephone_prefix = 0;
	int line_number = 0;
	scanf("(%d) %d-%d", &area_code, &telephone_prefix, &line_number);
	printf("You entered: %d.%d.%d\n", area_code, telephone_prefix, line_number);

	return 0;
}
