#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "lists.h"

/**
 * add_node - Adds a new node at the beginning of a list_t list.
 * @head: A pointer to a pointer to the head of the list_t list.
 * @str: The string to be duplicated and added to the new node.
 *
 * Return: The address of the new element, or NULL if it failed.
 */
list_t *add_node(list_t **head, const char *str)
{
list_t *new_node;
char *str_copy;
unsigned int len = 0;

if (str == NULL)
return (NULL);

new_node = malloc(sizeof(list_t));
if (new_node == NULL)
return (NULL);

str_copy = malloc(sizeof(char) * (strlen(str) + 1));
if (str_copy == NULL)
{
free(new_node);
return (NULL);
}

strcpy(str_copy, str);
len = strlen(str);

new_node->str = str_copy;
new_node->len = len;
new_node->next = *head;
*head = new_node;

return (new_node);
}
