#include <stdio.h>

/**
 * main - A program that prints the size of various computer types
 * Return: 0 (success)
 */
int main(void)
{
char a;
int b;
long int c;
long long int d;
float f;

printf("Size of a char: %i byte(s)\n", sizeof(a));
printf("Size of an int: %i byte(s)\n", sizeof(b));
printf("Size of a long int: %i byte(s)\n", sizeof(c));
printf("Size of a long long int: %i byte(s)\n", sizeof(d));
printf("Size of a float: %i byte(s)\n", sizeof(f));
return (0);
}
