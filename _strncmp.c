#include "main.h"

/**
 * _strncmp - compare the string and the length
 * @str1: first string to compare
 * @str2: second string to compare
 * @num: lenght of string to compare
 * Return: Success
 */

int _strncmp(char *str1, char *str2, int num)
{
	int i = 0;

	/* compare the lenght of strings */
	while (str1[i] == str2[i] && i < num)
	{
		if (i + 1 == num)
		{
			break;
		}
		i++;
	}

	/* compare the data */
	if (str1[i] == str2[i])
	{
		return (0);
	}

	return (-1);
}
