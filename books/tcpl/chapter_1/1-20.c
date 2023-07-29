#include <stdio.h>
#include <stdlib.h>

#define TABSTOP 8

int main() {
	int pos = 0;
	int character;
	while ((character = getchar()) != EOF) {
		if (character == '\t')	{
			for (pos = (pos % TABSTOP); pos < TABSTOP; pos += 1) {
				putchar('.');
			}
		} else if (character == '\n') {
			putchar('\n');
			pos = 0;
		} else {
			putchar(character);
			pos = 1 + (pos % TABSTOP);
		}
	}

	return EXIT_FAILURE;
}

// Q: Should n be a variable or a symbolic parameter?
// A: A variable due to variables having more flexibility than symbolic parameters 
