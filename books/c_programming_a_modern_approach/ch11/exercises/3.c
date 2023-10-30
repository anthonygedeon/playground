#include <stdio.h>

void avg_sum(double a[], int n, double *avg, double *sum) {
	int i;

	*sum = 0.0; // (1)
	for (i = 0; i < n; i++)
		*sum += a[i]; // (2)
	*avg = *sum / n; // (3) (4)
}

int main(void) {
	double i, j;
	double nums[] = { 102, 99, 23, 1, 418 };
	avg_sum(nums, 5, &i, &j);
	printf("%lf %lf\n", i, j);
	return 0;
}
