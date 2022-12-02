#ifndef MAIN_H_
#define MAIN_H_

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

/**
 * struct builtIn_s - struct used to call builtIn funs
 * @fun: function name string
 * @f: void function pointer
 *
 * Description: calls builtIn funs
 */
typedef struct builtIn_s
{
	char *fun;
	void (*f)(char **envp, char **command, char **pathArr);
}builtIn_t;
/*
 * prototypes - function protos below
 */

/* defined in string_support.c */
char *_strcat(char *dest, char *src);
char *dupstr(char *fire);
char *_strcpy(char *dest, char *src);
int _strcmp(char *s1, char *s2);
int _strlen(char *s);
/* defined in tokenizer.c */
int tok_num(char *str, char *delims);
char **tokstr(char *line, char *delims);
int substrLen(char *str, char *delims);
/* defined in freedom.c */
void free_tokens(char **tokens);
void free_path(char **paths);
/* defined in help_fun.c */
char **get_input(char *input);
ssize_t yoinkline(char **line, FILE *inbound);
/* defined in moar_strstuff.c */
int _strncmp(char *s1, char *s2, int n);
/* defined in pathfinder.c */
char **path_locate(char *envvars[]);
char **path_tok(char *path);
void print_paths(char **pathArr);
char *check_paths(char **pathArr, char *command);
/* defined in error_elephant.c */
void errorHand(int eNum, char *arg, char *pName);
/* defined in built_in.c*/
void bIn_exit(char **envp, char **command, char **pathArr);
void bIn_env(char **envp, char **command, char **pathArr);
int runBuiltIn(char *envp[], char **command, char **pathArr);

#endif
