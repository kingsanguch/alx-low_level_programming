#include "hash_tables.h"

/**
 * shash_table_create - Creates a sorted hash table.
 * @size: The size of the array.
 *
 * Return: A pointer to the newly created sorted hash table, or NULL if it fails.
 */
shash_table_t *shash_table_create(unsigned long int size)
{
    shash_table_t *new_table;
    unsigned long int i;

    new_table = malloc(sizeof(shash_table_t));
    if (new_table == NULL)
        return (NULL);

    new_table->size = size;
    new_table->array = malloc(sizeof(shash_node_t *) * size);
    if (new_table->array == NULL)
    {
        free(new_table);
        return (NULL);
    }

    new_table->shead = NULL;
    new_table->stail = NULL;

    for (i = 0; i < size; i++)
        new_table->array[i] = NULL;

    return (new_table);
}

/**
 * shash_table_set - Adds an element to a sorted hash table.
 * @ht: The sorted hash table to add or update the key/value to.
 * @key: The key. Key can't be an empty string.
 * @value: The value associated with the key. Value must be duplicated.
 *
 * Return: 1 if it succeeded, 0 otherwise.
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
    shash_node_t *new_node, *temp, *prev;
    unsigned long int index;

    if (ht == NULL || key == NULL || *key == '\0')
        return (0);

    index = key_index((const unsigned char *)key, ht->size);

    temp = ht->array[index];
    prev = NULL;

    while (temp != NULL && strcmp(temp->key, key) < 0)
    {
        prev = temp;
        temp = temp->next;
    }

    new_node = malloc(sizeof(shash_node_t));
    if (new_node == NULL)
        return (0);

    new_node->key = strdup(key);
    if (new_node->key == NULL)
    {
        free(new_node);
        return (0);
    }

    new_node->value = strdup(value);
    if (new_node->value == NULL)
    {
        free(new_node->key);
        free(new_node);
        return (0);
    }

    if (prev == NULL)
    {
        new_node->next = ht->array[index];
        ht->array[index] = new_node;
    }
    else
    {
        new_node->next = temp;
        prev->next = new_node;
    }

    if (ht->shead == NULL || strcmp(ht->shead->key, key) > 0)
    {
        new_node->sprev = NULL;
        new_node->snext = ht->shead;
        if (ht->shead != NULL)
            ht->shead->sprev = new_node;
        ht->shead = new_node;
    }
    else
    {
        temp = ht->shead;
        while (temp->snext != NULL && strcmp(temp->snext->key, key) < 0)
            temp = temp->snext;

        new_node->sprev = temp;
        new_node->snext = temp->snext;
        if (temp->snext != NULL)
            temp->snext->sprev = new_node;
        temp->snext = new_node;
    }

    if (new_node->snext == NULL)
        ht->stail = new_node;

    return (1);
}

/**
 * shash_table_get - Retrieves a value associated with a key from a sorted hash table.
 * @ht: The sorted hash table to look into.
 * @key: The key to look for.
 *
 * Return: The value associated with the key, or NULL if key couldn't be found.
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
    shash_node_t *temp;

    if (ht == NULL || key == NULL || *key == '\0')
        return (NULL);

    temp = ht->shead;
    while (temp != NULL && strcmp(temp->key, key) < 0)
        temp = temp->snext;

    if (temp != NULL && strcmp(temp->key, key) == 0)
        return (temp->value);

    return (NULL);
}

/**
 * shash_table_print - Prints a sorted hash table.
 * @ht: The sorted hash table to print.
 */
void shash_table_print(const shash_table_t *ht)
{
    shash_node_t *node;
    int flag = 0;

    if (ht == NULL)
        return;

    printf("{");
    node = ht->shead;
    while (node != NULL)
    {
        if (flag == 1)
            printf(", ");
        printf("'%s': '%s'", node->key, node->value);
        flag = 1;
        node = node->snext;
    }
    printf("}\n");
}

/**
 * shash_table_print_rev - Prints a sorted hash table in reverse.
 * @ht: The sorted hash table to print.
 */
void shash_table_print_rev(const shash_table_t *ht)
{
    shash_node_t *node;
    int flag = 0;

    if (ht == NULL)
        return;

    printf("{");
    node = ht->stail;
    while (node != NULL)
    {
        if (flag == 1)
            printf(", ");
        printf("'%s': '%s'", node->key, node->value);
        flag = 1;
        node = node->sprev;
    }
    printf("}\n");
}

/**
 * shash_table_delete - Deletes a sorted hash table.
 * @ht: The sorted hash table to delete.
 */
void shash_table_delete(shash_table_t *ht)
{
    shash_node_t *node, *next;

    if (ht == NULL)
        return;

    node = ht->shead;
    while (node != NULL)
    {
        next = node->snext;
        free(node->key);
        free(node->value);
        free(node);
        node = next;
    }

    free(ht->array);
    free(ht);
}
