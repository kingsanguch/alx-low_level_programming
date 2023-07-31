#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PASSWORD_LENGTH 27

/**
 * generate_random_password - Generates random valid password
 * main - Generates a random valid password
 * Return: Always 0
 */

char *generate_random_password()
{
char *password = malloc(PASSWORD_LENGTH);

if (password == NULL)
{
fprintf(stderr, "Memory allocation failed.\n");
exit(EXIT_FAILURE);
}

srand(time(NULL));

for (int i = 0; i < PASSWORD_LENGTH - 1; i++)
{

password[i] = (rand() % (126 - 33 + 1)) + 33;

password[PASSWORD_LENGTH - 1] = '\0';

return (password);
}

int main(void)
{
char *password = generate_random_password();

printf("%s\n", password);

free(password);
return (0);
}
