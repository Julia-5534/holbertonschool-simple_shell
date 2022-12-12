#include "shell.h"

char *error_cd(char **argArr);
char *error_syn(char **argArr);
char *error_126(char **argArr);
char *error_127(char **argArr);

/**
 * error_cd - Creates error message for cd errors.
 * @argArr: An array of arguments passed to the command.
 * Return: The error string.
 */
char *error_cd(char **argArr)
{
	char *error, *hist_str;
	int len;

	hist_str = _itoa(hist);
	if (!hist_str)
		return (NULL);

	if (argArr[0][0] == '-')
		argArr[0][2] = '\0';
	len = _strlen(pName) + _strlen(hist_str) + _strlen(argArr[0]) + 24;
	error = malloc(sizeof(char) * (len + 1));
	if (!error)
	{
		free(hist_str);
		return (NULL);
	}

	_strcpy(error, pName);
	_strcat(error, ": ");
	_strcat(error, hist_str);
	if (argArr[0][0] == '-')
		_strcat(error, ": cd: Illegal option ");
	else
		_strcat(error, ": cd: can't cd to ");
	_strcat(error, argArr[0]);
	_strcat(error, "\n");

	free(hist_str);
	return (error);
}

/**
 * error_syn - Creates error message for syntax errors.
 * @argArr: An array of arguments passed to the command.
 * Return: The error string.
 */
char *error_syn(char **argArr)
{
	char *error, *hist_str;
	int len;

	hist_str = _itoa(hist);
	if (!hist_str)
		return (NULL);

	len = _strlen(pName) + _strlen(hist_str) + _strlen(argArr[0]) + 33;
	error = malloc(sizeof(char) * (len + 1));
	if (!error)
	{
		free(hist_str);
		return (NULL);
	}

	_strcpy(error, pName);
	_strcat(error, ": ");
	_strcat(error, hist_str);
	_strcat(error, ": Syntax error: \"");
	_strcat(error, argArr[0]);
	_strcat(error, "\" unexpected\n");

	free(hist_str);
	return (error);
}

/**
 * error_126 - Creates error message for permission denied failures.
 * @argArr: An array of arguments passed to the command.
 * Return: The error string.
 */
char *error_126(char **argArr)
{
	char *error, *hist_str;
	int len;

	hist_str = _itoa(hist);
	if (!hist_str)
		return (NULL);

	len = _strlen(pName) + _strlen(hist_str) + _strlen(argArr[0]) + 24;
	error = malloc(sizeof(char) * (len + 1));
	if (!error)
	{
		free(hist_str);
		return (NULL);
	}

	_strcpy(error, pName);
	_strcat(error, ": ");
	_strcat(error, hist_str);
	_strcat(error, ": ");
	_strcat(error, argArr[0]);
	_strcat(error, ": Permission denied\n");

	free(hist_str);
	return (error);
}

/**
 * error_127 - Creates error message for command not found failures.
 * @argArr: An array of arguments passed to the command.
 * Return: The error string.
 */
char *error_127(char **argArr)
{
	char *error, *hist_str;
	int len;

	hist_str = _itoa(hist);
	if (!hist_str)
		return (NULL);

	len = _strlen(pName) + _strlen(hist_str) + _strlen(argArr[0]) + 16;
	error = malloc(sizeof(char) * (len + 1));
	if (!error)
	{
		free(hist_str);
		return (NULL);
	}

	_strcpy(error, pName);
	_strcat(error, ": ");
	_strcat(error, hist_str);
	_strcat(error, ": ");
	_strcat(error, argArr[0]);
	_strcat(error, ": not found\n");

	free(hist_str);
	return (error);
}
