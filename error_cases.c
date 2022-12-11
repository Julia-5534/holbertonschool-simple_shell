#include "shell.h"

int create_error(char **argArr, int err);
char *error_env(char **argArr);
char *error_1(char **argArr);
char *error_exit(char **argArr);

/**
 * create_error - Writes error messages to stderr.
 * @argArr: array of arguments.
 * @err: error value.
 * Return: error value.
 */
int create_error(char **argArr, int err)
{
	char *error;

	switch (err)
	{
	case -1:
		error = error_env(argArr);
		break;
	case 1:
		error = error_1(argArr);
		break;
	case 2:
		if (*(argArr[0]) == 'e')
			error = error_exit(++argArr);
		else if (argArr[0][0] == ';' || argArr[0][0] == '&' || argArr[0][0] == '|')
			error = error_syn(argArr);
		else
			error = error_cd(argArr);
		break;
	case 126:
		error = error_126(argArr);
		break;
	case 127:
		error = error_127(argArr);
		break;
	}
	write(STDERR_FILENO, error, _strlen(error));

	if (error)
		free(error);
	return (err);
}

/**
 * error_env - Creates error message for env errors.
 * @argArr: An array of arguments passed to the command.
 * Return: The error string.
 */
char *error_env(char **argArr)
{
	char *error, *hist_str;
	int len;

	hist_str = _itoa(hist);
	if (!hist_str)
		return (NULL);

	argArr--;
	len = _strlen(pName) + _strlen(hist_str) + _strlen(argArr[0]) + 45;
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
	_strcat(error, ": Unable to add/remove from environment\n");

	free(hist_str);
	return (error);
}

/**
 * error_1 - Creates error message alias errors.
 * @argArr: An array of arguments passed to the command.
 * Return: The error string.
 */
char *error_1(char **argArr)
{
	char *error;
	int len;

	len = _strlen(pName) + _strlen(argArr[0]) + 13;
	error = malloc(sizeof(char) * (len + 1));
	if (!error)
		return (NULL);

	_strcpy(error, "alias: ");
	_strcat(error, argArr[0]);
	_strcat(error, " not found\n");

	return (error);
}

/**
 * error_exit - Creates error message for exit errors.
 * @argArr: An array of arguments passed to the command.
 * Return: The error string.
 */
char *error_exit(char **argArr)
{
	char *error, *hist_str;
	int len;

	hist_str = _itoa(hist);
	if (!hist_str)
		return (NULL);

	len = _strlen(pName) + _strlen(hist_str) + _strlen(argArr[0]) + 27;
	error = malloc(sizeof(char) * (len + 1));
	if (!error)
	{
		free(hist_str);
		return (NULL);
	}

	_strcpy(error, pName);
	_strcat(error, ": ");
	_strcat(error, hist_str);
	_strcat(error, ": exit: Illegal number: ");
	_strcat(error, argArr[0]);
	_strcat(error, "\n");

	free(hist_str);
	return (error);
}
