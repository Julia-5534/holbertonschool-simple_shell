#include "main.h"

void bIn_exit(char **envp)
{
	if (envp)
		/* YOLO */
	exit(EXIT_SUCCESS);
}

void bIn_env(char **envp)
{
	unsigned int i = 0;

	for (; envp[i]; i++)
	{
		write(STDOUT_FILENO, envp[i], _strlen(envp[i]));
	}
}

/**
 * runBuiltIn - runs builtin comm
 * @envp: environ vars
 * Return: void
 */
void runBuiltIn(char *envp[], char *command)
{
	builtIn_t betty[] = {{"exit", bIn_exit}, {"env", bIn_env}, {NULL, NULL}};
	unsigned int i = 0;

	for (; betty[i].fun; i++)
		if (_strcmp(betty[i].fun, command) == 0)
			betty[i].f(envp);
}
