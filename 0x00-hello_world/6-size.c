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

printf("Size of a char: %zu byte(s)\n", sizeof(a));
printf("Size of an int: %zu byte(s)\n", sizeof(b));
printf("Size of a long int: %zu byte(s)\n", sizeof(c));
printf("Size of a long long int: %zu byte(s)\n", sizeof(d));
printf("Size of a float: %zu byte(s)\n", sizeof(f));

printf("[Expected]\n");
printf("Size of a char: 1 byte(s)\n");
printf("Size of an int: 4 byte(s)\n");
printf("Size of a long int: %zu byte(s)\n", sizeof(long int));
printf("Size of a long long int: %zu byte(s)\n", sizeof(long long int));
printf("Size of a float: 4 byte(s)\n");
return (0);
}
