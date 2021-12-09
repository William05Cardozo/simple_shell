#include "main.h"

/**
 * _strtok - function used to separate strings
 * @buffer: Receives input parameters
 * @dlimiter: Variable that holds the limiter
 * Return: str
 */

char *_strtok(char *buffer, const char *dlimiter)
{
	static char *ref;
	char *str = NULL;
	char *set = NULL;

	buffer = buffer ? buffer : ref;

	if (*buffer != '\0')
	{
		set = buffer;

		if (!*set)
		{
			ref = '\0';
		}
		else
		{
			str = set;
			while ((*set != *dlimiter && *set != *(dlimiter + 1)) && *set != '\0')
			{
				set++;
			}
			if (*set != '\0')
			{
				*set = '\0';
				set++;
			}
			while (*set == ' ' && *(set + 1) != '\0')
			{
				set++;
			}
			ref = set;
			if (*str == '\0')
				return (NULL);
			return (str);
		}
	}
	str = NULL;
	return (str);
}
