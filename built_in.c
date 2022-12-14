#include "shell.h"

int runBuiltIn(char **command, char *line);
int hey_exit(char **command);
int hey_env(char **command);

/**
 * runBuiltIn - function that runs built in commands
 * @command: array of strings containing command and args
 * @line: user input line from getline
 * Return: -1 if command isn't built in, else index num of built in
 */
int runBuiltIn(char **command, char *line)
{
	builtIn_t betty[] = {
		{ "exit", hey_exit },
		{ "env", hey_env },
		{ NULL, NULL }
	};
	int i;

	for (i = 0; betty[i].fun; i++)
	{
		if (_strcmp(betty[i].fun, command[0]) == 0 &&
		_strlen(command[0]) == _strlen(betty[i].fun))
		{
			if (i == 0)
				free(line);
			betty[i].f(command);
			free_tokens(command);
			ret_val = 0;
			return (i);
		}
	}
	return (-1);
}

/**
 * hey_exit - built in exit for shell program
 * @command: array of strings containing command and args
 * Return: exit status of last command
 */
int hey_exit(char **command)
{
	free_path(pathArr);
	free_tokens(command);
	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "\n", 1);
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

	if (!environ || !(*environ))
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
