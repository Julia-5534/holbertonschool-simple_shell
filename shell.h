#ifndef SHELL_H_
#define SHELL_H_

/*
 * libraries - to be included
 */
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>
#include <signal.h>

/* global */
extern int hist;
extern int ret_val;
extern char *pName;
extern char **pathArr;
extern char **environ;

/**
 * struct builtIn_s - struct used to call builtIn funs
 * @fun: function name string
 * @f: int function pointer
 *
 * Description: calls builtIn funs
 */
typedef struct builtIn_s
{
	char *fun;
	int (*f)(char **param1);
} builtIn_t;

/*
 * prototypes - function protos below
 */

/* defined in string_support.c */
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
int _strlen(char *s);
int _strncmp(char *s1, char *s2, int n);
int _strcmp(char *s1, char *s2);

/* defined in tokenizer.c */
int tok_num(char *str, char *delims);
char **tokstr(char *line, char *delims);
int substrLen(char *str, char *delims);

/* defined in freedom.c */
void free_tokens(char **tokens);
void free_path(char **paths);
void free_env(void);
void free_exit(char *line);
void sig_stop(int sNum);

/* defined in help_fun.c */
char **get_input(char *input);
char *_itoa(int num);
int forktime(char **command, char *thePath);
int cleanstr(char *line);
int num_len(int num);

/* defined in pathfinder.c */
char **path_locate(char *envvar);
char **path_tok(char *path);
char *check_paths(char *command);

/* defined in error_elephant.c */
void errorHand(int eNum, char *arg, char *pName);

/* defined in built_in.c */
int runBuiltIn(char **command, char *line);
int hey_exit(char **command);
int hey_env(char **command);

/* defined in main.c */
int main(int argc, char *argv[]);

#endif
