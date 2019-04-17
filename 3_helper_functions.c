#include "seashell.h"

/**
 * _strchr - Function returns pointer to char
 *
 * @s: Pointer to string
 * @c: char being pointed to
 * Return: Pointer to last occurence
 */

char *_strchr(char *s, char c)
{
	while (*s)
	{
		if (*s == c)
			return (s);
		s++;
	}
	return (NULL);
}

/**
 * env_builtin - env builtins
 *
 * Return: void
 */

void env_builtin(void)
{
	size_t i;

	for (i = 0; environ[i] != NULL; i++)
	{
		_puts(environ[i]);
		_putchar('\n');
	}
}
