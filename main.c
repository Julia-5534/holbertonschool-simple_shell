#include "main.h"

/**
 * main - Entry point for ghost
 * @argc: arg count
 * @argv: array of input arg strings
 * @envp: array of inherited environment vars
 * Return: TBD
 */
int main(int argc, char *argv[], char *envp[])
{
    pid_t child_pid;
	int stat1, i = 0;
    ssize_t eRet = 0;
	char *line = NULL, *moneySign;
    char **command;
	size_t n = 0;
    char *thePath = NULL, **pathArr;

    moneySign = "$ ";
    pathArr = path_locate(envp);
    if (argc || argv[0] || thePath)
    {
        /* placeholder */
    }
	while (1)
    {
        write(STDOUT_FILENO, moneySign, 2);
        eRet = getline(&line, &n, stdin);
        if (eRet == -1)
        {
            free_tokens(command);
            free(command);
            free(thePath);
            break;
        }
        command = get_input(line);
        free(line);
        thePath = check_paths(pathArr, command[0]);
        if (_strcmp("exit", command[0]) == 0)
        {
            break;
        }
        if (_strcmp("env", command[0]) == 0)
        {
            for (i = 0; envp[i]; i++)
            {
                printf("%s\n", envp[i]);
            }
        }
        if (!(thePath))
        {
            printf("./hsh: %s not found\n", command[0]);
            continue;
        }
        child_pid = fork();
        if (child_pid == 0)
        {
            execve(thePath, command, envp);
        }
        else
        {
            waitpid(child_pid, &stat1, WUNTRACED);
        }
        free_tokens(command);
        free(command);
        free(thePath);
	}
    free_path(pathArr);
    write(STDOUT_FILENO, "\n", 1);
    return (0);
}
