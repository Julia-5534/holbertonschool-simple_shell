#include "main.h"

/**
 * path_locate - yoinks path from env
 * @envvars: env var array in
 * Return: array of path strs
 */
char **path_locate(char *envvars[])
{
	unsigned int i = 0;
	char **daWay = NULL;

	for (; envvars[i]; i++)
	{
		if (_strncmp("PATH", envvars[i], 4) == 0)
		{
			daWay = path_tok(envvars[i]);
			return (daWay);
		}
	}
	return (daWay);
}

/**
 * path_tok - supplies path info to tokenizer
 * @path: PATH from inherited env
 * Return: tokenized PATH
 */
char **path_tok(char *path)
{
	char **thePaths;
	char *separator = ":";

	thePaths = tokstr(path, separator);
	thePaths[0] += 5;
	return (thePaths);
}

/**
 * print_paths - shows the tokenized paths
 * @pathArr: array of path strs
 * Return: void, for testing
 */
void print_paths(char **pathArr)
{
	unsigned int i = 0;

	for (; pathArr[i]; i++)
	{
		/* placeholder */
	}
}

/**
 * check_paths - checks pathArr against command[0]
 * @pathArr: array of paths
 * @command: first tok of command array
 * Return: num of valid path located or NULL if none
 */
char *check_paths(char **pathArr, char *command)
{
	unsigned int i = 0, pathLen = 0;
	struct stat s;
	char *cmpPath = NULL;

	for (; pathArr[i]; i++)
	{
		pathLen = (_strlen(pathArr[i]) + _strlen(command) + 2);
		cmpPath = malloc(sizeof(char) * pathLen);
		_strcpy(cmpPath, pathArr[i]);
		_strcat(cmpPath, "/");
		_strcat(cmpPath, command);
		if (stat(cmpPath, &s) == 0)
		{
			return (cmpPath);
		}
		free(cmpPath);
	}
	if (stat(command, &s) == 0)
		return (command);
	return (NULL);
}
