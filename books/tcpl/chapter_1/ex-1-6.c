#include <stdio.h>

int main() {
	int c;
	int i;
	int nwhite = 0;
	int nother = 0;
	int ndigit[10];

	for (i = 0; i < 10; ++i) {
		ndigit[i] = 0;
	}

	while ((c = getchar()) != EOF) {
		if (c >= '0' && c <= '9') {
			++ndigit[c-'0'];
		} else if (c == ' ' || c == '\n' || c == '\t') {
			++nwhite;
		} else {
			++nother;
		}
	}

	printf("digits = ");
	for (i = 0; i < 10; ++i) {
		printf(" %d", ndigit[i]);
	}
	printf(", white space = %d, nother = %d\n", nwhite, nother);

	return 0;

}
