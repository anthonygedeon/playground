#include <stdio.h>

#define MAXLINE 10

int get_line(char line[], int maxline);
void copy(char to[], char from[]);

int main() {
	int len = 0;
	int max = 0;
	char line[MAXLINE];
	char longest[MAXLINE];
	
	int c;
	while ((len = get_line(line, MAXLINE)) > 0) {
		while ((c = getchar()) != EOF && c != '\n') {
			len += 1;
		}

		if (len > max) {
			max = len;
			copy(longest, line);
		}
	}

	if (max > 0) {
		printf("Longest line with %i characters:\n%s ...\n", max, longest);
	}

	return 0;
}

int get_line(char s[], int lim) {
	int c, i;

	for (i = 0; i < lim-1 && (c=getchar()) != EOF && c != '\n'; i += 1) {
		s[i] = c;
	}
	if (c == '\n') {
		s[i] = c;
		i += 1;
	}
	s[i] = '\0';

	return i;
}

void copy(char to[], char from[]) {
	int i = 0 ;
	while ((to[i] = from[i]) != '\0') 
		++i;
}
