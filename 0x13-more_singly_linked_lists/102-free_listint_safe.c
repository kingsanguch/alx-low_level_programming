#include "lists.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * free_listint_safe - Frees a listint_t linked list safely
 * @h: A pointer to the head of the list.
 * Return: The size of the list that was freed.
 */
size_t free_listint_safe(listint_t **h)
{
size_t count = 0;
listint_t *current, *temp;

if (h == NULL || *h == NULL)
return (0);

current = *h;

while (current != NULL)
{
count++;
temp = current;
current = current->next;
free(temp);

/* Detect the loop and set the head to NULL */
if (temp <= current)
{
*h = NULL;
break;
}
}

/* Set the head to NULL */
*h = NULL;
return (count);
}
