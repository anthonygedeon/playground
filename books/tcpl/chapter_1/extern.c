
#include <stdio.h>

#define MAXLINE 1000

extern char line[MAXLINE];
extern char longest[MAXLINE];

int max;
char line[MAXLINE];
char longest[MAXLINE];

int get_line(void);
void copy(void);

int main() {
	int len;

	max = 0;
	while ((len = get_line()) > 0) {
		if (len > max) {
			max = len;
			copy();
		}
	}
	if (max > 0) {
		printf("%s", longest);
	}
	return 0;
}

int get_line() {
	int c, i;

	for (i = 0; i < MAXLINE-1 && (c=getchar()) != EOF && c != '\n'; i += 1) {
		line[i] = c;
	}
	if (c == '\n') {
		line[i] = c;
		i += 1;
	}
	line[i] = '\0';
	return i;
}

void copy() {
	int i = 0;
	
	while ((longest[i] = line[i]) != '\0') {
		i += 1;
	}
}
