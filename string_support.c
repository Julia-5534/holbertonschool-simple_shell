#include "main.h"

/**
 * dupstr - This function duplicates a string (char *fire)
 * and stores it in a newly allocated block of memory. It
 * then returns a pointer to that new memory block.
 *
 * The name is wildly appropriate when you think about it.
 *
 * @fire: pointer to string to duplicate
 *
 * Return: pointer to duplicated string hextek location
 *
 */
char *dupstr(char *fire)
{
	unsigned int i = 0;
	char *dumpster;

	/* mitigate bad magic */
	if (!(fire))
	{
		return (NULL);
	}

	/* gets strlen */
	while (fire[i])
	{
		i++;
	}

	/* find a good location in memory and check */
	dumpster = malloc(sizeof(char) * (i + 1));
	if (!(dumpster))
	{
		return (NULL);
	}

	/* copy the string contents */
	for (i = 0; fire[i]; i++)
	{
		dumpster[i] = fire[i];
	}
	dumpster[i] = '\0';

	/* return new string loca */
	return (dumpster);
}

/**
 * *_strcat - meows 2 strings together
 * @dest: where big string goes and other smol string comes
 * @src: smol string input
 * Return: big string
 */
char *_strcat(char *dest, char *src)
{
	int i = 0, j = 0;

	while (dest[i])
	{
		i++;
	}
	while (src[j])
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}

/**
 * *_strcpy - function for to copy chararr
 * @src: source of chararr
 * @dest: destination of chararr
 * Return: finaldestination
 */
char *_strcpy(char *dest, char *src)
{
	int a = 0;

	while (*(src + a))
	{
		*(dest + a) = *(src + a);
		a++;
	}
	dest[a] = '\0';
	return (dest);
}

/**
 * _strcmp - compares strings ASCII values
 * @s1: first string
 * @s2: second string
 * Return: first dif
 */
int _strcmp(char *s1, char *s2)
{
	int i = 0, dif = 0;

	while (s1[i] && s2[i])
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
 * _strlen - function to find length of string
 * @s: string input
 * Return: string length
 */
int _strlen(char *s)
{
	int a = 0;

	while (*(s + a) != '\0')
	{
		a++;
	}
	return (a);
}
