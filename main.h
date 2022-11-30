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
/* defined in moar_strstuff.c */
int _strncmp(char *s1, char *s2, int n);
/* defined in pathfinder.c */
char **path_locate(char *envvars[]);
char **path_tok(char *path);
void print_paths(char **pathArr);
char *check_paths(char **pathArr, char *command);

#endif
