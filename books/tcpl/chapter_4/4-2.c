#include <ctype.h>
#include <math.h>
#include <stdio.h>

#define MAXLINE 1000

double atof(char s[]);

double atof(char s[]) {
	double val, power;
	int i, sign, base;
	int s_sign;
	int is_scientific = 0;
	
	for (i = 0; isspace(s[i]); i++) {
		;
	}
	sign = (s[i] == '-') ? -1 : 1;
	if (s[i] == '+' || s[i] == '-') {
		i++;
	}
	for (val = 0.0; isdigit(s[i]); i++) {
		val = 10.0 * val + (s[i] - '0');
	}
	if (s[i] == '.') {
		i++;
	}
	for (power = 1.0; isdigit(s[i]); i++) {
		val = 10.0 * val + (s[i] - '0');
		power *= 10.0;
	}
	if (s[i] == 'e' || s[i] == 'E') {
		i++;
		is_scientific = 1;
	}

	s_sign = (s[i] == '-') ? -1 : 1;
	if (s[i] == '+' || s[i] == '-') {
		i++;
	}

	for (base = 0; isdigit(s[i]); i++) {
		base = 10.0 * base + (s[i] - '0');
	}

	if (is_scientific) {
		return (sign * val / power) * pow(10.0, (s_sign) * (double)base);
	}

	return sign * val / power;
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

int main(void) {
	char line[MAXLINE];
	
	double sum = 0;
	while (my_getline(line, MAXLINE) > 0 ) {
		printf("\t%g\n", sum += atof(line));
	}

	return 0;
}
