#include <stdio.h>

int main(void) {
	printf("Enter numerical grade: ");
	int grade;
	scanf("%d", &grade);

	if (grade < 100 && grade >= 0) {
		printf("Letter grade: ");
		switch(grade / 10) {
			case 10: 
			case 9: printf("A"); break;
			case 8: printf("B"); break;
			case 7: printf("C"); break;
			case 6: printf("D"); break;
			case 5: case 4: case 3: case 2: case 1: 
			case 0: printf("F"); break;
		}
		printf("\n");
	} else {
		printf("Error: invalid grade\n");
	}

	return 0;
}
