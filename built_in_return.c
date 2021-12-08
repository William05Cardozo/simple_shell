#include "main.h"

/**
 * built_in_return - Function that validates parameters
 * @f: function pointer
 * @list: pointer list
 * @environment: environment variable
 * Return: No line
 */

void built_in_return(char (*f)(list_t *r), list_t *list, char **environment)
{
	if (f != NULL)
	{
		f(list);
	}
	else if (f == NULL)
	{
		if ((access(list->array[0], F_OK)) != -1)
		{
			mypath(list, environment);

		}

		else if (catpath(list, environment) == 0)
		{
			if (isatty(STDIN_FILENO))
			{
				_puts(list->buffer);
				_puts(": command not found\n");
			}
		}
	}
}
