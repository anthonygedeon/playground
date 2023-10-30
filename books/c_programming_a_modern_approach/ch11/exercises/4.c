#include <stdio.h>

void swap(int *p, int *q) {
	int tmp = *q;
	*q = *p;
	*p = tmp;	
}

int main(void) {
	int i = 10;
	int j = 20;
	swap(&i, &j);
	printf("i: %i j: %i\n", i, j);
}
