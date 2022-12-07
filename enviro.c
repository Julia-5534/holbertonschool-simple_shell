#include "shell.h"

char *enviro(char *envar);

/**
 * enviro - Function to return the environment global
 * @envar: global variable
 * Return: PATH to evironment variable or NULL on failure
 */

char *enviro(char *envar)
{
	int x = 0;
	size_t l = _strlen(envar);
	char *envs;

	if (!environ || !*envar)
		return (NULL);
	while (environ[x] && (_strncmp(envar, environ[x], l)))
		x++;
	if (environ[x])
	{
		envs = strndup(environ[x], l + 1);
		return (envs);
	}
	return (NULL);
}
