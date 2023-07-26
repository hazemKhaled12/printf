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

/**
 * _printInt - prints a string to stdout
 * @num: pointer to the string to print
 * Return: Return number of printed characters
 */

int _printInt(int num)
{
	char buffer[20];
	int count = 0;
	bool negative = false;
	int i = 0;
	int j;

	if (num < 0)
	{
		negative = true;
		num = -num;
	}
	do {
		buffer[i] = num % 10 + '0';
		num /= 10;
		i++;
	} while (num > 0);

	if (negative)
	{
		buffer[i] = '-';
		i++;
	}

	for (j = i - 1; j >= 0; j--)
	{
		write(1, &buffer[j], 1);
		count++;
	}

	return (count);
}
