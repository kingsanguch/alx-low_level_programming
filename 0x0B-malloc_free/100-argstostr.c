#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * argstostr - Concatenates all the arguments of the program.
 * @ac: The number of arguments.
 * @av: An array of strings containing the arguments.
 *
 * Return: A pointer to the concatenated string, or NULL if it fails.
 */
char *argstostr(int ac, char **av)
{
char *concatenated;
int total_length = 0;
int i, j, k;

if (ac == 0 || av == NULL)
return (NULL);

for (i = 0; i < ac; i++)
{
j = 0;
while (av[i][j])
{
total_length++;
j++;
}
total_length++;
}
concatenated = malloc(sizeof(char) * (total_length + 1));

if (concatenated == NULL)
return (NULL);

k = 0;
for (i = 0; i < ac; i++)
{
j = 0;
while (av[i][j])
{
concatenated[k] = av[i][j];
k++;
j++;
}
concatenated[k] = '\n';
k++;
}
concatenated[k] = '\0';
return (concatenated);
}
