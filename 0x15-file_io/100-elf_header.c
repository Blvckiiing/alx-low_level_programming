#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <elf.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

void print_error(const char *message)
{
	fprintf(stderr, "%s\n", message);
	exit(98);
}

void read_elf_header(int fd)
{
	Elf64_Ehdr elf_header;
	if (read(fd, &elf_header, sizeof(Elf64_Ehdr)) != sizeof(Elf64_Ehdr))
	{
		print_error("Unable to read ELF header");
	}

	if (elf_header.e_ident[EI_MAG0] != ELFMAG0 ||
        elf_header.e_ident[EI_MAG1] != ELFMAG1 ||
        elf_header.e_ident[EI_MAG2] != ELFMAG2 ||
        elf_header.e_ident[EI_MAG3] != ELFMAG3)
	{
		print_error("Not an ELF file");
	}
	printf("ELF Header:\n");
	printf("  Magic:   ");
	for (int i = 0; i < EI_NIDENT; i++)
	{
		printf("%02x ", elf_header.e_ident[i]);
	}

	printf("\n");
	printf("  Class:
			ELF%d\n", elf_header.e_ident[EI_CLASS]);
	printf("  Data:
			%s\n", (elf_header.e_ident[EI_DATA] == ELFDATA2LSB) ? "2's complement, little endian" : "2's complement, big endian");
	printf("  Version:
			%d (current)\n", elf_header.e_ident[EI_VERSION]);
	printf("  OS/ABI:
			%s\n", (elf_header.e_ident[EI_OSABI] == ELFOSABI_SYSV) ? "UNIX - System V" : "Unknown");
	printf("  ABI Version:
			%d\n", elf_header.e_ident[EI_ABIVERSION]);
	printf("  Type:
			%d (Executable file)\n", elf_header.e_type);
	printf("  Entry point address:
			0x%lx\n", (unsigned long)elf_header.e_entry);
}

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		print_error("Usage: elf_header elf_filename");
	}

	int fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		print_error("Unable to open file");
	}

	read_elf_header(fd);
	close(fd);

	return 0;
}
