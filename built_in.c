#include "shell.h"

int runBuiltIn(char**command, char **envp);
int hey_exit(char **command, char **envp);
int hey_env(char **command, char **envp);

/**
 * get_builtin - Matches a command with a corresponding
 *               builtin function.
 * @command: The command to match.
 * Return: A function pointer to the corresponding builtin.
 */
int runBuiltIn(char **command, char **envp)
{
	builtIn_t betty[] = {
		{ "exit", hey_exit },
		{ "env", hey_env },
		{ NULL, NULL }
	};
	int i;
	for (i = 0; betty[i].fun; i++)
	{
		if (_strcmp(betty[i].fun, command[0]) == 0 && _strlen(command[0]) == _strlen(betty[i].fun))
		{
			betty[i].f(command, envp);
			return (i);
		}
	}
	return (-1);
}

/**
 * hey_exit - Causes normal process termination
 *                for the shell.
 * @argArr: An array of arguments containing the exit value.
 * @front: A double pointer to the beginning of args.
 *
 * Return: If there are no arguments - -3.
 *         If the given exit value is invalid - 2.
 *         O/w - exits with the given status value.
 *
 * Description: Upon returning -3, the program exits back in the main function.
 */
int hey_exit(char **command, char **envp)
{
	/* int i, len_of_int = 10;
	unsigned int num = 0, max = 1 << (sizeof(int) * 8 - 1);

	if (argArr[0])
	{
		if (argArr[0][0] == '+')
		{
			i = 1;
			len_of_int++;
		}
		for (; argArr[0][i]; i++)
		{
			if (i <= len_of_int && argArr[0][i] >= '0' && argArr[0][i] <= '9')
				num = (num * 10) + (argArr[0][i] - '0');
			else
				return (create_error(--argArr, 2));
		}
	}
	else
	{
		return (-3);
	}
	if (num > max - 1)
		return (create_error(--argArr, 2));
	argArr -= 1;
	free_argArr(argArr, front);
	free_env();
	free_alias_list(aliases);
	exit(num);
	*/
	if (envp)
		/*place holder*/
	free_tokens(command);
	free_path(pathArr);
	exit(EXIT_SUCCESS);
}

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

/**
 * hey_env - Prints the current environment.
 * @argArr: An array of arguments passed to the shell.
 * @front: A double pointer to the beginning of argArr.
 * Return: If an error occurs - -1.
 *	   Otherwise - 0.
 *
 * Description: Prints one variable per line in the
 *              format 'variable'='value'.
 */
int hey_env(char **command, char **envp)
{
	int i;

	if (command)
	/* placeholder */
	for (i = 0; envp[i]; i++)
	{
		write(STDOUT_FILENO, envp[i], _strlen(envp[i]));
		write(STDOUT_FILENO, "\n", 1);
	}
	return (0);
}
