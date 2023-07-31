#include "main.h"

/**
 * _strspn - Gets the length of a prefix substring.
 * @s: A pointer to the main string.
 * @accept: A pointer to the substring of acceptable bytes.
 *
 * Return: The number of bytes in the initial segment of s
 *         which consist only of bytes from accept.
 */
unsigned int _strspn(char *s, char *accept)
{
unsigned int count = 0;
int found = 1;

while (*s && found)
{
found = 0;

while (*accept)
{
if (*s == *accept)
{
count++;
found = 1;
break;
}
accept++;
}

if (!found)
break;

s++;
accept = accept - count;
}

return (count);
}
