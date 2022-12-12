#include "shell.h"

int hey_alias(char **argArr, char __attribute__((__unused__)) **front);
void set_alias(char *var_name, char *value);
void print_alias(alias_t *alias);

/**
 * hey_alias - Builtin command that either prints all aliases, specific
 * aliases, or sets an alias.
 * @argArr: An array of arguments.
 * @front: A double pointer to the beginning of args.
 * Return: If an error occurs - -1.
 *         Otherwise - 0.
 */
int hey_alias(char **argArr, char __attribute__((__unused__)) **front)
{
	alias_t *temp = aliases;
	int i, ret = 0;
	char **value;

	if (!argArr[0])
	{
		while (temp)
		{
			print_alias(temp);
			temp = temp->next;
		}
		return (ret);
	}
	for (i = 0; argArr[i]; i++)
	{
		temp = aliases;
		value = tokstr(argArr[i], "=");
		if (!value)
		{
			while (temp)
			{
				if (_strcmp(argArr[i], temp->name) == 0)
				{
					print_alias(temp);
					break;
				}
				temp = temp->next;
			}
			if (!temp)
				ret = create_error(argArr + i, 1);
		}
		else
			set_alias(argArr[i], *value);
	}
	return (ret);
}

/**
 * set_alias - Will either set an existing alias 'name' with a new value,
 * 'value' or creates a new alias with 'name' and 'value'.
 * @var_name: Name of the alias.
 * @value: Value of the alias. First character is a '='.
 */
void set_alias(char *var_name, char *value)
{
	alias_t *temp = aliases;
	int len, j, k;
	char *new_value;

	*value = '\0';
	value++;
	len = _strlen(value) - _strspn(value, "'\"");
	new_value = malloc(sizeof(char) * (len + 1));
	if (!new_value)
		return;
	for (j = 0, k = 0; value[j]; j++)
	{
		if (value[j] != '\'' && value[j] != '"')
			new_value[k++] = value[j];
	}
	new_value[k] = '\0';
	while (temp)
	{
		if (_strcmp(var_name, temp->name) == 0)
		{
			free(temp->value);
			temp->value = new_value;
			break;
		}
		temp = temp->next;
	}
	if (!temp)
	{
		/* placeholder */
	}
}

/**
 * print_alias - Prints the alias in the format name='value'.
 * @alias: Pointer to an alias.
 */
void print_alias(alias_t *alias)
{
	char *alias_string;
	int len = _strlen(alias->name) + _strlen(alias->value) + 4;

	alias_string = malloc(sizeof(char) * (len + 1));
	if (!alias_string)
		return;
	_strcpy(alias_string, alias->name);
	_strcat(alias_string, "='");
	_strcat(alias_string, alias->value);
	_strcat(alias_string, "'\n");

	write(STDOUT_FILENO, alias_string, len);
	free(alias_string);
}
/**
 * replace_aliases - Goes through the arguments and replace any matching alias
 * with their value.
 * @argArr: 2D pointer to the arguments.
 * Return: 2D pointer to the arguments.
 */
char **replace_aliases(char **argArr)
{
	alias_t *temp;
	int i;
	char *new_value;

	if (_strcmp(argArr[0], "alias") == 0)
		return (argArr);
	for (i = 0; argArr[i]; i++)
	{
		temp = aliases;
		while (temp)
		{
			if (_strcmp(argArr[i], temp->name) == 0)
			{
				new_value = malloc(sizeof(char) * (_strlen(temp->value) + 1));
				if (!new_value)
				{
					free_argArr(argArr, argArr);
					return (NULL);
				}
				_strcpy(new_value, temp->value);
				free(argArr[i]);
				argArr[i] = new_value;
				i--;
				break;
			}
			temp = temp->next;
		}
	}

	return (argArr);
}
