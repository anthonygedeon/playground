#include <stdio.h>

#define N 5

int *find_largest(int a[], int n);

int main(void) {
	int nums[] = {1, 100, 3, 4, 5};
	printf("%i\n", *find_largest(nums, N));
	return 0;
}

int *find_largest(int a[], int n) {
	int largest_index = 0;
	for (int i = 1; i < n; i++) {
		if (a[largest_index] < a[i]) {
			largest_index = i;
		} 
	}
	return &a[largest_index];
}
