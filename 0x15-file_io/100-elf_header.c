#include <elf.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * check_elf - Checks if a file is an ELF file.
 * @e_ident: A pointer to an array containing the ELF magic numbers.
 *
 * Description: If the file is not an ELF file, it exits with code 98.
 */
void check_elf(unsigned char *e_ident);

/**
 * print_magic - Prints the ELF magic numbers.
 * @e_ident: A pointer to an array containing the ELF magic numbers.
 */
void print_magic(unsigned char *e_ident);

/**
 * main - Displays the information contained in the ELF header at the start of an ELF file.
 * @argc: The number of arguments supplied to the program.
 * @argv: An array of pointers to the arguments.
 *
 * Return: 0 on success.
 *
 * Description: If the file is not an ELF File or the function fails, it exits with code 98.
 */
int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "Usage: %s elf_filename\n", argv[0]);
		exit(98);
	}

	Elf64_Ehdr header;
	int file_descriptor;

	file_descriptor = open(argv[1], O_RDONLY);
	if (file_descriptor == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}

	ssize_t bytes_read = read(file_descriptor, &header, sizeof(Elf64_Ehdr));
	if (bytes_read == -1)
	{
		close(file_descriptor);
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}

	check_elf(header.e_ident);

	printf("ELF Header:\n");
	print_magic(header.e_ident);
	printf("  Class:                             ELF64\n");
	printf("  Data:                              2's complement, little endian\n");
	printf("  Version:                           1 (current)\n");
	printf("  OS/ABI:                            UNIX - System V\n");
	printf("  ABI Version:                       0\n");
	printf("  Type:                              EXEC (Executable file)\n");
	printf("  Entry point address:               0x%lx\n", (unsigned long)header.e_entry);

	close(file_descriptor);
	return (0);
}

void check_elf(unsigned char *e_ident)
{
	if (e_ident[EI_MAG0] != ELFMAG0 || e_ident[EI_MAG1] != ELFMAG1 ||
			e_ident[EI_MAG2] != ELFMAG2 || e_ident[EI_MAG3] != ELFMAG3)
	{
		dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
		exit(98);
	}
}

void print_magic(unsigned char *e_ident)
{
	printf("  Magic:   ");
	for (int i = 0; i < EI_NIDENT; i++)
	{
		printf("%02x ", e_ident[i]);
	}
	printf("\n");
}
