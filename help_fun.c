#include "shell.h"

char **get_input(char *input);
ssize_t yoinkline(char **line, FILE *inbound);
int num_len(int num);
char *_itoa(int num);

/**
 * get_input - takens input and tokenizes
 * @input: input to be tokd
 * Return: pointer to token array
 */
char **get_input(char *input)
{
	int i;
	char **command;
	char *separator = " ";

	for (i = 0; separator[i]; i++)
		command = tokstr(input, &separator[i]);
	return (command);
}

/**
 * yoinkline - our version of getline
 * @line: the line to be yoinked
 * @inbound: the inbound file to be yoinked
 * Return: inbound
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
		return (-1);
	}
	inCount = 0;
	buff = malloc(sizeof(char) * 151);
	while (c != '\n')
	{
		readRet = read(STDIN_FILENO, &c, 1);
		if (readRet == EOF || (readRet == 0 && inCount == 0))
		{
			free(buff);
			return (-2);
		}
		else if (readRet == 0 && inCount > 0)
		{
			break;
		}
		buff[inCount] = c;
		inCount++;
	}
	if (inCount > 1)
		buff[inCount - 1] = '\0';
	else if (inCount == 1)
	{
		free(buff);
		inCount = 0;
		return (-1);
	}
	*line = buff;
	if (readRet != 0)
	{
		inCount = 0;
	}
	return (inCount);
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
