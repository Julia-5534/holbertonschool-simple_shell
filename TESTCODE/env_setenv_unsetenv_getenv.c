#include "shell.h"

int hey_setenv(char **args, char **__attribute__((__unused__)), char __attribute__((__unused__)) **front);
int hey_unsetenv(char **args, char **__attribute__((__unused__)), char __attribute__((__unused__)) **front);
char **_getenv(char *var);

/**
 * hey_setenv - Changes or adds an environmental variable to the PATH.
 * @argArr: An array of arguments passed to the shell.
 * @front: A double pointer to the beginning of args.
 * @args: because we said so
 * Description: argArr[1] is the name of the new or existing PATH variable.
 *              argArr[2] is the value to set the new or changed variable to.
 *
 * Return: If an error occurs - -1.
 *         Otherwise - 0.
 */
int hey_setenv(char __attribute__((__unused__)) **args, char __attribute__((__unused__)) **argArr, char __attribute__((__unused__)) **front)
{
	char **env_var = NULL, **new_environ, *new_value;
	char args;
	size_t size;
	int index;

	if (!argArr[0] || !argArr[1])
		return (create_error(argArr, -1));

	new_value = malloc(_strlen(argArr[0]) + 1 + _strlen(argArr[1]) + 1);
	if (!new_value)
		return (create_error(argArr, -1));
	_strcpy(new_value, argArr[0]);
	_strcat(new_value, "=");
	_strcat(new_value, argArr[1]);

	env_var = _getenv(argArr[0]);
	if (env_var)
	{
		free(*env_var);
		*env_var = new_value;
		return (0);
	}
	for (size = 0; environ[size]; size++)
		;

	new_environ = malloc(sizeof(char *) * (size + 2));
	if (!new_environ)
	{
		free(new_value);
		return (create_error(argArr, -1));
	}

	for (index = 0; environ[index]; index++)
		new_environ[index] = environ[index];

	free(environ);
	environ = new_environ;
	environ[index] = new_value;
	environ[index + 1] = NULL;

	return (0);
}

/**
 * hey_unsetenv - Deletes an environmental variable from the PATH.
 * @argArr: An array of arguments passed to the shell.
 * @front: A double pointer to the beginning of args.
 * @whatx: because we said so
 * Description: argArr[1] is the PATH variable to remove.
 *
 * Return: If an error occurs - -1.
 *         Otherwise - 0.
 */
int hey_unsetenv(char **argArr, char __attribute__((__unused__)) **whatx, char __attribute__((__unused__)) **front)
{
	char **env_var, **new_environ;
	char whatx;
	size_t size;
	int index, index2;

	if (!argArr[0])
		return (create_error(argArr, -1));
	env_var = _getenv(argArr[0]);
	if (!env_var)
		return (0);

	for (size = 0; environ[size]; size++)
		;

	new_environ = malloc(sizeof(char *) * size);
	if (!new_environ)
		return (create_error(argArr, -1));

	for (index = 0, index2 = 0; environ[index]; index++)
	{
		if (*env_var == environ[index])
		{
			free(*env_var);
			continue;
		}
		new_environ[index2] = environ[index];
		index2++;
	}
	free(environ);
	environ = new_environ;
	environ[size - 1] = NULL;

	return (0);
}

/**
 * _getenv - Gets an environmental variable from the PATH.
 * @var: The name of the environmental variable to get.
 *
 * Return: If the environmental variable does not exist - NULL.
 *         Otherwise - a pointer to the environmental variable.
 */
char **_getenv(char *var)
{
	int index, len;

	len = _strlen(var);
	for (index = 0; environ[index]; index++)
	{
		if (_strncmp(var, environ[index], len) == 0)
			return (&environ[index]);
	}

	return (NULL);
}
