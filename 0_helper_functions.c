#include "seashell.h"
/* define the format string in helper function file */

/**
 * print_char - print char
 * @all_parameters: Arguments
 * Return: int
 */

int print_char(va_list all_parameters)
{
	_putchar(va_arg(all_parameters, int));
	return (1);
}

/**
 * print_string - print string
 *
 * @all_parameters: arguments
 * Return: int
 */

int print_string(va_list all_parameters)
{
	char *s;
	int i = 0;

	s = va_arg(all_parameters, char *);

	if (!s)
		i = i + _puts("(null)");
	else
		i = i + _puts(s);
	return (i);
}

/**
 * print_percent - prints percentage sign
 *
 * @all_parameters: arguments in function
 * Return: int
 */

int print_percent(va_list all_parameters)
{
	char c = '%';

	(void) all_parameters;
/* Write the Character to stdout */
	_putchar(c);
	return (1);
}

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _puts - function used to place characters in string
 *
 * @str: String being printed
 * Return: i which is the value for the string
 */

int _puts(char *str)
{
	int i = 0;

	for ( ; *(str + i); i++)
	{
		_putchar(str[i]);
	}
	return (i);
}
