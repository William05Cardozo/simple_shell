#include "main.h"

/**
 * check_match_return - check return
 * @f: function pointer
 * @vars: pointer vars
 * @environment: environment variable
 * Return: Success void
 */

void check_match_return(char (*f)(vars_t *r), vars_t *vars, char **environment)
{
	char *prompt = "($) ";

	if (f != NULL)
	{
		f(vars);
	}

	else if (f == NULL)
	{
		if ((access(vars->array[0], F_OK)) != -1)
		{
			checkpath(vars, environment);
			if (isatty(STDIN_FILENO))
				_puts(prompt);
		}
		if (concatpath(vars, environment) == 0)
		{
			if (isatty(STDIN_FILENO))
			{
				_puts(vars->buffer);
				_puts(": command not found\n");
			}
		}
	}

	if (isatty(STDIN_FILENO))
		_puts(prompt);
}
