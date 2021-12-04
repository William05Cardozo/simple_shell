#include "main.h"

/**
 * checkpath - check if the access to environment is open
 * @vars: struct variable
 * @environment: environment variable
 * Return: Success void
 */

void checkpath(vars_t *vars, char **environment)
{
	pid_t child;
	int status;

	child = fork();
	switch (child)
	{
	case 0:
		execve(vars->array[0], vars->array, environment);
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
 * concatpath - joining and concatenating a final path environment
 * @vars: struct variable
 * @environment: environment variable
 * Return: Success 0 Always
 */

int concatpath(vars_t *vars, char **environment)
{
	int i, status;
	char **tokensEnv;
	char *concat1, *concat2, *duplicate;
	pid_t child;

	for (i = 0; environment[i]; i++)
	{
		if ((_strncmp(environment[i], "PATH", 4)) == 0)
			break;
	}

	duplicate = _strdup(environment[i]);
	tokensEnv = tokenizer(duplicate, ":=");

	i = 0;
	while (tokensEnv[i] != NULL)
	{
		concat1 = _strcat(tokensEnv[i], "/"); /*   /usr/bin/   */
		concat2 = _strcat(concat1, vars->array[0]); /*   /usr/bin/ls   */

		if (access(concat2, F_OK) == 0)
		{
			child = fork();
			switch (child)
			{
			case 0:
				execve(concat2, vars->array, environment);
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
