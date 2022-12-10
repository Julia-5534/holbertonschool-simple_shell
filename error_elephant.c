#include "shell.h"

void errorHand(int eNum, char *arg, char *pName);

/**
 * errorHand - handles errors
 * @eNum: error number
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

	eLen = (_strlen(pName) + _strlen(errMsg2) + _strlen(arg) + (_strlen(errMsg0) * 2) + _strlen(errMsg1) + 1);
	errComposite = malloc(sizeof(char) * eLen);
	_strcpy(errComposite, pName);
	_strcat(errComposite, errMsg0);
	_strcat(errComposite, errMsg1);
	_strcat(errComposite, errMsg0);
	_strcat(errComposite, arg);
	_strcat(errComposite, errMsg2);
	write(STDERR_FILENO, errComposite, eLen);
	free(errMsg1);
	free(errComposite);
}
