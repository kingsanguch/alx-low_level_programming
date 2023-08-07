#include "main.h"
#include <stdlib.h>

/**
 * _strdup - Duplicates a string in memory.
 * @str: The string to be duplicated.
 *
 * Return: If successful - a pointer to the duplicated string.
 *         If memory allocation fails or str is NULL - NULL.
 */
char *_strdup(char *str)
{
char *duplicate;
unsigned int len = 0;
unsigned int i;

if (str == NULL)
return (NULL);

while (str[len] != '\0')
len++;

duplicate = malloc(sizeof(char) * (len + 1));

if (duplicate == NULL)
return (NULL);

for (i = 0; i <= len; i++)
duplicate[i] = str[i];

return (duplicate);
}
