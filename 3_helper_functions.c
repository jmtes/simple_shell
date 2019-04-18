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

/**
 * _strstr - pointer to break function
 *
 * @needle: string being checked for in string s
 * @haystack: string to check
 * Return: substring
 */

char *_strstr(char *haystack, char *needle)
{
	unsigned int i = 0, j = 0;

	while (haystack[i])
	{
		while (needle[j] && haystack[i] == needle[0])
	{
		if (haystack[i + j] == needle[j])
			j++;
		else
			break;
	}
	if (needle[j])
	{
		i++;
		j = 0;
	}
	else
		return (haystack + i);
	}
	return (0);
}

/**
 * is_empty - Determine if user input is empty
 * @usr_input: String containing user input
 *
 * Return: 1 if string is empty, 0 otherwise
 */

int is_empty(char *usr_input)
{
	while (*usr_input)
	{
		if (*usr_input != ' ' && *usr_input != '\t')
			return (0);
		usr_input++;
	}
	return (1);
}

int is_a_path(char *token)
{
	if (*token == '/')
		return (1);
	if (*token == '.')
	{
		if (*(token + 1) == '/')
			return (1);
		if (*(token + 1) == '.')
		{
			if (*(token + 2) == '/')
				return (1);
		}
	}
	return (0);
}
