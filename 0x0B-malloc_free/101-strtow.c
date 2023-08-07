#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * strtow - Splits a string into words.
 * @str: The input string.
 *
 * Return: A pointer to an array of strings (words), or NULL on failure.
 */
char **strtow(char *str)
{

int word_count = 0;
char **words = NULL;
char *word = strtok(str, " ");
int i;

if (str == NULL || *str == '\0')
return (NULL);

while (word)
{
word_count++;
words = realloc(words, sizeof(char *) * word_count);
if (words == NULL)
{
for (i = 0; i < word_count; i++)
free(words[i]);
free(words);
return (NULL);
}
words[word_count - 1] = strdup(word);
if (words[word_count - 1] == NULL)
{
for (i = 0; i < word_count; i++)
free(words[i]);
free(words);
return (NULL);
}
word = strtok(NULL, " ");
}

return (words);
}
