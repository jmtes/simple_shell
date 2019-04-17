#include "seashell.h"

/**
 * _printf - Pared down printf with variable arg list
 * @format: format arguments
 * Return: Number of chars printed excluding the null byte
 */
int _printf(const char *format, ...)
{
/* points to each unnamed arg in turn */
	va_list all_parameters;
	int i, j, count = 0;

	va_start(all_parameters, format);
/* All below are validation statements */
	if (!format || (format[0] == '%' && !format[1]))
		return (-1);

	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
			i++;
		else
		{
			_putchar(format[i]);
			i++;
			count++;
			continue;
		}
		j = get_struct(format[i], all_parameters);
		if (j == -1)
		{
			_putchar('%');
			_putchar(format[i]);
			count += 2;
		}
		else
			count += j;
		i++;
	}
/* Cleans up the list */
	va_end(all_parameters);
/* Returns char count here */
	return (count);
}

/**
 * get_struct - gets struct
 * @c: the char
 * @all_parameters: ap
 * Return: struct
 */
int get_struct(char c, va_list all_parameters)
{
	specifier_t structs_ar[] = {
		{'c', print_char},
		{'s', print_string},
		{'%', print_percent},
		{'d', print_integer},
		{'i', print_integer},
		{'\0', NULL}
	};
	int j = 0;

	while (structs_ar[j].function_ptr)
	{
		if (c == structs_ar[j].spec)
		{
			return (structs_ar[j].function_ptr(all_parameters));
		}
		j++;
	}
	return (-1);
}
