#include <stdio.h>

#define MAXLINE 1000

int my_getline(char line[], int max);
int strindex(char source[], char searchfor[]);

char pattern[] = "ould";

int main() {
	char line[MAXLINE];
	int found = 0;

	int index;
	while (my_getline(line, MAXLINE) > 0) {
		if ((index = strindex(line, pattern)) >= 0) {
			printf("index: %i line: %s", index, line);
			found++;
		}
	}

	return found;
}

int my_getline(char s[], int lim) {
	int c, i;

	i = 0;
	while (--lim > 0 && (c=getchar()) != EOF && c != '\n') {
		s[i++] = c;
	}
	if (c == '\n') {
		s[i++] = c;
	}
	s[i] = '\0';
	return i;
}

int strindex(char s[], char t[]) {
	int last = -1;

	int i, j, k;
	for (i = 0; s[i] != '\0'; i++) {
		for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++) { // increments k once the pattern starts
			;
		}

		if (k > 0 && t[k] == '\0') { // checks to see if pattern has been iterated entirely
			last = i;
		}

	}

	return last;
}
