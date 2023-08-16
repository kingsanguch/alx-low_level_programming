#include <stdio.h>
#include <stdlib.h>
#include "3-calc.h"

/**
 * main - Entry point.
 * @argc: The number of command-line arguments.
 * @argv: An array of command-line argument strings.
 * Return: 0 on success, 98 on error.
 */
int main(int argc, char *argv[])
{
if (argc == 4)
{
int num1 = atoi(argv[1]);
int num2 = atoi(argv[3]);
char *operator = argv[2];

int (*operation)(int, int) = get_op_func(operator);

if (operation != NULL)
{
printf("%d\n", operation(num1, num2));
return (0);
}
}

printf("Error\n");
return (98);
}
