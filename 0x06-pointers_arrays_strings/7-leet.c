#include "main.h"

/**
 * leet - Encodes a string into 1337.
 * @str: The input string to be encoded.
 *
 * Return: A pointer to the encoded string.
 */
char *leet(char *str)
{
char replacements[] = {'4', '3', '0', '7', '1'};
char target[] = {'a', 'e', 'o', 't', 'l'};

int i, j;

for (i = 0; str[i]; i++)
{
for (j = 0; target[j]; j++)
{
if (str[i] == target[j] || str[i] == target[j] - ('a' - 'A'))
{
str[i] = replacements[j];
break;
}
}
}

return (str);
}
