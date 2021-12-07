#include "main.h"

/**
 * built -Look for the built in function to execute
 * @m: List type struct
 * Return: Result
 */

char (*built(list_t *m))(list_t *m)
{
	int i;

	built_t op[] = {
		{"exit", escape},
		/*{"env", _env},*/
		{NULL, NULL}
	};

	for (i = 0; op[i].f != NULL; i++)
	{
		if (_strcmp(op[i].string, m->array[0]) == 0)
		{
			break;
		}
	}
	return (op[i].f);
}

/**
 * escape - Function that ends the programme
 * @list: Linked list
 * Return: Result
 */

char escape(__attribute__((unused)) list_t *list)
{
	free(list->buffer);
	free(list->array);
	exit(98);
}


/**
 * _env - function
 * @list: Linked list
 * i: iterator
 * Return: No line
 

char _env(__attribute__((unused)) list_t *list)
{
	unsigned int i;

	for (i = 0; list->env[i]; i++)
	{
		_puts(list->env[i]);
		_puts("\n");
	}
	return (0);
} */
