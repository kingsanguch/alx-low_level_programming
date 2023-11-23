#include "main.h"

/**
 * get_bit - Returns the value of a bit at a given index.
 * @n: The number.
 * @index: The index, starting from 0, of the bit to get.
 *
 * Return: The value of the bit at the index or -1 if an error occurred.
 */
int get_bit(unsigned long int n, unsigned int index)
{
	if (index >= (sizeof(unsigned long int) * 8))
		return (-1);

	return ((int)((n >> index) & 1));
}
