#include "shell.h"

char **path_locate(char *envvars[]);
char **path_tok(char *path);
void print_paths(char **pathArr);
char *check_paths(char *command);

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
 * Return: the goods
 * LET ME KNOW IF THIS IS ALL JACKED UP
 */
void print_paths(char **pathArr)
{
	struct stat s;
	char *string, **path;
	int i = 0;

	if (!pathArr)
		return;
	if (stat(pathArr[0], &s) == 0)
		return;
	string = enviro("PATH="); /*enviro.c*/
	path = tokstr(string, ":");
	free(string);
	string = NULL;
	while (path[i])
	{
		string = malloc(_strlen(path[i]) + _strlen(pathArr[0]) + 2);
		string = _strcpy(string, path[i]);
		string = _strcat(string, "/");
		string = _strcat(string, pathArr[0]);
	if (stat(string, &s) == 0)
	{
		free(pathArr[0]);
		pathArr[0] = strdup(string);
	for (i = 0; path[i] != NULL; i++)
	free(path[i]);
	free(path);
	free(string);
	return;
	}
	i++;
	free(string);
	string = NULL;
	}
	for (i = 0; path[i] != NULL; i++)
		free(path[i]);
	free(path);
}

/**
 * check_paths - checks pathArr against command[0]
 * @pathArr: array of paths
 * @command: first tok of command array
 * Return: num of valid path located or NULL if none
 */
char *check_paths(char *command)
{
	unsigned int i = 0, pathLen = 0;
	struct stat s;
	char *cmpPath = NULL;

	if (command[0] == '/')
	{
		if (stat(command, &s) == 0)
		{
			return (command);
		}
		else
		{
			return (NULL);
		}
	}
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
	return (NULL);
}
