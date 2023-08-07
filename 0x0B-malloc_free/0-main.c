#include "main.h"

/**
 * main - check the code for ALX School students.
 *
 * Return: Always 0.
 */
int main(void)
{
char *buffer;

buffer = create_array(98, 'H');
if  (buffer == NULL)
{
printf("failed to allocate memory\n");
return (1);
}
simple_print_buffer(buffer, 98);
free(buffer);
return (0);
}
/**
 * simple_print_buffer - Prints buffer in hexadecimal
 * @buffer: The address of memory to print
 * @size: The size of the memory to print
 *
 * Return: Nothing.
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
