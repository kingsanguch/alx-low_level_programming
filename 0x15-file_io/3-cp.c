#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "main.h"

#define BUFFER_SIZE 1024

/**
 * main - Copies the content of a file to another file.
 * @ac: The number of arguments.
 * @av: The array of arguments.
 *
 * Return: 0 on success, or an exit code on failure.
 */
int main(int ac, char **av)
{
int fd_from, fd_to, rd_bytes, wr_bytes;
char buffer[BUFFER_SIZE];

if (ac != 3)
{
dprintf(STDERR_FILENO, "Usage: %s file_from file_to\n", av[0]);
exit(97);
}

fd_from = open(av[1], O_RDONLY);
if (fd_from == -1)
{
dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", av[1]);
exit(98);
}

fd_to = open(av[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
if (fd_to == -1)
{
dprintf(STDERR_FILENO, "Error: Can't write to %s\n", av[2]);
close(fd_from);
exit(99);
}

while ((rd_bytes = read(fd_from, buffer, BUFFER_SIZE)) > 0)
{
wr_bytes = write(fd_to, buffer, rd_bytes);
if (wr_bytes == -1 || wr_bytes != rd_bytes)
{
dprintf(STDERR_FILENO, "Error: Can't write to %s\n", av[2]);
close(fd_from);
close(fd_to);
exit(99);
}
}

if (rd_bytes == -1)
{
dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", av[1]);
close(fd_from);
close(fd_to);
exit(98);
}

if (close(fd_from) == -1)
{
dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_from);
exit(100);
}

if (close(fd_to) == -1)
{
dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_to);
exit(100);
}

return (0);
}
