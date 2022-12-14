#include "shell.h"

void errorHand(int eNum, char *arg, char *pName);

/**
 * errorHand - handles errors
 * @lNum: historic line num
 * @arg: error arg
 * @pName: program name
 * Return: void, prints error to SE
 */
void errorHand(int lNum, char *arg, char *pName)
{
	unsigned int eLen = 0;
	char *errComposite;
	char *errMsg0 = ": ";
	char *errMsg1 = _itoa(lNum);
	char *errMsg2 = ": not found\n";
	char *errMsg3 = ": Permission denied\n";

	if (ret_val == 127)
		eLen = (_strlen(pName) + _strlen(errMsg2) + _strlen(arg)
		+ (_strlen(errMsg0) * 2) + _strlen(errMsg1));
	else if (ret_val == 126)
		eLen = (_strlen(pName) + _strlen(errMsg3) + _strlen(arg)
		+ (_strlen(errMsg0) * 2) + _strlen(errMsg1));
	errComposite = malloc(sizeof(char) * eLen + 1);
	_strcpy(errComposite, pName);
	_strcat(errComposite, errMsg0);
	_strcat(errComposite, errMsg1);
	_strcat(errComposite, errMsg0);
	_strcat(errComposite, arg);
	if (ret_val == 127)
		_strcat(errComposite, errMsg2);
	else if (ret_val == 126)
		_strcat(errComposite, errMsg3);
	write(STDERR_FILENO, errComposite, eLen);
	free(errMsg1);
	free(errComposite);
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
