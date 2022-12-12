/**
 * print_paths - shows the tokenized paths
 * @pathArr: array of path strs
 * Return: the goods
 * LET ME KNOW IF THIS IS ALL JACKED UP
 */
void print_paths(char **pathArr)
{
	struct stat s;
	char *string, **path;
	int i = 0;

	if (!pathArr)
		return;
	if (stat(pathArr[0], &s) == 0)
		return;
	string = enviro("PATH="); /*enviro.c*/
	path = tokstr(string, ":");
	free(string);
	string = NULL;
	while (path[i])
	{
		string = malloc(_strlen(path[i]) + _strlen(pathArr[0]) + 2);
		string = _strcpy(string, path[i]);
		string = _strcat(string, "/");
		string = _strcat(string, pathArr[0]);
	if (stat(string, &s) == 0)
	{
		free(pathArr[0]);
		pathArr[0] = strdup(string);
	for (i = 0; path[i] != NULL; i++)
	free(path[i]);
	free(path);
	free(string);
	return;
	}
	i++;
	free(string);
	string = NULL;
	}
	for (i = 0; path[i] != NULL; i++)
		free(path[i]);
	free(path);
}
