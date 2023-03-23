#include <stdlib.h>
#include "main.h"

/**
 * print_last_digit - Print the last digit of a number
 * @n: The number to print the last digit of
 *
 * Return: The value of the last digit
 */
int print_last_digit(int n)
{
	int last_digit;

	if (n < 0)
		n = -n;

	last_digit = n % 10;

	_putchar('0' + last_digit);

	return (last_digit);
}
