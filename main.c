#include "shell.h"

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
	char *line = NULL, *thePath = NULL, **command = NULL;
<<<<<<< HEAD
=======
	size_t llen;
	char **pathArr;
	int ret_val, hist = 0;
>>>>>>> 429403bd45c820adffb176a1cfae3de1d564dc99

	signal(SIGINT, sig_stop);
	pName = argv[0];
	if (argc != 1)
		exit(EXIT_FAILURE);
	pathArr = path_locate("PATH");
	while (1)
	{
		hist++;
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "$ ", 2);
<<<<<<< HEAD
		if (yoinkline(&line, stdin) == -1)
=======
		if (getline(&line, &llen, stdin) < 0)
		{
			free(line);
			free_path(pathArr);
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			exit(ret_val);
		}
		cleanstr(line);
		if (tok_num(line, " ") <= 0)
		{
>>>>>>> parent of 41480a0... betty style fixes
			continue;
		command = get_input(line);
		retVal = runBuiltIn(command);
		if (retVal >= 0)
		{
			free_tokens(command);
			continue;
		}
		thePath = check_paths(command[0]);
		if (access(thePath, X_OK) != 0)
		{
			if (access((thePath), F_OK) == 0)
			{
				ret_val = 126;
			}
			else
			{
				ret_val = 127;
			}
			errorHand(hist, command[0], pName);
			free_tokens(command);
			continue;
		}
		ret_val = forktime(command, thePath);
	}
	return (0);
}
