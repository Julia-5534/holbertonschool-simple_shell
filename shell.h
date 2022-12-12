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

/* global */
extern int hist;
extern int ret_val;
extern char *pName;
extern char **pathArr;
extern char **environ;

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
	int (*f)(char **param1);
} builtIn_t;

/**
 * struct alias_s - struct defining aliases.
 * @name: name of the alias.
 * @value: value of the alias.
 * @next: pointer to another struct alias_s.
 */
typedef struct alias_s
{
	char *name;
	char *value;
	struct alias_s *next;
} alias_t;

alias_t *aliases;

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
void free_env(void);
void free_alias_list(alias_t *head);

/* defined in help_fun.c */
char **get_input(char *input);
ssize_t yoinkline(char **line, FILE *inbound);
int num_len(int num);
char *_itoa(int num);
int forktime(char **command, char *thePath);

/* defined in moar_strstuff.c */
int _strncmp(char *s1, char *s2, int n);
unsigned int _strspn(char *s, char *accept);

/* defined in pathfinder.c */
char **path_locate(char *envvar);
char **path_tok(char *path);
char *check_paths(char *command);

/* defined in error_elephant.c */
void errorHand(int eNum, char *arg, char *pName);

/* defined in built_in.c */
int runBuiltIn(char **command);
int hey_exit(char **command);
int hey_env(char **command);

/* defined in main.c */

/* defined in env_setenv_unsetenv_getenv.c */
int hey_setenv(char **args, char **__attribute__((__unused__)), char __attribute__((__unused__)) **front);
int hey_unsetenv(char **command, char **pathArr, char **envp);
char **_getenv(char *var);

/* defined in alias_builtins.c */
int hey_alias(char **argArr, char __attribute__((__unused__)) **front);
void set_alias(char *var_name, char *value);
void print_alias(alias_t *alias);

/* defined in error_cases.c */
int create_error(char **argArr, int err);
char *error_env(char **argArr);
char *error_1(char **argArr);
char *error_exit(char **argArr);

/* defined in error_cases_2.c */
char *error_cd(char **argArr);
char *error_syn(char **argArr);
char *error_126(char **argArr);
char *error_127(char **argArr);

#endif
