#include "main.h"

/**
 * print_triangle - Prints a triangle of size 'size' using the character '#'.
 * @size: The size of the triangle to be printed.
 *        If size is 0 or less, the function only prints a newline.
 */
void print_triangle(int size)
{
if (size <= 0)
{
_putchar('\n');
}
else
{
int i, j;
for (i = 1; i <= size; i++)
{
for (j = size - i; j > 0; j--)
{
_putchar(' ');
}
for (j = 0; j < i; j++)
{
_putchar('#');
}
_putchar('\n');
}
}
}

