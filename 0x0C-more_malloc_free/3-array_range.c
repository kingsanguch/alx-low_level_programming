#include <stdlib.h>
#include "main.h"
/**
 * array_range - Creates an array of integers from min to max (inclusive).
 * @min: Minimum value.
 * @max: Maximum value.
 * Return: Pointer to array, NULL on failure or invalid input.
 */
int *array_range(int min, int max)
{
int *new_array, size, i;

if (min > max)
return (NULL);

size = max - min + 1;
new_array = malloc(sizeof(int) * size);

if (!new_array)
return (NULL);

for (i = 0; i < size; i++)
new_array[i] = min + i;

return (new_array);
}
