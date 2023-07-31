#include "main.h"
#include <stdio.h>

/**
 * print_diagsums - Prints the sum of the two diagonals of a square matrix.
 * @a: A pointer to the square matrix of integers.
 * @size: The size of the square matrix.
 */
void print_diagsums(int *a, int size)
{
int i;
int sum_diag1 = 0;
int sum_diag2 = 0;

for (i = 0; i < size; i++)
{
sum_diag1 += a[(size + 1) * i];
sum_diag2 += a[(size - 1) * (i + 1)];
}
printf("%d, %d\n", sum_diag1, sum_diag2);
}
