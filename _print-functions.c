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
	long int numN = (long)num;

	if (numN < 0)
	{
		negative = true;
		numN = -numN;
	}
	do {
		buffer[i] = numN % 10 + '0';
		numN /= 10;
		i++;
	} while (numN > 0);

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

/**
 * _intToBinary - prints a string to stdout
 * @num: pointer to the string to print
 * Return: Return number of printed characters
 */

char *_intToBinary(unsigned int num)
{
	char *binary;
	int i;

	binary = malloc(sizeof(char) * (sizeof(int) * 8 + 1));
	binary[sizeof(int) * 8] = '\0';
	i = sizeof(int) * 8 - 1;
	while (i >= 0)
	{
		binary[i--] = (num & 1) + '0';
		num >>= 1;
	}
	return (binary);
}
