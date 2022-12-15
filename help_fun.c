#include "shell.h"

char **get_input(char *input);
char *_itoa(int num);
int forktime(char **command, char *thePath);
int cleanstr(char *line);
int num_len(int num);

/**
 * get_input - supplies approp. delims for command array
 * @input: user input to be tokenized
 * Return: array of strings cont. command and args
 */
char **get_input(char *input)
{
	char **command;
	char *separator = " \t";

	command = tokstr(input, separator);
	return (command);
}

/**
 * _itoa - Converts an integer to a string.
 * @num: The integer.
 * Return: The converted string.
 */
char *_itoa(int num)
{
	char *buffer;
	int len = num_len(num);
	unsigned int num1;

	buffer = malloc(sizeof(char) * (len + 1));
	if (!buffer)
		return (NULL);

	buffer[len] = '\0';

	if (num < 0)
	{
		num1 = num * -1;
		buffer[0] = '-';
	}
	else
	{
		num1 = num;
	}

	len--;
	do {
		buffer[len] = (num1 % 10) + '0';
		num1 /= 10;
		len--;
	} while (num1 > 0);

	return (buffer);
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
	int stat1, exRet;

	switch (child_pid = fork())
	{
		case 0:
		{
			exRet = execve(thePath, command, environ);
			if (exRet == -1)
			{
				perror(pName);
				if (_strcmp(thePath, command[0]) != 0)
					free(thePath);
				free_tokens(command);
				free_path(pathArr);
				exit(EXIT_FAILURE);
			}
			break;
		}
		case -1:
		{
			perror(pName);
			exit(EXIT_FAILURE);
		}
		default:
		{
			waitpid(child_pid, &stat1, WUNTRACED);
			if (WIFEXITED(stat1))
			{
				exRet = WEXITSTATUS(stat1);
			}
		}
	}
	if (_strcmp(thePath, command[0]) != 0)
		free(thePath);
	free_tokens(command);
	return (exRet);
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

/**
 * num_len - Counts the digit length of a number.
 * @num: The number to measure.
 * Return: The digit length.
 */
int num_len(int num)
{
	unsigned int num1;
	int len = 1;

	if (num < 0)
	{
		len++;
		num1 = num * -1;
	}
	else
	{
		num1 = num;
	}
	while (num1 > 9)
	{
		len++;
		num1 /= 10;
	}

	return (len);
}
