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
	free(list->array);
	exit(98);
}
