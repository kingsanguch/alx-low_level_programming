#include "main.h"
#include <fcntl.h>
#include <unistd.h>

/**
 * create_file - Creates a file with specified permissions and writes content.
 * @filename: The name of the file to create.
 * @text_content: The NULL-terminated string to write to the file.
 *
 * Return: 1 on success, -1 on failure.
 */
int create_file(const char *filename, char *text_content)
{
int file_descriptor, write_status, close_status;
ssize_t text_len = 0;

if (filename == NULL)
return (-1);

file_descriptor = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0600);
if (file_descriptor == -1)
return (-1);

if (text_content != NULL)
{
while (text_content[text_len] != '\0')
text_len++;

write_status = write(file_descriptor, text_content, text_len);
if (write_status == -1)
{
close(file_descriptor);
return (-1);
}
}

close_status = close(file_descriptor);
if (close_status == -1)
return (-1);

return (1);
}
