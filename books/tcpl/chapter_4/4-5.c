#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAXOP 100
#define MAXVAL 100
#define NUMBER '0'
#define IDENTIFIER 'a'
#define VARIABLE_SIZE 26

#define SIN "sin"
#define EXP "exp"
#define POW "pow"

#define BUFSIZE 100

int var;
double variables[VARIABLE_SIZE];
char pattern[3];
char buf[BUFSIZE];
int bufp = 0;

int sp = 0;
double val[MAXVAL];

int peek(void);
int getch(void);
void ungetch(int c);
int getop(char source[]);
void push(double operand);
double pop(void);
void showtop(void);
void duplicate(void);
void swap(void);
void clear(void);

void showtop(void) {
	printf("%g\n", val[sp-1]);
}

void swap(void) {
	double a = pop();
	double b = pop();
	push(a);
	push(b);
}

void duplicate(void) {
	double top = pop();
	push(top);
	push(top);
}

void clear(void) {
	sp = 0;
}

int getop(char source[]) {
	int i, c;

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

	if (isalpha(c)) {
		if (c >= 'a' && c <= 'z') {
			// this needs to know if there is a '=' 
			var = c;
			while ((c = getch()) != '=')
				;
			if (c == '=') {
				return '=';
			}

			return IDENTIFIER;
		}

		while (isalpha(source[++i] = c = getch())) 
			;

		source[i] = '\0';
		if (strcmp(source, SIN) == 0 || strcmp(source, EXP) == 0 || (strcmp(source, POW) == 0)) {
			strcpy(pattern, source);
			ungetch(c);
			return IDENTIFIER;
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
		// printf("[");
		// for (int i = 0; i < bufp; i++) {
		// 	printf(" %c ", buf[i]);
		// }
		// printf("]\n");
		switch (type) {
			case NUMBER:
				push(atof(s));
				break;
			case IDENTIFIER:
				if (strcmp(pattern, SIN) == 0) {
					double result = pop();
					push(sin(result));
				} else if (strcmp(pattern, EXP) == 0) {
					double result = pop();
					push(exp(result));
				} else if (strcmp(pattern, POW) == 0) {
					double power = pop();
					double base = pop();
					push(pow(base, power));
				} else {
					double item = variables[var - 'a'];
					printf("var %c = %g\n", var, item);
					push(item);
				}
				break;
			case '+':
				push(pop() + pop());
				break;
			case '*':
				push(pop() * pop());
				break;
			case '@':
				duplicate();
				break;
			case '&': 
				clear();
				break;
			case '!': 
				swap();
				break;
			case '?': 
				showtop();
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
			case '=':
				op2 = pop();
				variables[var - 'a'] = op2;
				printf("testing %c\n", var);
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
