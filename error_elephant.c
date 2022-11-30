#include "main.h"

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
	char *errMsg1 = ": No such file or directory\n";

	if (arg)
	{
		/* placeholder */
	}
	if (eNum == 101)
	{
		eLen = (_strlen(pName) + _strlen(errMsg1) + 1);
		errComposite = malloc(sizeof(char) * eLen);
		_strcpy(errComposite, pName);
		_strcat(errComposite, errMsg1);
		write(STDERR_FILENO, errComposite, eLen);
		free(errComposite);
	}
}
