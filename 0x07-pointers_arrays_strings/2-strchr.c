#include "main.h"
#include <stddef.h>

/**
 * _strchr - Locates the first occurrence of the character c in the string s.
 * @s: A pointer to the string to search in.
 * @c: The character to find.
 *
 * Return: A pointer to the first occurrence of c in the string s,
 *         or NULL if the character is not found.
 */
char *_strchr(char *s, char c)
{
/* Loop through the string until the end or until the character is found */
while (*s != '\0')
{
if (*s == c)
{
return (s); /* Return the pointer to the first occurrence of c */
}
s++;
}

/* If the character is not found, return NULL */
return (NULL);
}
