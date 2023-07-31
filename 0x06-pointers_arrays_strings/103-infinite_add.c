#include "main.h"
#include <stdio.h>

/**
 * infinite_add - Adds two numbers.
 * @n1: The first number.
 * @n2: The second number.
 * @r: The buffer to store the result.
 * @size_r: The size of the buffer.
 *
 * Return: A pointer to the result. If the result, returns 0.
 */
char *infinite_add(char *n1, char *n2, char *r, int size_r)
{

int carry = 0;
int i, j, k;
int len_n1, len_n2, max_len;

    /* Calculate the length of n1 and n2 */
for (len_n1 = 0; n1[len_n1] != '\0'; len_n1++)
;
for (len_n2 = 0; n2[len_n2] != '\0'; len_n2++)
;

    /* Determine the maximum length among n1, n2, and size_r - 1 */
max_len = (len_n1 > len_n2 ? len_n1 : len_n2);

    /* Check if the result can fit in the buffer */
if (max_len + 1 > size_r)
return (0);

r[max_len + 1] = '\0'; /* Null-terminate the result string */
k = max_len;

for (i = len_n1 - 1, j = len_n2 - 1; i >= 0 || j >= 0; i--, j--, k--)
{
int digit_n1 = (i >= 0) ? n1[i] - '0' : 0;
int digit_n2 = (j >= 0) ? n2[j] - '0' : 0;
int sum = digit_n1 + digit_n2 + carry;

carry = sum / 10;
r[k] = (sum % 10) + '0';
}

    /* Check if there's still a carry to add */
if (carry)
{
if (k == 0) /* Check if there's space for the carry in the buffer */
return (0);
r[k] = carry + '0';
}
else
{
k++;
}

    /* Move the result to the beginning of the buffer if necessary */
if (k != 0)
{
for (i = 0; i < max_len + 1 - k; i++)
{
r[i] = r[i + k];
}
}

return (r);
}
