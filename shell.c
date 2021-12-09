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
	unsigned int pipeline = 0;
	char *prmpt = "$ ";
	char *dlimiter = " \n";
	size_t dashSize = 0;
	char (*f)(list_t *);

	if (!isatty(STDIN_FILENO))
		pipeline = 1;
	if (pipeline == 0)
		_puts(prmpt);

	while ((getline(&list.buffer, &dashSize, stdin)) != -1)
	{
		while (*list.buffer == ' ')
			list.buffer++;
		list.array = tokenizer(list.buffer, dlimiter);
		if (list.array == NULL)
		{
			continue;
		}
		else
		{
			f = built(&list);
			built_in_return(f, &list, environment);
		}
		if (pipeline == 0)
			_puts(prmpt);
	}
	if (pipeline == 0)
		_puts("\n");
	return (0);
}
