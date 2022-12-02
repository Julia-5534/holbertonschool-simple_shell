#include "main.h"

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
	free (tokens);
}

/**
 * free_path - frees mem assoc w indv strs in strarr
 * @paths: array of path toks
 * Return: void
 */
void free_path(char **paths)
{
	unsigned int i = 0;

	paths[0] -= 5;
	for (; paths[i] != NULL; i++)
	{
		free(paths[i]);
	}
	free(paths);
}
