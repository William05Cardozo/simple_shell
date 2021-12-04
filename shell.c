#include "main.h"
/**
 * main - main function that contains the loop of program
 * @argc: number of arguments passed to function
 * @argv: array of arguments passed to function
 * @environment: variable to bring the environment path
 * Return: Success 0 Always
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
			check_match_return(f, &list, environment);
		}
	}
	if (isatty(STDIN_FILENO))
		_putchar('\n');

	_freeenv(environment);

	return (0);
}
