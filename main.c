#include "shell.h"

char **pathArr;
int ret_val = 0;
int hist = 0;
char *pName;

/**
 * main - Entry point for ghost
 * @argc: arg count
 * @argv: array of input arg strings
 * Return: TBD
 */
int main(int argc, char *argv[])
{
	char *line = NULL, *thePath = NULL, **command = NULL;
	size_t llen;

	signal(SIGINT, sig_stop);
	pName = argv[0];
	if (argc != 1)
		exit(EXIT_FAILURE);
	while (1)
	{
		hist++;
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "$ ", 2);
		if (getline(&line, &llen, stdin) < 0)
			free_exit(line);
		cleanstr(line);
		if (tok_num(line, " ") <= 0)
		{
			continue;
		}
		command = get_input(line);
		if (runBuiltIn(command, line) >= 0)
			continue;
		thePath = check_paths(command[0]);
		if (access(thePath, X_OK) != 0)
		{
			if (access((thePath), F_OK) == 0)
				ret_val = 126;
			else
				ret_val = 127;
			errorHand(hist, command[0], pName);
			free_tokens(command);
			continue;
		}
		ret_val = forktime(command, thePath);
	}
	return (0);
}
