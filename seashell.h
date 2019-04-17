#ifndef SEASHELL_H
#define SEASHELL_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include <sys/stat.h>
#include <stdarg.h>

/**
 * struct specifier - function that produces output according to a format
 *
 * @spec: Format to print
 * @function_ptr: The function pointer to the specifier
 */
typedef struct specifier
{
	char spec;
	int (*function_ptr)(va_list);
} specifier_t;

/**
 * struct dir_node - Nodes of list of PATH directories
 *
 * @dir_path: Directory name
 * @next: Pointer to next list node
 */

typedef struct dir_node
{
	char *dir_path;
	struct dir_node *next;
} dir_list_t;

extern char **environ;
char *usr_input;
char **array;
char tmp[256];

void env_builtin(void);

/*linked list operations*/
void free_list(dir_list_t **head);
dir_list_t *add_node_end(dir_list_t **head, const char *str);
char *_getenv(char *name);
dir_list_t *make_path_list(void);

/*_printf functions*/
int _printf(const char *format, ...);
int _putchar(char c);
int print_char(va_list all_parameters);
int print_string(va_list all_parameters);
int print_percent(va_list all_parameters);
int print_integer(va_list all_parameters);
int print_unsign(int n);
int counter(int j);
int _puts(char *str);
int get_struct(char c, va_list all_parameters);

/*general helper functions*/
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
int _strlen(char *s);
char *_strdup(char *str);
int _strcmp(char *s1, char *s2);
char *_strchr(char *s, char c);

#endif
