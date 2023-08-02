#include "main.h"

/**
 * factorial - Calculates the factorial of a given number using recursion.
 * @n: The input number.
 *
 * Return: The factorial of the number, or -1 if n is negative.
 */
int factorial(int n)
{
if (n < 0)
return (-1);

if (n == 0)
return (1);

return (n * factorial(n - 1));
}
