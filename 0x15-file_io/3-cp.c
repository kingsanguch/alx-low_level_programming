#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "main.h"

#define BUFFER_SIZE 1024

/**
 * main - Copies the content of a file to another file.
 * @argc: The number of command-line arguments.
 * @argv: An array containing the command-line arguments.
 * Return: 0 on success, or the appropriate error code on failure.
 */
int main(int argc, char *argv[])
{
int fd_from, fd_to, read_result, write_result;
char buffer[BUFFER_SIZE];

if (argc != 3)
{
dprintf(2, "Usage: %s file_from file_to\n", argv[0]);
exit(97);
}

fd_from = open(argv[1], O_RDONLY);
if (fd_from == -1)
{
dprintf(2, "Error: Can't read from file %s\n", argv[1]);
exit(98);
}

fd_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
if (fd_to == -1)
{
dprintf(2, "Error: Can't write to file %s\n", argv[2]);
close(fd_from);
exit(99);
}

while ((read_result = read(fd_from, buffer, BUFFER_SIZE)) > 0)
{
write_result = write(fd_to, buffer, read_result);
if (write_result == -1)
{
dprintf(2, "Error: Can't write to file %s\n", argv[2]);
close(fd_from);
close(fd_to);
exit(99);
}
}

if (read_result == -1)
{
dprintf(2, "Error: Can't read from file %s\n", argv[1]);
close(fd_from);
close(fd_to);
exit(98);
}

if (close(fd_from) == -1)
{
dprintf(2, "Error: Can't close fd %d\n", fd_from);
exit(100);
}

if (close(fd_to) == -1)
{
dprintf(2, "Error: Can't close fd %d\n", fd_to);
exit(100);
}

return (0);
}
