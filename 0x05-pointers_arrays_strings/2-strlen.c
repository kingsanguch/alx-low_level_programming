#include "main.h"

/**
 * _strlen - checks the length of sttring
 * @s: string to be checked
 * Return: The length of srting
 */

int _strlen(char *s)
{

	int string_length = 0;

	while (s[string_length])
		string_length++;
	return (string_length);
}
