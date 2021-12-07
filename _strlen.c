#include "main.h"

/**
 * _strlen - function that prints the length of the strings
 * @str: contains the string
 * Return: i
 */

int _strlen(char *str)
{
	int i;

	if (str == NULL)
	{
		return (0);
	}
	for (i = 0; str[i] != '\0'; i++)
		;
	return (i);
}
