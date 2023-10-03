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
 * main - Displays the information contained in the ELF header
 *        at the start of an ELF file.
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

	if (bytes_read = read)
		close(file_descriptor);
	dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
	exit(98);
}

{
	check_elf(header.e_ident);

	printf("ELF Header:\n");
	print_magic(header.e_ident);
	print_class(header.e_ident);
	print_data(header.e_ident);
	print_version(header.e_ident);
	print_osabi(header.e_ident);
	print_abi(header.e_ident);
	print_type(header.e_type, header.e_ident);
	print_entry(header.e_entry, header.e_ident);
}

close(file_descriptor);
return (0);
}

void check_elf(unsigned char *e_ident)
{
	void check_elf(unsigned char *e_ident)
		void print_magic(unsigned char *e_ident)
		void print_class(unsigned char *e_ident)
		void print_data(unsigned char *e_ident)
		void print_version(unsigned char *e_ident)
		void print_osabi(unsigned char *e_ident)
		void print_abi(unsigned char *e_ident)
		void print_type(unsigned int e_type, unsigned char *e_ident)
		void print_entry(Elf64_Addr e_entry, unsigned char *e_ident)
}
