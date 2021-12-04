#include "main.h"

/**
 * _strtok - cut the strings according to the delimiter
 * @buffer: storage the commands received of the input
 * @dlimiter: the character for cut the strings
 * Return: Success str
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
			ref = set;
		}
	}
	return (str);
}
