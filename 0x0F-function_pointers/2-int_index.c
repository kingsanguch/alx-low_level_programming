#include <stddef.h>

/**
 * int_index - searches for an integer in an array
 * @array: array of integers
 * @size: number of elements in the array
 * @cmp: pointer to the comparison function
 *
 * Return: index of the first matching element, or -1 if not found
 */
int int_index(int *array, int size, int (*cmp)(int))
{
int i;

if (array != NULL && cmp != NULL && size > 0)
{
for (i = 0; i < size; i++)
{
if (cmp(array[i]))
{
return (i);
}
}
}
return (-1);
}
