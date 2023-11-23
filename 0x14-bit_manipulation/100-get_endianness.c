#include "main.h"

/**
 * get_endianness - Checks the endianness of the system.
 *
 * Return: 0 if big endian, 1 if little endian.
 */
int get_endianness(void)
{
	unsigned int check = 1;
	char *endian = (char *)&check;

	/* If the first byte of the memory is 1, it is little-endian */
	return (*endian == 1 ? 1 : 0);
}
