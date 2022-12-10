#include "shell.h"

void errorHand(int eNum, char *arg, char *pName);

/**
 * errorHand - handles errors
 * @eNum: error number
 * @arg: error arg
 * @pName: program name
 * Return: void, prints error to SE
 */
void errorHand(int eNum, char *arg, char *pName)
{
	unsigned int eLen = 0;
	char *errComposite;
	char *errMsg0 = ": 1: ";
	char *errMsg2 = ": not found\n";

	if (eNum == 101)
	{
		eLen = (_strlen(pName) + _strlen(errMsg2) + _strlen(arg) + strlen(errMsg0) + 1);
		errComposite = malloc(sizeof(char) * eLen);
		_strcpy(errComposite, pName);
		_strcat(errComposite, errMsg0);
		_strcat(errComposite, arg);
		_strcat(errComposite, errMsg2);
		write(STDERR_FILENO, errComposite, eLen);
		free(errComposite);
	}
}
