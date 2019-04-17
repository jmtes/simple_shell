#include "seashell.h"

/**
 * free_list - Function the frees linked list
 *
 * @head: Points to node in the beginning
 * Return: void
 */

void free_list(dir_list_t **head)
{
	dir_list_t *temp;

	if (!head)
		return;

	while ((*head))
	{
		temp = (*head)->next;
		free((*head)->dir_path);
		free(*head);
		*head = temp;
	}
}

/**
 * add_node_end - Function adds node to end of linkedlist
 *
 * @head: Beginnig of linked list
 * @str: String being checked
 * Return: Returns address of new_node
 */

dir_list_t *add_node_end(dir_list_t **head, const char *str)
{
	dir_list_t *tail = *head;
	dir_list_t *new_node = NULL;
	char *new_dir_path = NULL;

	if (!str)
		return (NULL);

	new_node = malloc(sizeof(dir_list_t));
	if (!new_node)
		return (NULL);

	new_dir_path = strdup(str);
	if (str && !new_dir_path)
	{
		free(new_node);
		return (NULL);
	}

	new_node->dir_path = new_dir_path;
	new_node->next = NULL;

	if (!*head)
		*head = new_node;
	else
	{
		while (tail->next)
			tail = tail->next;
		tail->next = new_node;
	}
	return (new_node);
}

/**
 * _getenv - Function that searches for environment var
 *
 * @name: name of environment variable
 * Return: Pointer to corresponding value
 */

char *_getenv(char *name)
{
	char *token = NULL;
	char *env_cpy = NULL;

	while (*environ)
	{
		env_cpy = strdup(*environ);
		token = strtok(env_cpy, "=");

		if (!strcmp(token, name))
		{
			token = strtok(NULL, "\0");
			/*token = strdup(token);*/
			return (token);
		}
		free(env_cpy);
		environ++;
	}
	return (NULL);
}

/**
 * make_path_list - Function that gets PATH to a variable
 *
 * Return: head
 */

dir_list_t *make_path_list(void)
{
	char *path_value = NULL;
	char *token = NULL;
	dir_list_t *head = NULL;

	path_value = _getenv("PATH");
	if (!path_value)
		return (NULL);

	head = NULL;

	token = strtok(path_value, ":");
	add_node_end(&head, token);

	while (token)
	{
		token = strtok(NULL, ":");
		add_node_end(&head, token);
	}
	return (head);
}
