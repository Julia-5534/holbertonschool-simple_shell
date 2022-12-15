#include "shell.h"

void free_tokens(char **tokens);
void free_path(char **paths);
void free_env(void);
void sig_stop(int sNum);

/**
 * free_tokens - frees mem assoc w indv strs in strarr
 * @tokens: array of str tokens
 * Return: void
 */
void free_tokens(char **tokens)
{
	unsigned int i = 0;

	for (; tokens[i] != NULL; i++)
	{
		free(tokens[i]);
	}
	free(tokens);
}

/**
 * free_path - frees mem assoc w indv strs in strarr
 * @paths: array of path toks
 * Return: void
 */
void free_path(char **paths)
{
	unsigned int i = 0;

	if (!paths)
		return;
	if (!(*paths))
		return;
	paths[0] -= 5;
	for (; paths[i] != NULL; i++)
	{
		free(paths[i]);
	}
	free(paths);
}

/**
 * free_env - Frees the env
 */
void free_env(void)
{
	int index;

	for (index = 0; environ[index]; index++)
		free(environ[index]);
	free(environ);
}

/**
 * free_exit - frees vars in prep for exit
 * @line: input line
 * Return: void
 */
void free_exit(char *line)
{
	free(line);
	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "\n", 1);
	exit(ret_val);
}

/**
 * sig_stop - stops signal
 * @sNum: signal number
 * Return: void
 */
void sig_stop(int sNum)
{
	char *sigMsg = "\nWhat is dead may never die...";

	(void)sNum;
	write(STDOUT_FILENO, sigMsg, _strlen(sigMsg));
	write(STDOUT_FILENO, "\n$ ", 3);
}
