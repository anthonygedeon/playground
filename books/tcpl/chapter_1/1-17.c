#include <stdio.h>
#include <string.h>

#define MAXLINE 1000

int get_line(char line[], int maxline);
void copy(char to[], char from[]);

int main() {
	int len;
	int max;
	char line[MAXLINE];
	char longest[MAXLINE][MAXLINE];
	
	int counter = 0;
	while ((len = get_line(line, MAXLINE)) > 0) {
		if (len >= 80) {
			copy(longest[counter], line);
		}
		counter += 1;	
	}

	printf("Output: \n");
	if (max >= 0) {
		for (int i = 0; i < counter; i++) {
			for (int j = 0; j < strlen(longest[i]); j++) {
				printf("%c", longest[i][j]);
			}
		}
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
	int i = 0;
	for (i = 0; from[i] != '\0'; i += 1) {
		to[i] = from[i];
	}
	i++;
	to[i] = '\0';
}
