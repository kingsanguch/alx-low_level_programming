#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "dog.h"

/**
 * new_dog - Creates a new dog.
 * @name: The name of the dog.
 * @age: The age of the dog.
 * @owner: The owner of the dog.
 *
 * Return: Pointer to the new dog, or NULL if failed.
 */
dog_t *new_dog(char *name, float age, char *owner)
{
dog_t *new_dog_ptr;

new_dog_ptr = malloc(sizeof(dog_t));
if (new_dog_ptr == NULL)
return (NULL);

new_dog_ptr->name = malloc(strlen(name) + 1);
if (new_dog_ptr->name == NULL)
{
free(new_dog_ptr);
return (NULL);
}

new_dog_ptr->age = age;
new_dog_ptr->owner = malloc(strlen(owner) + 1);
if (new_dog_ptr->owner == NULL)
{
free(new_dog_ptr->name);
free(new_dog_ptr);
return (NULL);
}

return (new_dog_ptr);
}
