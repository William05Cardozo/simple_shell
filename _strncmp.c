#include "main.h"

/**
 * _strncmp - compare two string with length
 * @str1: string to compare
 * @str2: string to compare
 * @num: comparative string rank
 * Return: Result
 */

int _strncmp(char *str1, char *str2, int num)
{
	int i = 0;

	while (str1[i] == str2[i] && i < num)
	{
		if (i + 1 == num)
		{
			break;
		}
		i++;
	}
	if (str1[i] == str2[i])
	{
		return (0);
	}
	return (-1);
}
