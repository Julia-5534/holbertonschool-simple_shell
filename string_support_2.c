
#include "shell.h"

/**
 * _strspn - prototype for function
 * @s: the null fuction
 * @accept: the null terminated string
 * Return: len - return length
 */

unsigned int _strspn(char *s, char *accept)
{
	unsigned int len = 0;

	if ((*s == '\0') || (*accept == '\0'))
		return (len);

	while (*s && tokstr(accept, *s++))
	{
		len++;
	}
	return (len);
}
