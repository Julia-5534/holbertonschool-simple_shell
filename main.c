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
	int retVal, tokenNum, i = 0;
	char *line = NULL, *thePath = NULL, **command = NULL, *token = NULL, *holdstr = NULL;

	pName = argv[0];
	if (argc != 1)
		exit(EXIT_FAILURE);
	pathArr = path_locate("PATH");
	while (1)
	{
		hist++;
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "$ ", 2);
		if (yoinkline(&line, stdin) == -1)
			continue;
		/*
		command = get_input(line);
		*/
		tokenNum = tok_num(line, " ");
		command = malloc(sizeof(char *) * (tokenNum + 1));
		holdstr = dupstr(line);
		free(line);
		token = strtok(holdstr, " \t");
		while (token)
		{
			command[i] = dupstr(token);
			i++;
			token = strtok(NULL, " ");
		}
		command[i] = NULL;
		i = 0;
		free(holdstr);
		retVal = runBuiltIn(command);
		if (retVal >= 0)
		{
			free_tokens(command);
			continue;
		}
		thePath = check_paths(command[0]);
		if (!(thePath) || access((thePath), X_OK) != 0)
		{
			ret_val = 127;
			errorHand(hist, command[0], pName);
			free_tokens(command);
			continue;
		}
		ret_val = forktime(command, thePath);
	}
	return (0);
}
