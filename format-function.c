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

bool handleFormat(const char *format, int *sum, int *i, va_list *args)
{
	if (format[*i + 1] == '%')
	{
		return (handleFormatPersion(format, sum, i));
	}
	if (format[*i + 1] == 'c')
	{
		return (handleFormatChar(args, sum, i));
	}
	if (format[*i + 1] == 's')
	{
		return (handleFormatString(args, sum, i));
	}
	if (format[*i + 1] == 'i' || format[*i + 1] == 'd')
	{
		return (handleFormatInteger(args, sum, i));
	}
	if (format[*i + 1] == 'b')
	{
		return (handleFormatIToB(args, sum, i));
	}
	return (false);
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

bool handleFormatPersion(const char *format, int *sum, int *i)
{
	_putchar(format[*i + 1]);
	*sum += 1;
	*i += 2;
	return (true);
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

bool handleFormatChar(va_list *args, int *sum, int *i)
{
	int x = va_arg(*args, int);

	_putchar(x);
	*sum += 1;
	*i += 2;
	return (true);
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

bool handleFormatString(va_list *args, int *sum, int *i)
{
	char *x = va_arg(*args, char *);

	if (x == NULL)
	{
		(*sum) += _puts("(null)");
		(*i) += 2;
		return (true);
	}

	(*sum) += _puts(x);
	(*i) += 2;
	return (true);
}

/**
 * handleFormatInteger - Printf function
 *
 * @sum: sum
 * @i: iterator
 * @args: va_list
 *
 * Return: Printed chars.
 */

bool handleFormatInteger(va_list *args, int *sum, int *i)
{
	int x = va_arg(*args, int);

	*sum += _printInt(x);
	*i += 2;
	return (true);
}
