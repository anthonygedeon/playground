#include <stdio.h>

#define N 7

void find_two_largest(int a[], int n, int *largest, int *second_largest);

int main(void) {
	int a;
	int	b;
	int numbers[] = { 1, 5, 63, 100, 981, 34, 88 };
	find_two_largest(numbers, N, &a, &b);
	printf("%i %i\n", a, b); // 981 100
	return 0;
}

void find_two_largest(int a[], int n, int *largest, int *second_largest) {
	*second_largest = a[0];

	int largest_index;
	for (int i = 1; i < n; i++) {
		if (a[largest_index] < a[i]) {
			largest_index = i;
		} 
	}

	*largest = a[largest_index];

	for (int i = 1; i < n; i++) {
		if (largest_index == i) {
			continue;
		}

		if (*second_largest < a[i]) {
			*second_largest = a[i];
		} 
	}
}
