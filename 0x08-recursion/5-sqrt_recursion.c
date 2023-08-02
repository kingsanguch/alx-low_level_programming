#include "main.h"

/**
 * sqrt_helper - Recursive helper function to calculate the square root.
 * @n: The number to find the square root of.
 * @guess: The current guess for the square root.
 *
 * Return: The integer square root, or -1 if no square root exists.
 */
int sqrt_helper(int n, int guess)
{
if (guess * guess == n)
return (guess);

if (guess * guess > n)
return (-1);

return ((sqrt_helper(n, guess + 1)));
}

/**
 * _sqrt_recursion - Calculates the integer square root of a number
 * @n: The input number.
 *
 * Return: The integer square root, or -1 if no square root exists.
 */
int _sqrt_recursion(int n)
{
if (n < 0)
return (-1);

return (sqrt_helper(n, 0));
}
