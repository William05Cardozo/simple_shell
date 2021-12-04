#include "main.h"

/**
 * match - execute the match of input and built-in functions
 * @m: list type struct
 * Return: Success
 */

char (*built(list_t *m))(list_t *m)
{
	int i;

	built_t op[] = {
		{"exit", esc},
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
 * esc - built-in function that kill the program
 * @list: struct list
 * Return: Success
 */

char esc(__attribute__((unused)) list_t *list)
{
	free(list->buffer);
	free(list->array);
	exit(98);
}