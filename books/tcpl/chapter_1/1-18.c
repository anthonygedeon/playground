#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 1024

// TODO: use putchar instead of %s
// TODO: remove isalpha and don't use A..Z, a..z
// TODO: possibly remove code for reseting the buffer?

void rtrim(char* buffer, int start);

int main() {
	int ptr = 0;
	char queue[MAX];
	
	int character;
	while ((character = getchar()) != EOF) { // and queue does not surpass MAX
		if (character != '\n') {
			queue[ptr] = character;
			ptr += 1;
		}

		if (character == '\n') {
			rtrim(queue, ptr);
			printf("%s|\n", queue); // vertical bar used for debugging

			// reset the queue 
			for (int i = 0; i < MAX; i++) {
				queue[i] = '\0';
			}
			ptr = 0;
		}
	}

	return EXIT_SUCCESS;
}

// Trim trailing whitespace from buffer
void rtrim(char* buffer, int start) {
	for (int i = start; !isalpha(buffer[i]); i -= 1) {
		if (buffer[i] == ' ' || buffer[i] == '\t') {
			buffer[i] = '\0';
		} 			
	}
}
