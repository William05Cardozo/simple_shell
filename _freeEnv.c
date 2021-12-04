#include "main.h"

/**
 * _freeEnv - function that free the environment variable
 * @environment: variable to bring the environment path
 * Return: Success void
 */
void _freeEnv(char **environment)
{
	int i;

	for (i = 0; environment[i]; i++)
	{
		free(environment[i]);
	}

	if (environment == NULL)
	{
		free(environment);
	}
}
