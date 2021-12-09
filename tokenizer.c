#include "main.h"

/**
 * tokenizer - Receive data and allocate memory.
 * @buffer: stores the command (s) received of the input.
 * @dlimiter: Character to cut the strings.
 *
 * Return: Success tokens.
 */

char **tokenizer(char *buffer, char *dlimiter)
{
	char **tokns = NULL;
	size_t i = 0;
	unsigned int mSize = 1;

	if (buffer == NULL)
	{
		return (NULL);
	}

	tokns = malloc(sizeof(char *) * mSize);

	if ((*buffer == '\n' || *buffer == ' ')   && *(buffer + 1) == '\0')
	{
		return (NULL);
	}

	while ((tokns[i] = _strtok(buffer, dlimiter)) != NULL)
	{
		i++;
		if (i > mSize)
		{
			tokns = realloc(tokns, sizeof(char *) * (i + 1));
			if (tokns == NULL)
				return (NULL);
		}
		buffer = NULL;
	}
	return (tokns);
}
