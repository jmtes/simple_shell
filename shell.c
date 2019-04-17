#include "seashell.h"

/**
 * get_filepath - Get file_path
 *
 * @command: Input in command line
 *
 * Return: Null
 */

char *get_filepath(char *command)
{
	/*char *tmp = NULL;*/
	dir_list_t *list = NULL;
	dir_list_t *current = NULL;
	char *a, *b, *PATH;

	list = make_path_list();
	current = list;

	PATH = _getenv("PATH");
	if (PATH)
	{
		a = strstr(PATH, "::");
		b = strstr(PATH, ":/bin");
		if (PATH[0] == ':' || PATH[_strlen(PATH) - 1] == ':' ||
		    (a && (a < b)))
		{
			if (!access(command, F_OK))
				return (command);

		}
	}

	while (current)
	{
		_strcpy(tmp, current->dir_path);
		_strcat(tmp, "/");
		_strcat(tmp, command);

		if (!access(tmp, F_OK))
		{
			free_list(&list);
			return (tmp);
		}
		current = current->next;
	}
	free_list(&list);
	return (NULL);
}

/**
 * word_count - Function to get the length of string
 *
 * @string: Input string being counted
 * Return: Count of string
 */

int word_count(char *string)
{
	int count = 0;

	char *find_delim = string;

	while (*find_delim)
	{
		if (*find_delim == ' ')
			count++;
		find_delim++;
	}
	count += 2;
	return (count);
}

/**
 * make_argv - Function that shows args using strtok
 *
 * @string: arguments displayed
 * Return: Array of strings
 */

char **make_argv(char *string)
{
	char *token = NULL;
	int i, count = 0;

	count = word_count(string);
	array = malloc(sizeof(char *) * (count + 1));
	array[count] = NULL;
	i = 0;
	token = strtok(string, " \t");
	if (!token)
	{
		free(array);
		return (NULL);
	}
	array[i++] = token;
	while (token)
	{
		token = strtok(NULL, " \t");
		array[i] = token;
		i++;
	}
	token = array[0];
	if (*token != '/')
	{
		if (!strcmp(token, "exit"))
		{
			free(array);
			free(string);
			exit(0);
		}

		array[0] = get_filepath(token);
		if (!array[0])
		{
			free(array);
			return (NULL);
		}
	}
	return (array);
}

/**
 * exec_command - Function that executes coomand
 *
 * @usr_input: Input string to be executed
 * Return: void
 */

void exec_command(char *usr_input)
{
	char **argv = NULL;
	pid_t is_parent, j;

	argv = make_argv(usr_input);
	if (!argv)
	{
		_printf("Something is going terribly wrong.");
		free(usr_input);
		return;
	}

	is_parent = fork();

	if (is_parent == 0)
	{
		j = execve(argv[0], argv, NULL);
		if (j == -1)
		{
			_printf("./shell: No such file or directory\n");
			free(argv);
			free(usr_input);
			return;
		}
	}

	wait(NULL);
	free(argv);
	free(usr_input);
	return;
}

/**
 * main - Function main
 *
 * Return: void
 */

int main(void)
{
	char *newline = NULL;
	size_t bufsize = 1024;
	ssize_t p;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			_printf("$ ");
		usr_input = malloc(1024);
		if (!usr_input)
			return (-1);
		p = getline(&usr_input, &bufsize, stdin);
		if (p == -1)
		{
			free(usr_input);
			exit(0);
		}
		newline = _strchr(usr_input, '\n');
		if (newline)
			*newline = '\0';

		if (!*usr_input)
		{
			free(usr_input);
			continue;
		}

		if (!strcmp(usr_input, "env"))
		{
			env_builtin();
			free(usr_input);
			continue;
		}
		exec_command(usr_input);
	}
	free(usr_input);
	return (0);
}
