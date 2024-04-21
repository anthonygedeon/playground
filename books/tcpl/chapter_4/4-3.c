#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXOP 100
#define MAXVAL 100
#define NUMBER '0'

#define BUFSIZE 100

char buf[BUFSIZE];
int bufp = 0;

int sp = 0;
double val[MAXVAL];

int getch(void);
void ungetch(int c);

int getop(char source[]);
void push(double operand);
double pop(void);

int getop(char source[]) {
	int i, c, sign;
	
	while ((source[0] = c = getch()) == ' ' || c == '\t')
		;

	source[1] = '\0';

	i = 0;
	if (c == '-') {
		if (!isdigit(source[++i] = c = getch())) {
			ungetch(c);
			return '-';
		}
	}

	if (!isdigit(c) && c != '.') {
		return c;
	}

	if (isdigit(c)) {
		while (isdigit(source[++i] = c = getch()))
			;
	}
	if (c == '.') {
		while (isdigit(source[++i] = c = getch()))
			;
	}

	source[i] = '\0';
	if (c != EOF) {
		ungetch(c);
	}

	return NUMBER;
}

int getch(void) {
	return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) {
	if (bufp >= BUFSIZE) {
		printf("ungetch: too many characters\n");
	} else {
		buf[bufp++] = c;
	}
}

void push(double operand) {
	if (sp < MAXVAL) {
		val[sp++] = operand;
	} else {
		printf("error: stack full, can't push %g\n", operand);
	}
}

double pop(void) {
	if (sp > 0) {
		return val[--sp];
	} else {
		printf("error: stack is empty\n");
		return 0.0;
	}
}

int main(void) {
	int type;
	double op2;
	char s[MAXOP];

	while ((type = getop(s)) != EOF) {
		switch (type) {
			case NUMBER:
				push(atof(s));
				break;
			case '+':
				push(pop() + pop());
				break;
			case '*':
				push(pop() * pop());
				break;
			case '%':
				op2 = pop();
				if (op2 != 0.0) {
					push((int)pop() % (int)op2);
				} else {
					printf("error: zero modulo\n");
				}
				break;
			case '-':
				op2 = pop();
				push(pop() - op2);
				break;
			case '/':
				op2 = pop();
				if (op2 != 0.0) {
					push(pop() / op2);
				} else {
					printf("error: zero divisor\n");
				}
				break;
			case '\n':
				printf("\t%.8g\n", pop());
				break;
			default:
				printf("error: unknown command %s\n", s);
				break;
		}
	}
	
	return 0;
}
