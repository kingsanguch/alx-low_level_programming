#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define ELF_MAGIC_SIZE 16
#define BUFFER_SIZE 64

/**
 * main - Displays the information contained in the ELF header of an ELF file.
 * @argc: The number of arguments.
 * @argv: The array of arguments.
 *
 * Return: 0 on success, or exit with status code 98 on failure.
 */
int main(int argc, char **argv)
{
int fd, read_bytes;
char elf_magic[ELF_MAGIC_SIZE];
char buffer[BUFFER_SIZE];

if (argc != 2)
{
dprintf(STDERR_FILENO, "Usage: %s elf_filename\n", argv[0]);
return (98);
}

fd = open(argv[1], O_RDONLY);
if (fd == -1)
{
dprintf(STDERR_FILENO, "Error: Cannot read file '%s'\n", argv[1]);
return (98);
}
read_bytes = read(fd, elf_magic, ELF_MAGIC_SIZE);
if (read_bytes != ELF_MAGIC_SIZE || elf_magic[0] != 0x7f || elf_magic[1] != 'E' || elf_magic[2] != 'L' || elf_magic[3] != 'F')
{
dprintf(STDERR_FILENO, "Error: Not an ELF file: '%s'\n", argv[1]);
close(fd);
return (98);
}

lseek(fd, 0, SEEK_SET);
read_bytes = read(fd, buffer, BUFFER_SIZE);
if (read_bytes == -1)
{
dprintf(STDERR_FILENO, "Error: Cannot read file '%s'\n", argv[1]);
close(fd);
return (98);
}

printf("ELF Header:\n");
printf("  Magic:   ");
for (int i = 0; i < ELF_MAGIC_SIZE; i++)
{
printf("%02x", elf_magic[i]);
if (i < ELF_MAGIC_SIZE - 1)
printf(" ");
}
printf("\n");

printf("  Class:                             ELF%d\n", buffer[4] == 1 ? 32 : 64);
printf("  Data:                              2's complement, %s endian\n", buffer[5] == 1 ? "little" : "big");
printf("  Version:                           1 (current)\n");
printf("  OS/ABI:                            UNIX - %s\n", buffer[7] == 0 ? "System V" : "Other");
printf("  ABI Version:                       %d\n", buffer[8]);
printf("  Type:                              ");
switch (*(unsigned int *)(buffer + 16))
{
case 0:
printf("NONE (None)\n");
break;
case 1:
printf("REL (Relocatable file)\n");
break;
case 2:
printf("EXEC (Executable file)\n");
break;
case 3:
printf("DYN (Shared object file)\n");
break;
case 4:
printf("CORE (Core file)\n");
break;
default:
printf("<unknown: %d>\n", *(unsigned int *)(buffer + 16));
break;
}
printf("  Entry point address:               0x");
for (int i = 0; i < 8; i++)
printf("%02x", buffer[24 + i]);
printf("\n");

close(fd);
return (0);
}
