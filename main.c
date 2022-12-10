#include "shell.h"

char **pathArr;

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
	char *line = NULL, *thePath = NULL, **command;
	char *pName = argv[0];

	pathArr = path_locate(envp);
	if (argc || argv[0])
	{
		/* placeholder */
	}
	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "$ ", 2);
		eRet = yoinkline(&line, stdin);
		if (eRet == -2)
		{
			break;
		}
		if (eRet == -1)
		{
			continue;
		}
		command = get_input(line);
		free(line);
		if (command[0][0] == '\n')
		{
			free_tokens(command);
			continue;
		}
		retVal = runBuiltIn(command, envp);
		if (retVal >= 0)
		{
			free_tokens(command);
			continue;
		}
		thePath = check_paths(command[0]);
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
