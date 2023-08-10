#include <stdio.h>
#include <stdlib.h>

/**
 * _isdigit - Checks if a character is a digit.
 * @c: The character to check.
 * Return: 1 if @c is a digit, 0 otherwise.
 */
int _isdigit(char c)
{
return (c >= '0' && c <= '9');
}

/**
 * _print_error - Prints an error message and exits with status 98.
 */
void _print_error(void)
{
printf("Error\n");
exit(98);
}

/**
 * _multiply - Multiplies two positive numbers.
 * @len1: Length of the first number.
 * @num1: The first number as a string.
 * @len2: Length of the second number.
 * @num2: The second number as a string.
 */
void _multiply(int len1, char *num1, int len2, char *num2)
{
int i, j, k, carry, product;
int result_len = len1 + len2;
int *result = (int *)calloc(result_len, sizeof(int));

if (!result)
_print_error();

for (i = len1 - 1; i >= 0; i--)
{
carry = 0;
for (j = len2 - 1; j >= 0; j--)
{
product = (num1[i] - '0') * (num2[j] - '0') + result[i + j + 1] + carry;
carry = product / 10;
result[i + j + 1] = product % 10;
}
result[i + j + 1] += carry;
}

k = 0;
while (k < result_len && result[k] == 0)
k++;

if (k == result_len)
putchar('0');
else
{
for (; k < result_len; k++)
putchar(result[k] + '0');
}

putchar('\n');
free(result);
}

/**
 * main - Multiplies two positive numbers passed as arguments.
 * @argc: The number of command-line arguments.
 * @argv: An array of command-line arguments.
 * Return: 0 on success, 98 on error.
 */
int main(int argc, char *argv[])
{
int len1 = 0, len2 = 0;

if (argc != 3)
_print_error();

while (argv[1][len1])
{
if (!_isdigit(argv[1][len1]))
_print_error();
len1++;
}

while (argv[2][len2])
{
if (!_isdigit(argv[2][len2]))
_print_error();
len2++;
}

_multiply(len1, argv[1], len2, argv[2]);

return (0);
}
