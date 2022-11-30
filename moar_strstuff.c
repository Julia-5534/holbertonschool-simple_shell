#include "main.h"

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
