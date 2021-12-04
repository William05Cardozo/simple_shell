#include "main.h"

/**
 * _strlen - return the count of characters
 * @str: The string to know characters count
 * Return: Success i
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
