#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int htoi(const char hex[]);

int main(void) {
	printf("%i", htoi("0x7DE"));
	printf("%i", htoi("0X7DE"));
	printf("%i", htoi("7de"));

	return EXIT_SUCCESS;
}

int htoi(const char hex[]) {
	
	int result = 0;
	for (int i = 0; i < strlen(hex) && hex[i] != '\0'; i += 1) {
		int hex_value = 0;
		int lower_hex = tolower(hex[i]);

		if (isdigit(lower_hex)) {
			hex_value = lower_hex - '0';
		} else if (isalpha(lower_hex)) {
			switch (lower_hex) {
				case 'a':
					hex_value = 10;
					break;
				case 'b':
					hex_value = 11;
					break;
				case 'c':
					hex_value = 12;
					break;
				case 'd':
					hex_value = 13;
					break;
				case 'e':
					hex_value = 14;
					break;
				case 'f':
					hex_value = 15;
					break;
			}
		}

		result += (hex_value * pow(16.0, (strlen(hex)-1)-i));
	}

	return result;
}
