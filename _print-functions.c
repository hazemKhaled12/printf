#include "main.h"

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _puts - prints a string to stdout
 * @str: pointer to the string to print
 * Return: Return number of printed characters
 */

int _puts(char *str)
{
	int i;
	int numberOfTypedCharacter = 0;

	for (i = 0; str[i] != '\0'; i++)
	{
		_putchar(str[i]);
		numberOfTypedCharacter++;
	}
	return (numberOfTypedCharacter);
}
