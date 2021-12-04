#include "main.h"

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: Success 1 Always
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
