#include "main.h"

/**
 * main - Entry point for ghost
 * @argc: arg count
 * @argv: array of input arg strings
 * @envp: array of inherited environment vars
 * Return: TBD
 */
int main(int argc, char *argv[], char *envp[])
{
	pid_t child_pid;
	int stat1, retVal;
	ssize_t eRet = 0;
	char *line = NULL, *moneySign, *thePath = NULL;
	char **command, **pathArr;
	char *pName = argv[0];

	moneySign = "$ ";
	pathArr = path_locate(envp);
	if (argc || argv[0] || moneySign)
	{
		/* placeholder */
	}
	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, moneySign, 2);
		eRet = yoinkline(&line, stdin);
		if (eRet == -1)
		{
			break;
		}
		command = get_input(line);
		free(line);
		retVal = runBuiltIn(envp, command, pathArr);
		if (retVal >= 0)
		{
			continue;
		}
		thePath = check_paths(pathArr, command[0]);
		if (!(thePath))
		{
			errorHand(101, command[0], pName);
			free_tokens(command);
			continue;
		}
		child_pid = fork();
		if (child_pid == 0)
			execve(thePath, command, envp);
		else
			waitpid(child_pid, &stat1, WUNTRACED);
		if (_strcmp(thePath, command[0]) != 0)
			free(thePath);
		free_tokens(command);
	}
	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "\n", 1);
	free_path(pathArr);
	return (0);
}
