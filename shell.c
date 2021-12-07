#include "main.h"

/**
 * main - Main function that contains the loop of program.
 * @argc: Number of arguments.
 * @argv: Array of arguments.
 * @environment: Environment path.
 *
 * Return: Success 0 Always.
 */
int main(__attribute__((unused)) int argc,
	 __attribute__((unused)) char **argv, char **environment)
{
	list_t list = {NULL};
	char *prmpt = "♪ ";
	char *dlimiter = " \n";
	size_t dashSize = 0;
	char (*f)(list_t *);

	_puts(prmpt);
	while ((getline(&list.buffer, &dashSize, stdin)) != -1)
	{
		list.array = tokenizer(list.buffer, dlimiter);
		if (list.array == NULL)
		{
			if (isatty(STDIN_FILENO))
				_puts(prmpt);
			continue;
		}
		else
		{
			f = built(&list);
			built_in_return(f, &list, environment);
		}
	}
	if (isatty(STDIN_FILENO))
		_putchar('\n');

	_freeEnv(environment);

	return (0);
}
