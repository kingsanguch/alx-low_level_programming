#include <stdlib.h>
#include "main.h"
/**
 * _realloc - Reallocates a memory block.
 * @ptr: Pointer to the memory block to reallocate.
 * @old_size: Size of the old memory block.
 * @new_size: New size for the reallocated memory block.
 * Return: Pointer to the reallocated memory block, NULL on failure.
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
void *new_ptr;
unsigned int i;

if (new_size == old_size)
return (ptr);
if (!ptr)
return (malloc(new_size));

if (new_size == 0)
{
free(ptr);
return (NULL);
}

new_ptr = malloc(new_size);

if (!new_ptr)
return (NULL);

for (i = 0; i < old_size && i < new_size; i++)
*((char *)new_ptr + i) = *((char *)ptr + i);

free(ptr);

return (new_ptr);
}
