#include "main.h"

/**
 * create_array - Create array, init with char.
 * @size: Array size.
 * @c: Char to initialize.
 * Return: Pointer to array, NULL if fail.
 */
char *create_array(unsigned int size, char c)
{

char *array;
unsigned int i;

if (size == 0)
return (NULL);

array = (char *)malloc(sizeof(char) * size);
if (array == NULL)
return (NULL);

for (i = 0; i < size; i++)
{
array[i] = c;
}
return (array);
}
