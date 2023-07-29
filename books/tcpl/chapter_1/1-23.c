#include <stdio.h>
#include <stdlib.h>

int main() {
	int state = 0;
	int c;
	while ((c = getchar()) != EOF) {

		if (c == '/') {
			state = 1; // lock state
		}

		if (c == '\n' && state == 1) {
			state = 0;
		}
		
		if (state == 0) {
			putchar(c);
		}
	}

	return EXIT_SUCCESS;
}
