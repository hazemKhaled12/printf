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

	if (format[*i + 1] == 'd')
	{
		return (handleFormatDecimal(args, sum, i));
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
	// Introduced  Switch to handle c, i and d
	char format_char = *(i + 1);

	switch (format_char)
	{
		case 'c';
		{
			int x = va_arg(*args, int);

			_putchar(x);
			*sum += 1;
			*i += 2;
			break;
		}

		case 'd':
		case 'i':
		{
			handleFormatInt(args, sum, i);
			break;
		}

		default:
		{
			return false;
		}
	}

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
	(*sum) += _puts(x);
	(*i) += 2;
	return (true);
}

/**
 * handleFormatInt - Printf function
 *
 * @args: args
 * @sum: sum
 * @i: iterator
 *
 * Return: Printed chars.
 */

bool handleFormatInt(va_list *args, int *sum, int *i)
{
	int num = va_arg(*args, int);
	int num_copy = num;
	int num_digits = 0;
	int divisor = 1;

	// Number of digits in number is counted
	while (num_copy != 0)
	{
		num_copy /= 10;
		num_digits++;
	}

	// Negative numbers are handled
	if (num < 0)
	{
		_putchar('-');
		num = -num;
		num_digits--;
		*sum += 1;
	}

	// Calculate the divisor to print each digit
	while (num_digits > 1)
	{
		divisor *= 10;
		num_digits--;
	}

	// Print each digit of the number
	while (divisor > 0)
	{
		int digit = num / divisor;
		_putchar(digit + '0');
		num %= divisor;
		divisor /= 10;
		*sum += 1'
	}

	*i += 2;
	return true;
}
