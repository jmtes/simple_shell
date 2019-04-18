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

char *_itoa(int n)
{
	char *st;
	char *string;
	char *digits = "0123456789";

	string = malloc(32);
	if (!string)
		exit(1);

	st = string;

	do {
		*st = digits[n % 10];
		n /= 10;
		st++;
	} while (n);

	*st = '\0';
	st--;

	rev_string(string);

	return (string);
}

int print_to_error(char *str)
{
	int len = _strlen(str);

	write(STDERR_FILENO, str, len);
	return (len);
}

int error_handler(char *shell_name, char *command, int prompt_no)
{
	char *num_holder = NULL;

	num_holder = _itoa(prompt_no);

	_strcpy(tmp, shell_name);
	_strcat(tmp, ": ");
	_strcat(tmp, num_holder);
	_strcat(tmp, ": ");
	_strcat(tmp, command);
	_strcat(tmp, ": ");
	_strcat(tmp, "not found\n");
	print_to_error(tmp);
	free(num_holder);
	return (errno);
}
