#include "shell.h"

char **get_input(char *input);
ssize_t yoinkline(char **line, FILE *inbound);
int num_len(int num);
char *_itoa(int num);
int forktime(char **command, char *thePath);

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
 * yoinkline - our version of getline
 * @line: the line to be yoinked
 * @inbound: the inbound file to be yoinked
 * Return: 0 on success -1 if only newline
*/
ssize_t yoinkline(char **line, FILE *inbound)
{
	static ssize_t inCount;
	char *buff;
	char c = 'a';
	int readRet;

	if (inCount == 0)
	{
		fflush(inbound);
	}
	else
	{
		free_path(pathArr);
		perror(pName);
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "\n", 1);
		exit(EXIT_FAILURE);
	}
	inCount = 0;
	buff = malloc(sizeof(char) * 151);
	while (c != '\n')
	{
		readRet = read(STDIN_FILENO, &c, 1);
		if ((readRet == 0 && inCount == 0) || readRet == -1)
		{
			free(buff);
			free_path(pathArr);
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			exit(ret_val);
		}
		if (readRet == 0 && inCount > 0)
		{
			inCount++;
			break;
		}
		buff[inCount] = c;
		inCount++;
	}
	if (readRet != 0)
		buff[inCount - 1] = '\0';
	else
		buff[inCount] = '\0';
	inCount = 0;
	if (!buff[0])
	{
		free(buff);
		return (-1);
	}
	*line = buff;
	return (0);
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
