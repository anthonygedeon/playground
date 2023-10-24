#include <stdio.h>

int main(void) {
	int prefix = 0;
	int identifier = 0;
	int code = 0;
	int item = 0;
	int check = 0;
	printf("Enter ISBN: ");
	scanf("%d-%d-%d-%d-%d", &prefix, &identifier, &code, &item, &check);
	
	printf("GS1 prefix: %i\n", prefix);
	printf("Group identifier: %i\n", identifier);
	printf("Publisher code: %i\n", code);
	printf("Item number: %i\n", item);
	printf("Check digit: %i\n", check);

	return 0;
}
