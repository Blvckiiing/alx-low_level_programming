#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

ssize_t read_textfile(const char *filename, size_t letters)
{
	char *buf;
	ssize_t fd;
	ssize_t r, w = 0;

	if (filename == NULL)
	{
		perror("filename is NULL");
		return (0);
	}

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		perror("open");
		return (0);
	}

	buf = malloc(sizeof(char) * letters);
	if (buf == NULL)
	{
		perror("malloc");
		close(fd);
		return (0);
	}

	r = read(fd, buf, letters);
	if (r == -1)
	{
		perror("read");
		free(buf);
		close(fd);
		return (0);
	}

	while (r > 0)
	{
		w = write(STDOUT_FILENO, buf, r);
		if (w == -1)
		{
			perror("write");
			free(buf);
			close(fd);
			return (0);
		}
		r -= w;
	}

	free(buf);
	close(fd);

	return (w);
}
