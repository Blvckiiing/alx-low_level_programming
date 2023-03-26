#include <stdio.h>

/**
 * mul - multiplies two integers
 * @a: the first integer
 * @b: the second integer
 *
 * Return: the product of a and b
 */
int mul(int a, int b)
{
	int product = a * b;

	return (product);
}

/**
 * main - Entry point
 *
 * This function calls the mul function with two different sets of arguments
 * and prints the resulting products to the console using printf.
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	printf("%d\n", mul(98, 1024));
	printf("%d\n", mul(-402, 4096));
	return (0);
}
