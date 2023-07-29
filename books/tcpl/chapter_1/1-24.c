#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdbool.h>

#define BUFSIZE 1024

typedef struct stack {
	char buffer[BUFSIZE];
	int sp;
} stack;

void push(stack* st, char element);
void pop(stack* st);
char tail(stack* st);
bool empty(stack* st);

bool check(const char* brackets);

int main() {
	assert(!check("{[)][]}")); 
	assert(check("([{}({}[])])"));
	
	return EXIT_SUCCESS;
}

void stack_push(stack* st, char element) {
	st->buffer[st->sp] = element;
	st->sp += 1;
}

void stack_pop(stack* st) {
	if (st->sp > 0) {
		st->buffer[st->sp] = '\0';
		st->sp -= 1;
	}
}

char stack_tail(stack* st) {
	return st->buffer[st->sp-1];
}

bool stack_empty(stack* st) {
	if (st->sp == 0) {
		return true;
	} 
	return false;
}

bool check(const char* brackets) {
   stack stack = { .sp = 0 };

   for (int i = 0; i < strlen(brackets); i += 1) {
	   switch(brackets[i]) {
		   case '[':
		   case '(':
		   case '{':
			   stack_push(&stack, brackets[i]);
			   break;
		   case ']':
		   case ')':
		   case '}':
			   if (!stack_empty(&stack)) {
				   if (
					   ((brackets[i] == ']') && '[' == stack_tail(&stack)) || 
					   ((brackets[i] == ')') && '(' == stack_tail(&stack)) || 
					   ((brackets[i] == '}') && '{' == stack_tail(&stack)))
				   {
					   stack_pop(&stack);
				   } else {
					   return false;
				   }
			   }
			   break;
	   }
   }

   return stack_empty(&stack);
}
