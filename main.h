#ifndef MAIN_H
#define MAIN_H

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
*struct list - Stores input parameters
*@buffer: saves the first input parameters
*@array: contains the commands after of execute tokenizer function
*/

typedef struct list
{
char *buffer;
char **array;
} list_t;

/**
* struct built - stores the built-in functions
*@string: string that compares whether the function exists or not.
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
int catpath(list_t *list, char **environment);
void built_in_return(char (*f)(list_t *r), list_t *list, char **environment);
char (*built(list_t *m))(list_t *m);
char escape(list_t *list);
int _strcmp(char *s1, char *s2);
/*char _env(list_t *list);*/
void _freeEnv(char **environment);

#endif
