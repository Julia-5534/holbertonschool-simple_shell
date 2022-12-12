#include "shell.h"

char **pathArr;
int ret_val = 0;
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
	int retVal, eRet = 0;
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
		forktime(command, thePath);
	}
	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "\n", 1);
	free_path(pathArr);
	return (ret_val);
}

/**
 * forktime - function to fork and exec command(s)
 * @command: string array containing command and args
 * @thePath: sanitized path ready to spawn bbs
 * Return: always zero (0) success
 */
int forktime(char **command, char *thePath)
{
	pid_t child_pid;
	int stat1;

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
	return (0);
}
