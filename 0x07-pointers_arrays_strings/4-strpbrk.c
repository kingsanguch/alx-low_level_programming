#include "main.h"

/**
 * _strpbrk - Searches a string for any of a set of bytes.
 * @s: A pointer to the string to search in.
 * @accept: A pointer to the set of bytes to search for.
 *
 * Return: A pointer to the byte in s that matches one of the bytes in accept,
 *         or NULL if no such byte is found.
 */
char *_strpbrk(char *s, char *accept)
{
	int index;

	while (*s)
	{
		for (index = 0; accept[index]; index++)
		{
			if (*s == accept[index])
				return (s);
		}
		s++;
	}
	return ('\0');
}
