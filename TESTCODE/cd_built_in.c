#include "shell.h"

/**
 * hey_cd - Changes the current directory of the shellby process.
 * @argArr: An array of arguments.
 * @front: A double pointer to the beginning of args.
 *
 * Return: If the given string is not a directory - 2.
 *         If an error occurs - -1.
 *         Otherwise - 0.
 */
/*
int hey_cd(char **argArr, char **__attribute__((__unused__)), **front)
{
	char **dir_info, *new_line = "\n";
	char *oldpwd = NULL, *pwd = NULL;
	struct stat dir;

	oldpwd = getcwd(oldpwd, 0);
	if (!oldpwd)
		return (-1);

	if (argArr[0])
	{
		if (*(argArr[0]) == '-' || _strcmp(argArr[0], "--") == 0)
		{
			if ((argArr[0][1] == '-' && argArr[0][2] == '\0') ||
					argArr[0][1] == '\0')
			{
				if (_getenv("OLDPWD") != NULL)
					(chdir(*_getenv("OLDPWD") + 7));
			}
			else
			{
				free(oldpwd);
				return (create_error(argArr, 2));
			}
		}
		else
		{
			if (stat(argArr[0], &dir) == 0 && S_ISDIR(dir.st_mode)
					&& ((dir.st_mode & S_IXUSR) != 0))
				chdir(argArr[0]);
			else
			{
				free(oldpwd);
				return (create_error(argArr, 2));
			}
		}
	}
	else
	{
		if (_getenv("HOME") != NULL)
			chdir(*(_getenv("HOME")) + 5);
	}

	pwd = getcwd(pwd, 0);
	if (!pwd)
		return (-1);

	dir_info = malloc(sizeof(char *) * 2);
	if (!dir_info)
		return (-1);

	dir_info[0] = "OLDPWD";
	dir_info[1] = oldpwd;
	if (hey_setenv(dir_info, dir_info, dir_info) == -1)
		return (-1);

	dir_info[0] = "PWD";
	dir_info[1] = pwd;
	if (hey_setenv(dir_info, dir_info, dir_info) == -1)
		return (-1);
	if (argArr[0] && argArr[0][0] == '-' && argArr[0][1] != '-')
	{
		write(STDOUT_FILENO, pwd, _strlen(pwd));
		write(STDOUT_FILENO, new_line, 1);
	}
	free(oldpwd);
	free(pwd);
	free(dir_info);
	return (0);
}
*/