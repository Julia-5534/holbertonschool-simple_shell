#include "main.h"

void bIn_exit(char **envp, char **command, char **pathArr)
{
	if (envp)
		/*place holder*/
	free_tokens(command);
	free_path(pathArr);
	exit(EXIT_SUCCESS);
}

void bIn_env(char **envp, char **command, char **pathArr)
{
	unsigned int i = 0;

	if (pathArr)
	/*placeholder*/
	for (; envp[i]; i++)
	{
		write(STDOUT_FILENO, envp[i], _strlen(envp[i]));
		write(STDOUT_FILENO, "/n", 1);
	}
	free_tokens(command);
}

/**
 * runBuiltIn - runs builtin comm
 * @envp: environ vars
 * Return: void
 */
int runBuiltIn(char *envp[], char **command, char **pathArr)
{
	builtIn_t betty[] = {{"exit", bIn_exit}, {"env", bIn_env}, {NULL, NULL}};
	unsigned int i = 0;

	for (; betty[i].fun; i++)
	{	
		if (_strcmp(betty[i].fun, command[0]) == 0)
		{
			betty[i].f(envp, command, pathArr);
			return (i);
		}
	}	
	return (-1);
}
