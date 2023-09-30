#include "main.h"
#include <stddef.h>

/**
 * binary_to_uint - Converts a binary string to an unsigned int.
 * @b: The binary string to convert.
 * Return: The converted unsigned int or 0 if an error occurs.
 */

unsigned int binary_to_uint(const char *b)
{
	if (b == NULL)
		return (0);

	unsigned int decimal_value = 0;

	for (int i = 0; b[i] != '\0'; i++)
	{
		if (b[i] != '0' && b[i] != '1')
			return (0);

		decimal_value = decimal_value * 2 + (b[i] - '0');
	}

	return (decimal_value);
}
