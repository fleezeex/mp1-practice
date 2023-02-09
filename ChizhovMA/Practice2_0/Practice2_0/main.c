#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

int main()
{
	int i,j;
	Matrix *matrix_dynamic, *m1,*m2,*res;
	/*
	matrix.n = 2;
	matrix.x = (float*)malloc(sizeof(float) * matrix.n * matrix.n);
	for (i = 0; i < matrix.n; i++)
		for (j = 0; j < matrix.n; j++)
			scanf("%f", &(matrix.x[i * matrix.n + j]));

	*/
	/*
	allocate_matrix(&matrix_dynamic, 2);
	fill_matrix(matrix_dynamic);
	print_matrix(matrix_dynamic);
	free_matrix(&matrix_dynamic);
	*/
	allocate_matrix(&m1, 2);
	allocate_matrix(&m2, 2);

	fill_matrix(m1);
	fill_matrix(m2);
	/*
	res = addition_matrix(m1, m2);
	print_matrix(res);
	free_matrix(&res);
	*/
	/*
	res = addition_const(m1, 5.2f);
	print_matrix(res);
	free_matrix(&res);
	
	res = multi_const(m1, 3.4f);
	print_matrix(res);
	free_matrix(&res);
	*/

	res = multi_matrix(m1, m2);
	print_matrix(res);
	free_matrix(&res);
	return 0;
}