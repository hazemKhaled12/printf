#include "main.h"

/**
 * handleFormat - Printf function
 *
 * @sum: sum
 * @i: iterator
 * @args: va_list
 * @format: format
 *
 * Return: Printed chars.
 */

void handleFormat(const char *format, int *sum, int *i, va_list *args)
{
	if (format[*i + 1] == '%')
	{
		handleFormatPersion(format, sum, i);
		return;
	}
	if (format[*i + 1] == 'c')
	{
		handleFormatChar(args, sum, i);
		return;
	}

	if (format[*i + 1] == 's')
	{
		handleFormatString(args, sum, i);
		return;
	}
}

/**
 * handleFormatPersion - Printf function
 *
 * @sum: sum
 * @i: iterator
 * @format: format
 *
 * Return: Printed chars.
 */

void handleFormatPersion(const char *format, int *sum, int *i)
{
	_putchar(format[*i + 1]);
	*sum = *sum+1;
	*i += 2;
}

/**
 * handleFormatChar - Printf function
 *
 * @sum: sum
 * @i: iterator
 * @args: va_list
 *
 * Return: Printed chars.
 */

void handleFormatChar(va_list *args, int *sum, int *i)
{
	int x = va_arg(*args, int);

	_putchar(x);
	++*sum;
	*i += 2;
}

/**
 * handleFormatString - Printf function
 *
 * @args: args
 * @sum: sum
 * @i: iterator
 *
 * Return: Printed chars.
 */

void handleFormatString(va_list *args, int *sum, int *i)
{
	char *x = va_arg(*args, char *);

	(*sum) += _puts(x);
	(*i) += 2;
}

