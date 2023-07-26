#include "main.h"

/**
 * handleFormatIToB - Printf function
 *
 * @sum: sum
 * @i: iterator
 * @args: va_list
 *
 * Return: Printed chars.
 */

bool handleFormatIToB(va_list *args, int *sum, int *i)
{
	unsigned int x = va_arg(*args, unsigned int);
	char *binaryAsString = _intToBinary(x);
	(*sum) += _puts(binaryAsString);
	*i += 2;
	return (true);
}
