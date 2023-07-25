#include "main.h"

/**
 * _printf - Printf function
 *
 * @format: format
 *
 * Return: Printed chars.
 */

int _printf(const char *format, ...)
{
	int sum = 0;
	int i = 0;
	va_list args;

	va_start(args, format);

	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	while (format[i] != '\0')
	{
		if (format[i] != '%')
		{
			_putchar(format[i]);
			sum++;
			i++;
			continue;
		}
		handleFormat(format, &sum, &i, &args);
	}
	va_end(args);

	return (sum);
}
