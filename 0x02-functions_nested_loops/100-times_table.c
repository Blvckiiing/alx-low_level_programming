#include "main.h"

/**
 * print_times_table - prints the n times table, starting
 * with 0.
 * @n: the number of rows and columns of the table
 */
void print_times_table(int n)
{
	if (n < 0 || n > 15)
		return;

	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= n; j++)
		{
			int result = i * j;

			if (j == 0)
				_putchar('0');
			else
			{
				_putchar(',');
				_putchar(' ');

				if (result < 10)
					_putchar(' ');
				if (result < 100)
					_putchar(' ');

				_putnbr(result);
			}
		}
		_putchar('\n');
	}
}
