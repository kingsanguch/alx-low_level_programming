#include <stdlib.h>
#include "main.h"
/**
 * _calloc - Allocate memory for an array using malloc.
 * @nmemb: Number of elements.
 * @size: Size of each element.
 * Return: Pointer to allocated memory, or NULL.
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
void *allocated_memory;

if (nmemb == 0 || size == 0)
return (NULL);

allocated_memory = malloc(nmemb * size);

if (!allocated_memory)
return (NULL);

{
unsigned char *ptr = (unsigned char *)allocated_memory;
unsigned int i;

for (i = 0; i < nmemb * size; i++)
ptr[i] = 0;
}

return (allocated_memory);
}
