#include "main.h"

/**
 * _freeEnv - Function that free the environment variable.
 * @environment: Function to bring the path of the environment.
 *
 * Return: Succes void.
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
