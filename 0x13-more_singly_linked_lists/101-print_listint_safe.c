#include "lists.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * print_listint_safe - Prints a listint_t linked list safely
 * @head: A pointer to the head of the list.
 *
 * Return: The number of nodes in the list.
 */
size_t print_listint_safe(const listint_t *head)
{
const listint_t *current;
size_t count = 0;
int diff;

current = head;

while (current)
{
count++;
diff = current - current->next;
printf("[%p] %d\n", (void *)current, current->n);

if (diff > 0)
current = current->next;
else
{
printf("-> [%p] %d\n", (void *)current->next, current->next->n);
break;
}
}

return (count);
}
