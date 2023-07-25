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
	bool ran;

	va_start(args, format);

	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	while (format[i] != '\0')
	{
		if (format[i] != '%')
		{
			sum += _putchar(format[i]);
			i++;
			continue;
		}
		ran = handleFormat(format, &sum, &i, &args);

		if (ran)
			continue;
		sum += _putchar(format[i + 1]);
		i += 2;
		continue;
	}
	va_end(args);
	return (sum);
}
