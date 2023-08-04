#include "main.h"
#include <stdio.h>

/**
 * _puts - print print string followed by new line
 * @str: string to print
 */

void _puts(char *str)
{
	while (*str != '\0')
	{
		putchar(*str);
		str++;
	}
	putchar('\n');
}
