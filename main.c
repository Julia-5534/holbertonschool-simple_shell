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
	int retVal;
	char *line = NULL, *thePath = NULL, **command;
	size_t llen;

	pName = argv[0];
	if (argc != 1)
		exit(EXIT_FAILURE);
	pathArr = path_locate("PATH");
	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "$ ", 2);
		if (getline(&line, &llen, stdin) < 0)
		{
			free(line);
			free_path(pathArr);
			exit(EXIT_SUCCESS);
		}
		if (_strlen(line) == 1)
		{
			continue;
		}
		cleanstr(line);
		hist++;
		command = get_input(line);
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
	return (ret_val);
}
