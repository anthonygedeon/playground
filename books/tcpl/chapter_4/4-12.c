#include <stdio.h>

#define MAXLEN 100

void itoa(int num, char s[]) {
	static int i = 0;

	if (num < 0) {
		*(s++) = '-';
		num = -num;
	}

	if (num / 10)
		itoa(num / 10, s);

	s[i++] = num % 10 + '0';

	s[i] = '\0';
}


int main(void) {
	char buffer[MAXLEN];
	itoa(123, buffer);
	printf("%s\n", buffer);
	return 0;
}
