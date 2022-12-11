#include "shell.h"

char **pathArr;
int hist = 0;
char *pName;

/**
 * main - Entry point for ghost
 * @argc: arg count
 * @argv: array of input arg strings
 * @envp: array of inherited environment vars
 * Return: TBD
 */
int main(int argc, char *argv[])
{
	int retVal, fRet = 0, eRet = 0;
	char *line = NULL, *thePath = NULL, **command;

	pName = argv[0];
	if (argc != 1)
		exit(EXIT_FAILURE);
	pathArr = path_locate("PATH");
	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "$ ", 2);
		eRet = yoinkline(&line, stdin);
		hist++;
		if (eRet == -2)
			break;
		if (eRet == -1)
			continue;
		command = get_input(line);
		free(line);
		retVal = runBuiltIn(command);
		if (retVal >= 0)
		{
			free_tokens(command);
			continue;
		}
		thePath = check_paths(command[0]);
		if (!(thePath) || access((thePath), X_OK) != 0)
		{
			perror(pName);
			free_tokens(command);
			continue;
		}
		fRet = forktime(command, thePath);
	}
	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "\n", 1);
	free_path(pathArr);
	return (fRet);
}

int forktime(char **command, char *thePath)
{
	pid_t child_pid;
	int stat1, eRet = 0;

	switch(child_pid = fork())
	{
		case 0:
		{
			execve(thePath, command, environ);
			perror(pName);
			exit(EXIT_FAILURE);
		}
		case -1:
		{
			perror(pName);
			exit(EXIT_FAILURE);
		}
		default:
		waitpid(child_pid, &stat1, WUNTRACED);
	}
	if (_strcmp(thePath, command[0]) != 0)
		free(thePath);
	free_tokens(command);
	return (eRet);
}
