#ifndef _MAIN_SHELL_H
#define _MAIN_SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <limits.h>
#include <signal.h>
#include <fcntl.h>

/**
 * struct list - this struct contains ths storage of input data
 *@buffer: storage at first time the command received
 *@array: contains the commands after of execute tokenizer function
 */

typedef struct list
{
	char *buffer;
	char **array;
} list_t;

/**
 * struct built - contains the match of the input and the built-in functions
 *@string: string for compare with the built-in / env functions
 *@f: pointer to functions
 */

typedef struct built
{
	char *string;
	char (*f)(list_t *);
} built_t;

int _strlen(char *str);
int _puts(char *str);
int _putchar(char c);
char *_strcat(char *str1, char *str2);
char *_strdup(char *str);
int _strncmp(char *str, char *str2, int num);

char **tokenizer(char *buffer, char *delimiter);
char *_strtok(char *buffer, const char *delimiter);

void mypath(list_t *list, char **environment);
int concatpath(list_t *list, char **environment);
void check_match_return(char (*f)(list_t *r), list_t *list, char **environment);

char (*built(list_t *m))(list_t *m);
char esc(list_t *list);
void _freeenv(char **environment);

#endif
