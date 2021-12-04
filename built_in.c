#include "main.h"

/**
 * built - execute the match of input and built-in functions
 * @m: list type struct
 * Return: Success
 */

char (*built(list_t *m))(list_t *m)
{
	int i;

	built_t op[] = {
		{"exit", escape},
		{NULL, NULL}};

	for (i = 0; op[i].f != NULL; i++)
	{
		if (strcmp(op[i].string, m->array[0]) == 0)
		{
			break;
		}
	}
	return (op[i].f);
}

/**
 * escape - built-in function that kill the program
 * @list: struct list
 * Return: Success
 */

char escape(__attribute__((unused)) list_t *list)
{
	free(list->buffer);
	free(list->array);
	exit(98);
}
