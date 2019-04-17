#include "seashell.h"
/**
 * print_unsign - print unsigned int
 * @n: an int
 *
 * Return: int otherwise -1
 */

int print_unsign(int n)
{
	unsigned int n1;
	int c = 0;

	if (n < 0)
	{
		_putchar('-');
		n1 = -n;
	}
	else
		n1 = n;
	if (n1 / 10)
		c = print_unsign(n1 / 10);
	_putchar((n1 % 10) + '0');
	return (1 + c);
}

/**
 * counter - print integer
 * @j: counter of argument
 * Return: int otherwise -1
 */
int counter(int j)
{
	unsigned int abs = 0;
	unsigned int counter = 0;

	if (j < 0)
		abs = -j;
	else
		abs = j;
	if (abs)
		counter++;
	return (counter);
}
/**
 * print_integer - print integer
 * @all_parameters: arguments
 * Return: int otherwise -1
 */

int print_integer(va_list all_parameters)
{
	int i = va_arg(all_parameters, int);
	int count = 0;

	count = counter(i);
	if (i <= 0)
		count++;
	return (count + print_unsign(i) - 1);
}
