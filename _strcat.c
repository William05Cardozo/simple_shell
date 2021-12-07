#include "main.h"

/**
 * _strcat - Function to concatenate two strings.
 * @str1: First string to concatenate.
 * @str2: Second string to concatenate.
 *
 * Return: Success cat
 */

char *_strcat(char *str1, char *str2)
{
	int i = 0;
	int j = 0;
	char = *cat;

	cat = malloc(sizeof(char) * ((_strlen(str1)) + (_strlen(str2))) + 1);

	if (cat == NULL)
	{
		return (NULL);
	}

	while (str1[i] != '\0')
	{
		cat[i] = str1[i];
		i++;
	}

	while (str2[j] != '\0')
	{
		cat[i] = str2[j];
		i++;
		j++;
	}

	cat[i] = '\0';

	return (cat);
}
