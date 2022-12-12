#include "shell.h"

int runBuiltIn(char **command);
int hey_exit(char **command);
int hey_env(char **command);

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
 * @command: array of strings containing command and args
 * Return: -1 on bad magic 0 otherwise
 */
int hey_env(char **command)
{
	int i, j;

	if (!(environ))
	{
		return (-1);
	}
	for (i = 0; environ[i]; i++)
	{
		for (j = 0; environ[i][j]; j++)
		{
			write(STDOUT_FILENO, &environ[i][j], 1);
		}
		write(STDOUT_FILENO, "\n", 1);
	}
	(void)command;
	return (0);
}
