#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#define LEN(arr) sizeof(arr) / sizeof(arr[0])

void repeat(char* buffer, char c, int amount);

int main() {
	int alphabets[26] = { 0 };

	int character;
	while ((character = getchar()) != EOF) {
		character = tolower(character);
		if (character >= 'a' && character <= 'z') {
			int alpha = (character - 'a') % (LEN(alphabets));
			alphabets[alpha]++;
		}
	}

	printf("\n");
	printf("HISTOGRAM - Alphabet Frequency\n");

	for (int i = 0; i < LEN(alphabets); i++) {
		char string[alphabets[i]];
		repeat(string, '*', alphabets[i]);
		printf("%c %s\n", i+'a', string);
	}

	return 0;
}

void repeat(char *buffer, char c, int amount) {
	if (buffer == NULL) {
		return;
	}
	for (int i = 0; i < amount; i++) {
		buffer[i] = c;
	}
	buffer[amount] = '\0';

	return;
}
