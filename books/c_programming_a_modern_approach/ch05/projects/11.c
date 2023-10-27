#include <stdio.h>
#include <stdbool.h>

int main(void) {
	printf("Enter a two-digit number: ");
	int number;
	scanf("%d", &number);
	
	int left_digit  = number / 10;
	int right_digit = number % 10;
	bool is_teen_numbers = false;

	printf("You entered the number: ");

	switch(left_digit) {
		case 9: printf("ninety-"); break;
		case 8: printf("eighty-");break;
		case 7: printf("seventy-");break;
		case 6: printf("sixty-");break;
		case 5: printf("fifty-");break;
		case 4: printf("fourty-");break;
		case 3: printf("thirty-");break;
		case 2: printf("twenty-");break;
		case 1: 
			is_teen_numbers = true;
			switch(right_digit) {
				case 9: printf("nine-teen"); break;
				case 8: printf("eight-teen");break;
				case 7: printf("seven-teen");break;
				case 6: printf("six-teen");break;
				case 5: printf("fifth-teen");break;
				case 4: printf("four-teen");break;
				case 3: printf("thirteen");break;
				case 2: printf("twelve");break;
				case 1: printf("eleven");break;
				case 0: printf("ten");break;
			}

	}
	
	if (!is_teen_numbers) {
		switch(right_digit) {
			case 9: printf("nine"); break;
			case 8: printf("eight");break;
			case 7: printf("seven");break;
			case 6: printf("six");break;
			case 5: printf("five");break;
			case 4: printf("four");break;
			case 3: printf("three");break;
			case 2: printf("two");break;
			case 1: printf("one");break;
		}
	}

	printf(".\n");

	return 0;
}
