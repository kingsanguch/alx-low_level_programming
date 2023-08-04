#include "main.h"
/**
 * _strstr  -entry point
 * @haystack: input
 * @needle: input
 * Return: always 0
 */
char *_strstr(char *haystack, char *needle)
{
	for (; *haystack != '\0'; haystack++)
	{
		char *temp_haystack = haystack;
		char *p = needle;

		while (*temp_haystack == *p && *p != '\0')
		{
			++temp_haystack;
			++p;
		}
		if (*p == '\0')
			return (haystack);
	}
	return (0);
}
