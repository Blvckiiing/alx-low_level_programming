#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

/**
 * create_file - Creates a file and writes text content to it.
 * @filename: The name of the file to create.
 * @text_content: The text content to write to the file (can be NULL).
 *
 * Return: 1 on success, -1 on failure.
 */
int create_file(const char *filename, char *text_content)
{
	int fd, w, len = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
		for (len = 0; text_content[len]; len++)
			;
}

fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, S_IRUSR | S_IWUSR);
if (fd == -1)
	return (-1);
if (text_content != NULL)
{
	w = write(fd, text_content, len);

	if (w == -1)
	{
		close(fd);
		return (-1);
	}
}

if (chmod(filename, S_IRUSR | S_IWUSR) == -1)
{
	close(fd);
	return (-1);
}

close(fd);

return (1);
}
