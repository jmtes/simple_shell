#include "seashell.h"

/**
 * rev_string - Reverse string
 * @s: Pointer to string
 *
 * Description: Take string and reverse its order
 *
 * Return: N/A
 */
void rev_string(char *s)
{
	int len, i;
	char *start, *end, placehold;

	len = _strlen(s);

	start = s;
	end = s;
	for (i = 0; i < (len - 1); i++)
		end++;
	for (i = 0; i < (len / 2); i++)
	{
		placehold = *end;
		*end = *start;
		*start = placehold;

		start++;
		end--;
	}
}

char *_itoa(int n, char *str)
{
	int rem;

/*	if (n == 0)
	{
		*str = '0';
		*(str + 1) = '\0';
		return (str);
	}*/

	while (n != 0)
	{
		rem = n % 10;
		*str = (rem > 9)? (rem - 10) + 'a' : rem + '0';
		n /= 10;
		str++;
	}

	*str = '\0';

	rev_string(str);
	return (str);
}

int print_to_error(char *str)
{
	int len = _strlen(str);

	write(STDERR_FILENO, str, len);
	return (len);
}

int error_handler(char *shell_name, char *command)
{
	char *num_holder = NULL;

	num_holder = malloc(32);

	_strcpy(tmp, shell_name);
	_strcat(tmp, ": ");
	_strcat(tmp, _itoa(prompt_no, num_holder));
	_strcat(tmp, ": ");
	_strcat(tmp, command);
	_strcat(tmp, ": ");
	_strcat(tmp, "not found\n");
	print_to_error(tmp);
	free(num_holder);
	return (errno);
}
