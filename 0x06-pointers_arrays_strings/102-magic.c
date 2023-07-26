#include <stdio.h>

/**
 * main - Entry point of the program
 *
 * Description: The main function demonstrates pointer arithmetic to modify
 *              the value of a[2] to 98 without directly using the variable a.
 *              It uses a pointer p to point to an integer n, and by performing
 *            pointer arithmetic on p, it accesses modifies the value of a[2].
 *              The modified value of a[2] is then printed.
 *
 * Return: Always 0.
 */
int main(void)
{
int n;
int *p;

p = &n;
*(p + 5) = 98;  /* New line of code to set a[2] to 98 */
printf("a[2] = %d\n", *(p + 5));
return (0);
}

