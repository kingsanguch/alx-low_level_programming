#include <stdlib.h>
#include "main.h"
#include <limits.h>
#include <stdio.h>
/**
 * malloc_checked - Allocates memory using malloc.
 * @b: The number of bytes to allocate.
 *
 * Return: A pointer to the allocated memory.
 *         If malloc fails, exits with status value 98.
 */
void *malloc_checked(unsigned int b)
{
void *ptr = malloc(b);

if (ptr == NULL)
exit(98);
return (ptr);
}
