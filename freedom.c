#include "shell.h"

void free_tokens(char **tokens);
void free_path(char **paths);
void free_env(void);
void free_argArr(char **argArr, char **front);
void free_alias_list(alias_t *head);

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
 * free_argArr - Frees up memory taken by args.
 * @argArr: A null-terminated double pointer containing commands/arguments.
 * @front: A double pointer to the beginning of args.
 */
void free_argArr(char **argArr, char **front)
{
	size_t i;

	for (i = 0; argArr[i] || argArr[i + 1]; i++)
		free(argArr[i]);

	free(front);
}

/**
 * free_alias_list - Frees a alias_t linked list.
 * @head: The head of the alias_t list.
 */
void free_alias_list(alias_t *head)
{
	alias_t *next;

	while (head)
	{
		next = head->next;
		free(head->name);
		free(head->value);
		free(head);
		head = next;
	}
}
