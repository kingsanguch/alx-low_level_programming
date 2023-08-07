#include "main.h"

/**
 * create_array - Create array, init with char.
 * @size: Array size.
 * @c: Char to initialize.
 * Return: Pointer to array, NULL if fail.
 */
char *create_array(unsigned int size, char c)
{

char *array;
unsigned int i;

if (size == 0)
return (NULL);

array = (char *)malloc(sizeof(char) * size);
if (array == NULL)
return (NULL);

for (i = 0; i < size; i++)
{
array[i] = c;
}
return (array);
}

/**
 * simple_print_buffer - Print buffer in hex.
 * @buffer: Memory address.
 * @size: Memory size.
 * Return: None.
 */
void simple_print_buffer(char *buffer, unsigned int size)
{
unsigned int i;
for (i = 0; i < size; i++)
{
if (i % 10 == 0 && i > 0)
{
printf("\n");
}
printf("0x%02x ", buffer[i]);
}
printf("\n");
}
