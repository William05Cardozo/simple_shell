#include "main.h"

/**
 * tokenizer - manage the data received of the input and assign memory
 * @buffer: storage the commands received of the input
 * @delimiter: the character for cut the strings
 * Return: Success tokens
 */

char **tokenizer(char *buffer, char *delimiter)
{
	char **tokens = NULL;
	size_t i = 0;
	unsigned int mcount = 1;

	if (buffer == NULL)
	{
		return (NULL);
	}

	tokens = malloc(sizeof(char *) * mcount);

	if ((*buffer == '\n' || *buffer == ' ') && *(buffer + 1) == '\0')
	{
		return (NULL);
	}

	while ((tokens[i] = _strtok(buffer, delimiter)) != NULL)
	{
		i++;
		if (i > mcount)
		{
			tokens = realloc(tokens, sizeof(char *) * (i + 1));
			if (tokens == NULL)
				return (NULL);
		}
		buffer = NULL;
	}
	return (tokens);
}
