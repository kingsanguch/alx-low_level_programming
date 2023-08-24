#include <stdio.h>
#include "lists.h"

/**
 * print_list - Prints elements of list_t list.
 * @h: A pointer to the head of the list_t list.
 *
 * Return: number of nodes.
 */
size_t print_list(const list_t *h)
{
size_t count = 0;

while (h != NULL)
{

if (h->str == NULL)
printf("[0] (nil)\n");
else
printf("[%u] %s\n", h->len, h->str);

h = h->next;
count++;
}

return (count);
}
