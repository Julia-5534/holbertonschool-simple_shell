#include "shell.h"

int _strncmp(char *s1, char *s2, int n);
unsigned int _strspn(char *s, char *accept);

/**
 * _strncmp - compares strings up to n chars
 * @s1: first string
 * @s2: second string
 * @n: num of chars to compare
 * Return: first dif or 0 if none
 */
int _strncmp(char *s1, char *s2, int n)
{
	int i = 0, dif = 0;

	while (s1[i] && s2[i] && (i < n))
	{
		if (s1[i] == s2[i])
		{
			i++;
			continue;
		}
		else
		{
			dif = s1[i] - s2[i];
			break;
		}
	}
	return (dif);
}

/**
 * _strspn - calculates byte overlap
 * @s: input string
 * @accept: string w/ bytes to be accepted
 * Return: num of target byte matches
 */
unsigned int _strspn(char *s, char *accept)
{
	unsigned int bCount = 0;
	int i = 0, j = 0;

	while (accept[i])
	{
		j = 0;
		while ((s[j] >= 'a' && s[j] <= 'z') || (s[j] >= 'A' && s[j] <= 'Z'))
		{
			if (s[j] == accept[i])
			{
				bCount++;
			}
			j++;
		}
		i++;
	}
	return (bCount);
}

/**
 * cleanstr - removes newline chars from user input
 * @line: user input line
 * Return: always 0
 */
int cleanstr(char *line)
{
	int i = 0;

	while (line[i])
	{
		if (line[i] == '\n')
		{
			line[i] = '\0';
		}
		i++;
	}
	return (0);
}
