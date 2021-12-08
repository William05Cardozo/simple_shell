#include "main.h"

/**
 * mypath - My function
 * @list: Linked list
 * @environment: environment variable
 * Return: No line
 */

void mypath(list_t *list, char **environment)
{
	pid_t child;
	int status;

	child = fork();
	switch (child)
	{
		case 0:
			execve(list->array[0], list->array, environment);
			exit(98);
		case -1:
			perror("Error to create a child proccess");
			break;
		default:
			wait(&status);
			break;
	}
}

/**
 * catpath - joining and concatenating a final path environment
 * @list: Linked list
 * @environment: environment variable
 * Return: 0
 */

int catpath(list_t *list, char **environment)
{
	int i, status;
	char **tokenEnv;
	char *concat1, *concat2, *duplicate;

	pid_t child;

	for (i = 0; environment[i]; i++)
	{
		if ((_strncmp(environment[i], "PATH", 4)) == 0)
			break;
	}

	duplicate = _strdup(environment[i]);
	tokenEnv = tokenizer(duplicate, ":=");

	i = 0;
	while (tokenEnv[i] != NULL)
	{
		concat1 = _strcat(tokenEnv[i], "/");
		concat2 = _strcat(concat1, list->array[0]);

		if (access(concat2, F_OK) == 0)
		{
			child = fork();
			switch (child)
			{
				case 0:
					execve(concat2, list->array, environment);
					exit(98);
				case -1:
					perror("Error to create a child proccess");
					break;
				default:
					wait(&status);
					break;
			} return (1);
		} i++;
	} return (0);
}
