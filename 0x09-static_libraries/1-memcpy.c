#include "main.h"

/**
 * _memcpy - copie memory area
 * @dest: memory destination
 * @src: memeory source to be copied
 * @n: number of bytes
 *
 * Return: copied memory with n bytes
 */

char *_memcpy(char *dest, char *src, unsigned int n)
{
	int r = 0;
	int i = n;

	for (; r < i; r++)
	{
		dest[r] = src[r];
		n--;
	}
	return (dest);
}
