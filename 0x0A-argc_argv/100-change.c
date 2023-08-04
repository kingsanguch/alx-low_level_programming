#include <stdio.h>
#include <stdlib.h>
/**
 * main - Entry point of the program
 * @argc: Count of arguments
 * @argv: Array of arguments
 * Return: 0 on success, 1 on error
 */

int main(int argc, char *argv[])
{
int cents, i, count;
int coins[] = {25, 10, 5, 2, 1};
int num_coins = sizeof(coins) / sizeof(coins[0]);

if (argc != 2)
{
printf("Error\n");
return (1);
}

cents = atoi(argv[1]);

if (cents < 0)
{
printf("0\n");
return (0);
}

count = 0;

for (i = 0; i < num_coins && cents > 0; i++)
{
count += cents / coins[i];
cents %= coins[i];
}

printf("%d\n", count);

return (0);
}
