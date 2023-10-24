#include <stdio.h>

int main(void) {
	int cell_1 ,cell_2 , cell_3, cell_4, cell_5, cell_6, 
		cell_7, cell_8, cell_9, cell_10, cell_11, cell_12, 
		cell_13, cell_14, cell_15, cell_16;
	
	printf("Enter the numbers from 1 to 16 in any order: \n");
	scanf("%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d", 
			&cell_1, &cell_2, &cell_3, &cell_4, 
			&cell_5, &cell_6, &cell_7, &cell_8, 
			&cell_9, &cell_10, &cell_11, &cell_12,
			&cell_13, &cell_14, &cell_15, &cell_16);


	printf("%.2d %.2d %.2d %.2d\n%.2d %.2d %.2d %.2d\n%.2d %.2d %.2d %.2d\n%.2d %.2d %.2d %.2d\n", cell_1, cell_2, cell_3, cell_4, 
			cell_5, cell_6, cell_7, cell_8, 
			cell_9, cell_10, cell_11, cell_12, 
			cell_13, cell_14, cell_15, cell_16);

	printf("Row sums: %d %d %d %d\n", 
			(cell_1 + cell_2 + cell_3 + cell_4),
			(cell_5 + cell_6 + cell_7 + cell_8),
			(cell_9 + cell_10 + cell_11 + cell_12),
			(cell_13 + cell_14 + cell_15 + cell_16));

	printf("Columns sums: %d %d %d %d\n", 
			(cell_1 + cell_5 + cell_9 + cell_13),
			(cell_2 + cell_6 + cell_10 + cell_14),
			(cell_3 + cell_7 + cell_11 + cell_15),
			(cell_4 + cell_8 + cell_12 + cell_16));

	printf("Diagonal sums: %d %d\n", 
			(cell_1 + cell_6 + cell_11 + cell_16),
			(cell_13 + cell_10 + cell_7 + cell_4));

	return 0;
}
