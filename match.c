#include "main.h"

/**
 * match - execute the match of input and built-in functions
 * @m: var type struct
 * Return: Success
 */

char (*match(vars_t *m))(vars_t *m)
{
	int i;

	match_t op[] = {
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
 * @vars: struct var
 * Return: Success
 */

char esc(__attribute__((unused)) vars_t *vars)
{
	free(vars->buffer);
	free(vars->array);
	exit(98);
}
