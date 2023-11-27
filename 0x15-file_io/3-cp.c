#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

#define BUFFER_SIZE 1024

/**
 * main - Copies the content of a file to another file.
 * @argc: The argument count.
 * @argv: The argument vector.
 *
 * Return: 0 on success, otherwise exit with an error code.
 */
int main(int argc, char *argv[])
{
int file_from, file_to, rd, wr;
char buffer[BUFFER_SIZE];
mode_t permissions = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH;

if (argc != 3)
{
dprintf(2, "Usage: %s file_from file_to\n", argv[0]);
exit(97);
}

file_from = open(argv[1], O_RDONLY);
if (file_from == -1)
{
dprintf(2, "Error: Can't read from %s\n", argv[1]);
exit(98);
}

file_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, permissions);
if (file_to == -1)
{
dprintf(2, "Error: Can't write to %s\n", argv[2]);
exit(99);
}

do

{
rd = read(file_from, buffer, BUFFER_SIZE);
if (rd == -1)
{
dprintf(2, "Error: Can't read from %s\n", argv[1]);
exit(98);
}

wr = write(file_to, buffer, rd);
if (wr == -1)
{
dprintf(2, "Error: Can't write to %s\n", argv[2]);
exit(99);
}
} while (rd > 0);

if (close(file_from) == -1 || close(file_to) == -1)

dprintf(2, "Error: Can't close fd %d\n", (close(file_from) == -1) ? file_from : file_to);
exit(100);

return (0);
}
