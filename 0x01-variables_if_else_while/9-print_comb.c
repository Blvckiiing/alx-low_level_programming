#include <stdio.h>

/**
 * main - Prints all possible different combinations of two digits.
 *
 * Description: Numbers must be separated by ', ', and the two digits must be different.
 * * 01 and 10 are considered the same combination of the two digits 0 and 1.
 * Only the smallest combination of two digits should be printed.
 * Numbers should be printed in ascending order, with two digits.
 *
 * Return: 0 on successful completion.
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
			if (i == 8 && j == 9)
				continue;
			putchar(',');
			putchar(' ');
		}
	}
	putchar('\n');

	return (0);
}
