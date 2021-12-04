#include "main.h"

/**
 * mypath - check if the access to environment is open
 * @list: struct list
 * @environment: environment variable
 * Return: Success void
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
		break;
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
 * @list: struct list
 * @environment: environment variable
 * Return: Success 0 Always
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
		concat1 = _strcat(tokenEnv[i], "/"); /*   /usr/bin/   */
		concat2 = _strcat(concat1, list->array[0]); /*   /usr/bin/ls   */

		if (access(concat2, F_OK) == 0)
		{
			child = fork();
			switch (child)
			{
			case 0:
				execve(concat2, list->array, environment);
				break;
			case -1:
				perror("Error to create a child proccess");
				break;
			default:
				wait(&status);
				break;
			}
			return (1);
		}
		i++;
	}
	return (0);
}
