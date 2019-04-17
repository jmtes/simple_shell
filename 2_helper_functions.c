#include "seashell.h"

/**
 * _strcat - Concatenate two strings
 * @dest: destination memory block
 * @src: pointer to string to be appended
 *
 * Description: Concatenate string pointed to by src to end of string pointed
 * to by dest
 *
 * Return: Pointer to dest
 */
char *_strcat(char *dest, char *src)
{
	_strcpy(dest + _strlen(dest), src);
	return (dest);
}

/**
 * *_strcpy - Copy string
 * @dest: pointer to destination buffer
 * @src: string to be copied
 *
 * Description: Copy string pointed to by src into buffer pointed to by dest
 *
 * Return: Pointer to dest
 */
char *_strcpy(char *dest, char *src)
{
	char *destination = dest;

	while (*src)
		*dest++ = *src++;
	*dest = 0;
	return (destination);
}

/**
 * _strlen - Find length of string
 * @s: Pointer to string
 *
 * Description: Take pointer to string and find the string's length
 *
 * Return: Length of string
 */
int _strlen(char *s)
{
	int len = 0;

	while (*s != '\0')
	{
		len++;
		s++;
	}
	return (len);
}

/**
 * _strdup - Copy string into newly allocated memory
 * @str: String to copy
 *
 * Return: Pointer to memory space with copied string
 */

char *_strdup(char *str)
{
	char *p;

	if (str == NULL)
		return (NULL);
	p = malloc(sizeof(char) * (_strlen(str) + 1));
	if (p == NULL)
		return (NULL);
	else
		return (_strcpy(p, str));
}

/**
 * _strcmp - Compare two strings
 * @s1: String 1
 * @s2: String 2
 *
 * Return: Positive int if s1 > s2, 0 if s1 = s2, negative int if s1 < s2
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*(const unsigned char *)s1 - *(const unsigned char *)s2);
}
