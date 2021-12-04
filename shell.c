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
	vars_t vars = {NULL};
	char *prompt = "($) ";
	char *delimiter = " \n";
	size_t lineSize = 0;
	char (*f)(vars_t *);

	_puts(prompt);
	while ((getline(&vars.buffer, &lineSize, stdin)) != -1)
	{
		vars.array = tokenizer(vars.buffer, delimiter);
		if (vars.array == NULL)
		{
			if (isatty(STDIN_FILENO))
				_puts(prompt);
			continue;
		}
		else
		{
			f = match(&vars);
			check_match_return(f, &vars, environment);
		}
	}
	if (isatty(STDIN_FILENO))
		_putchar('\n');

	_freeenv(environment);

	return (0);
}
