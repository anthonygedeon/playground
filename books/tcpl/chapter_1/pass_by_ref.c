#include <stdio.h>

void ref(int* arg);
void val(int arg);

int main() {
	int var = 10;
	val(var); // pass by value
	printf("%i\n", var); // print 10

	ref(&var); // pass by reference
	printf("%i\n", var); // printf 20 instead of 
	return 0;
}

void ref(int* arg) {
	*arg = 20;
}

void val(int arg) {
	arg = 20;
}
