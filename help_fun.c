#include "main.h"

/**
 * get_input - takens input and tokenizes
 * @input: input to be tokd
 * Return: pointer to token array
 */
char **get_input(char *input)
{
    char **command;
    char *separator = " ";

    command = tokstr(input, separator);
    return (command);
}
