#include "main.h"

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
	int index;

	for (index = 0; s[index] >= '\0'; index++)
	{
		if (s[index] == c)
			return (s + index);
	}
	return ('\0');
}
