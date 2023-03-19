#include <stdio.h>

/*
 * Prints all possible two-digit combinations of the digits 0-9.
 *
 * This program prints all possible two-digit combinations of the digits 0-9,
 * separated by commas and spaces. The digits are printed in ascending order.
 *
 * Returns:
 *     0 on successful completion.
 */
int main(void)
{
	int i, j;

	for (i = 0; i < 10; i++)
	{
		for (j = i + 1; j < 10; j++)
		{
			putchar(i + '0');
			putchar(j + '0');
			if (i < 8 || j < 9)
			{
				putchar(',');
				putchar(' ');
			}
		}
	}
	putchar('\n');

	return (0);
}
