#include <stdio.h>

int main(void) {
	printf("Enter a 24-hour time: ");
	int hh, mm;
	scanf("%d:%d", &hh, &mm);

	printf("Equivalent 12-hour time: ");
	
	if (hh == 24) {
		printf("%.2d:%.2d PM\n", 12, mm);
	} else if (hh >= 12) {
		printf("%.2d:%.2d PM\n", hh % 12, mm);
	} else {
		printf("%.2d:%.2d AM\n", hh , mm);
	}

	return 0;
}
