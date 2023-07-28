#include <stdio.h>
#include <stdlib.h>

#define MAX 80

static int flag = 1;

void reverse(char* string);
void get_line(char s[], int lim);

int main() {
	char string[MAX];

	while (flag) {
		get_line(string, MAX);
		reverse(string);
	}

	return EXIT_SUCCESS;
}

void get_line(char s[], int lim) {
	int c, i;

	for (i = 0; i < lim-1 && (c=getchar()) != EOF; i += 1) {
		s[i] = c;
	}

	s[i] = '\0';

	if (c == EOF) {
		flag = 0;
	}
}

void reverse(char* string) {
	int len = 0;
	while (string[len] != '\0') {
		len++;
	}

	for (int i = len; i >= 0; i -= 1) {
		printf("%c", string[i]);
	}

	printf("\n");
}
