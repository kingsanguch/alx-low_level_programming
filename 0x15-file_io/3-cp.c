#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

#define BUFFER_SIZE 1024

/**
 * report_error - Reports an error message and exits with the given code.
 * @message: The error message format.
 * @filename: The filename to include in the message.
 * @exit_code: The exit code.
 */
void report_error(const char *message, const char *filename, int exit_code)
{
dprintf(STDERR_FILENO, message, filename);
exit(exit_code);
}

/**
 * main - Copies the content of a file to another file.
 * @argc: The number of command-line arguments.
 * @argv: An array of strings containing the command-line arguments.
 *
 * Return: 0 on success, or an exit code on failure.
 */

int main(int argc, char **argv)
{
int fd_from, fd_to;
ssize_t bytes_read, bytes_written;
char buffer[BUFFER_SIZE];

if (argc != 3)
report_error("Usage: cp file_from file_to\n", "", 97);

fd_from = open(argv[1], O_RDONLY);
if (fd_from == -1)
report_error("Error: Can't read from file %s\n", argv[1], 98);

fd_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
if (fd_to == -1)
{
close(fd_from);
report_error("Error: Can't write to %s\n", argv[2], 99);
}

while ((bytes_read = read(fd_from, buffer, BUFFER_SIZE)) > 0)
{
bytes_written = write(fd_to, buffer, bytes_read);
if (bytes_written == -1 || bytes_written != bytes_read)
{
close(fd_from);
close(fd_to);
report_error("Error: Can't write to %s\n", argv[2], 99);
}
}

if (bytes_read == -1)
{
close(fd_from);
report_error("Error: Can't read from file %s\n", argv[1], 98);
}

if (close(fd_from) == -1 || close(fd_to) == -1)
report_error("Error: Can't close fd\n", "", 100);

return (0);
}

