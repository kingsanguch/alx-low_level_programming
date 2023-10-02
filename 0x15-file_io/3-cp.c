#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFFER_SIZE 1024

/**
 * report_error - Reports an error message and exits with the given code.
 * @message: The error message format.
 * @filename: The filename to include in the message.
 * @exit_code: The exit code.
 */

void report_error(const char *message, const char *filename, int exit_code) {
    dprintf(STDERR_FILENO, message, filename);
    exit(exit_code);
}

/**
 * main - Copies the content of a file to another file.
 * @ac: The number of arguments.
 * @av: The array of arguments.
 *
 * Return: 0 on success, or an exit code on failure.
 */

int main(int ac, char **av) {
    int fd_from, fd_to;
    ssize_t bytes_read, bytes_written;
    char buffer[BUFFER_SIZE];

    if (ac != 3) {
        report_error("Usage: cp file_from file_to\n", "", 97);
    }

    fd_from = open(av[1], O_RDONLY);
    if (fd_from == -1) {
        report_error("Error: Can't read from file %s\n", av[1], 98);
    }

    fd_to = open(av[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
    if (fd_to == -1) {
        close(fd_from);
        report_error("Error: Can't write to %s\n", av[2], 99);
    }

    while ((bytes_read = read(fd_from, buffer, BUFFER_SIZE)) > 0) {
        bytes_written = write(fd_to, buffer, bytes_read);
        if (bytes_written == -1 || bytes_written != bytes_read) {
            close(fd_from);
            close(fd_to);
            report_error("Error: Can't write to %s\n", av[2], 99);
        }    }

    if (bytes_read == -1) {
        close(fd_from);
        close(fd_to);
        report_error("Error: Can't read from file %s\n", av[1], 98);
    }

    if (close(fd_from) == -1) {
        report_error("Error: Can't close fd %d\n", av[1], 100);
    }

    if (close(fd_to) == -1) {
        report_error("Error: Can't close fd %d\n", av[2], 100);
    }

    return 0;
}

