#include "shell.h"

int runBuiltIn(char **command);
int hey_exit(char **command);
int hey_env(void);

/**
 * runBuiltIn - function that runs built in commands
 * @command: array of strings containing command and args
 * Return: -1 if command isn't built in, else index num of built in
 */
int runBuiltIn(char **command)
{
	builtIn_t betty[] = {
		{ "exit", hey_exit },
		{ "env", hey_env },
		{ NULL, NULL }
	};
	int i;
	for (i = 0; betty[i].fun; i++)
	{
		if (_strcmp(betty[i].fun, command[0]) == 0 && _strlen(command[0]) == _strlen(betty[i].fun))
		{
			betty[i].f(command);
			ret_val = 0;
			return (i);
		}
	}
	return (-1);
}

/**
 * hey_exit - built in exit for shell program
 * @command: array of strings containing command and args
 */
int hey_exit(char **command)
{
	free_tokens(command);
	free_path(pathArr);
	exit(ret_val);
}

/**
 * hey_env - built in function to print local env
 * Return: status
 */
int hey_env(void)
{
	int j = 0, i = 0;

	while (environ[i] != NULL)
	{
		j = 0;
		while (environ[i][j] != '\0')
		{
			write(environ[i][j]);
			j++;
		}
		write('\n');
		i++;
	}
	return (0);
}