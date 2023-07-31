#include "main.h"

/**
 * _strstr - Locates a substring.
 * @haystack: A pointer to the main string.
 * @needle: A pointer to the substring to locate.
 *
 * Return: A pointer to the beginning of the located substring,
 *         or NULL if the substring is not found.
 */
char *_strstr(char *haystack, char *needle)
{
int index;

if (*needle == 0)
return (haystack);
while (*haystack)
{
index = 0;
if (haystack[index] == needle[index])
{
do {
if (needle[index + 1] == '\0')
return (haystack);
index++;
}

while (haystack[index] == needle[index]);

}
haystack++;
}
return ('\0');
}
