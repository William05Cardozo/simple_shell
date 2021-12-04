#include "main.h"

/**
 * _puts - writes the string in the output
 * @str: The string to print
 * Return: Success 0 Always
 */

int _puts(char *str)
{
	int num = 0;

	num = _strlen(str);
	write(STDOUT_FILENO, str, num);

	return (0);
}
