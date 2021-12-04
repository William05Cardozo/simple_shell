#include "main.h"

/**
 * build_in_return - check return
 * @f: function pointer
 * @list: pointer list
 * @environment: environment variable
 * Return: Success void
 */

void built_in_return(char (*f)(list_t *r), list_t *list, char **environment)
{
	char *prmpt = "♪ ";

	if (f != NULL)
	{
		f(list);
	}

	else if (f == NULL)
	{
		if ((access(list->array[0], F_OK)) != -1)
		{
			mypath(list, environment);
			if (isatty(STDIN_FILENO))
				_puts(prmpt);
		}
		if (catpath(list, environment) == 0)
		{
			if (isatty(STDIN_FILENO))
			{
			_puts(list->buffer);
				_puts(": command not found\n");
			}
		}
	}

	if (isatty(STDIN_FILENO))
		_puts(prmpt);
}