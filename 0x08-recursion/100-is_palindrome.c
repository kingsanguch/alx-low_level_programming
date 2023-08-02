#include "main.h"
#include <string.h>

/**
 * is_palindrome_helper - Recursive helper function to check if  palindrome.
 * @s: The string to check.
 * @start: The starting index.
 * @end: The ending index.
 *
 * Return: 1 if the string is a palindrome, 0 otherwise.
 */
int is_palindrome_helper(char *s, int start, int end)
{
if (start >= end)
return (1);

if (s[start] != s[end])
return (0);

return (is_palindrome_helper(s, start + 1, end - 1));
}

/**
 * is_palindrome - Checks whether a string is a palindrome.
 * @s: The input string.
 *
 * Return: 1 if the string is a palindrome, 0 otherwise.
 */
int is_palindrome(char *s)
{
int length = strlen(s);

if (length <= 1)
return (1);

return (is_palindrome_helper(s, 0, length - 1));
}
