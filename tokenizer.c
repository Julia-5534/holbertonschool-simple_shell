#include "main.h"

/**
 * tok_num - calcs num of toks in str
 * @str: string to tokenize
 * @delims: delims to tokenize based on
 * Return: num of tokens in overall str
 */
int tok_num(char *str, char *delims)
{
	int tokTotal = 0, i, lineLen = 0;

	lineLen = _strlen(str);
	for (i = 0; i < lineLen; i++)
	{
		if (str[i] != *delims)
		{
			tokTotal++;
			i += substrLen(str + i, delims);
		}
	}
	return (tokTotal);
}

/**
 * substrLen - computes length of substr / token
 * @str: string in question
 * @delims: delims to tok based on
 * Return: length of substr
 */
int substrLen(char *str, char *delims)
{
	int i = 0, tokLen = 0;

	while (str[i] && str[i] != *delims)
	{
		i++;
		tokLen++;
	}
	return (tokLen);
}

/**
 * tokstr - tokenizes str into substrs
 * @line: str to tokenize
 * @delims: delim to tokenize based on
 * Return: token array
 */
char **tokstr(char *line, char *delims)
{
	char **tokenStorage;
	int i, j = 0, k, tokTotal, ssLen = 0;

	tokTotal = tok_num(line, delims);
	tokenStorage = malloc(sizeof(char *) * (tokTotal + 1));
	for (i = 0; i < tokTotal; i++)
	{
		while (line[j] == *delims)
			j++;
		ssLen = substrLen(line + j, delims);
		tokenStorage[i] = malloc(sizeof(char) * (ssLen + 1));
		for (k = 0; k < ssLen; k++, j++)
			tokenStorage[i][k] = line[j];
		tokenStorage[i][k] = '\0';
	}
	tokenStorage[i] = NULL;
	return (tokenStorage);
}