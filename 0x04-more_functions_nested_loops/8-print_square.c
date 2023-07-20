#include "main.h"

/**
 * print_square - Prints a square of size 'size' using the character '#'.
 * @size: The size of the square to be printed.
 *        If size is 0 or less, the function only prints a newline.
 */
void print_square(int size)
{
if (size <= 0)
{
_putchar('\n');
}
else
{
int i, j;
for (i = 0; i < size; i++)
{
for (j = 0; j < size; j++)
{
_putchar('#');
}
_putchar('\n');
}
}
}

