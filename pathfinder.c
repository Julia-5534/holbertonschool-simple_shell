#include "shell.h"

char **path_locate(char *envvar);
char **path_tok(char *path);
char *check_paths(char *command);

/**
 * path_locate - yoinks path from env
 * @envvar: env var array in
 * Return: array of path strs
 */
char **path_locate(char *envvar)
{
	unsigned int i = 0;

	/* check that suitable environment exists */
	if (!environ)
		return (NULL);
	if (!(*environ))
		return (NULL);
	if (!(**environ))
		return (NULL);
	/* search environmental vars for PATH */
	for (; environ[i]; i++)
	{
		if (_strncmp(envvar, environ[i], _strlen(envvar)) == 0)
		{
			pathArr = path_tok(environ[i]);
			return (pathArr);
		}
	}
	return (pathArr);
}

/**
 * path_tok - supplies path info to tokenizer
 * @path: PATH from inherited env
 * Return: tokenized PATH
 */
char **path_tok(char *path)
{
	char *separator = ":";

	pathArr = tokstr(path, separator);
	/* move pointer past PATH= component of str */
	pathArr[0] += 5;
	return (pathArr);
}

/**
 * check_paths - checks pathArr against command[0]
 * @command: first tok of command array
 * Return: composite path to command if one exists
 */
char *check_paths(char *command)
{
	unsigned int i = 0, pathLen = 0;
	struct stat s;
	char *cmpPath = NULL;

	/* check if command supplied contained valid path */
	if (stat(command, &s) == 0)
		return (command);
	/* create tokenized path array from env PATH var */
	pathArr = path_locate("PATH=");
	/* check that path array was populated */
	if (!pathArr)
		return (command);
	/* cat path array w/ command supplied and check validity */
	if (command[0] != '/' && command[0] != '.')
	{
		for (; pathArr[i]; i++)
		{
			pathLen = (_strlen(pathArr[i]) + _strlen(command) + 2);
			cmpPath = malloc(sizeof(char) * pathLen);
			_strcpy(cmpPath, pathArr[i]);
			_strcat(cmpPath, "/");
			_strcat(cmpPath, command);
			if (stat(cmpPath, &s) == 0)
			{
				free_path(pathArr);
				return (cmpPath);
			}
			free(cmpPath);
		}
	}
	free_path(pathArr);
	return (command);
}
