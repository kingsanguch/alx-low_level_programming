#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

#define BUF_SIZE 64

/**
 * main - Entry point
 * @argc: Argument count
 * @argv: Argument vector
 * Return: 0 on success, 98 on failure
 */
int main(int argc, char *argv[])
{
int fd;
int i;
ssize_t bytes_read;
char buf[BUF_SIZE];

if (argc != 2)
{
dprintf(STDERR_FILENO, "Usage: %s elf_filename\n", argv[0]);
exit(98);
}

fd = open(argv[1], O_RDONLY);
if (fd == -1)
{
dprintf(STDERR_FILENO, "Error: Cannot open file '%s'\n", argv[1]);
exit(98);
}

/* Read the ELF header */
bytes_read = read(fd, buf, BUF_SIZE);
if (bytes_read == -1)
{
dprintf(STDERR_FILENO, "Error: Cannot read ELF header\n");
close(fd);
exit(98);
}

/* Check if it's a valid ELF file */
if (bytes_read < 4 || buf[0] != 0x7F || buf[1] != 'E' || buf[2] != 'L' || buf[3] != 'F')
{
dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
close(fd);
exit(98);
}

/* Display ELF Header information */
printf("ELF Header:\n");

/* Magic */
printf("  Magic:   ");
for (i = 0; i < 16; i++)
printf("%02x%c", buf[i], i < 15 ? ' ' : '\n');

/* Class */
printf("  Class:                             ELF%d\n", buf[4] == 1 ? 32 : 64);

/* Data */
printf("  Data:                              2's complement, %s endian\n", buf[5] == 1 ? "little" : "big");

/* Version */
printf("  Version:                           %d (current)\n", buf[6]);

/* OS/ABI */
printf("  OS/ABI:                            UNIX - System V\n");

/* ABI Version */
printf("  ABI Version:                       %d\n", buf[8]);

/* Type */
printf("  Type:                              ");
switch (*((uint16_t *)(buf + 16)))
{
case 1:
printf("REL (Relocatable file)\n");
break;
case 2:
printf("EXEC (Executable file)\n");
break;
case 3:
printf("DYN (Shared object file)\n");
break;
default:
printf("<unknown: %d>\n", *((uint16_t *)(buf + 16)));
}

/* Entry point address */
printf("  Entry point address:               0x");
for (i = 0; i < (buf[4] == 1 ? 4 : 8); i++)
printf("%02x", buf[24 + i]);
printf("\n");

close(fd);
return (0);
}
