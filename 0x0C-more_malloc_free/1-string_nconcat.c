#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * string_nconcat - Concatenates two strings with a  the second.
 * @s1: First string, can be NULL.
 * @s2: Second string, can be NULL.
 * @n: Maximum bytes to concatenate from s2.
 * Return: Pointer to the concatenated string or NULL on failure.
 */
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
unsigned int len1 = 0, len2 = 0, concat_len = 0, i;
char *concat;

while (s1 && s1[len1])
len1++;
while (s2 && s2[len2])
len2++;

concat_len = len1 + (n >= len2 ? len2 : n);

concat = (char *)malloc(sizeof(char) * (concat_len + 1));
if (!concat)
return (NULL);

for (i = 0; i < len1; i++)
concat[i] = s1[i];
for (i = 0; i < n && i < len2; i++)
concat[len1 + i] = s2[i];
concat[concat_len] = '\0';

return (concat);
}
