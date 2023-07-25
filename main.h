#ifndef _PRINTF_H
#define _PRINTF_H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

int _printf(const char *format, ...);
int _putchar(char c);
int _puts(char *str);

bool handleFormat(char *format, int *sum, int *i, va_list *args);
bool handleFormatPersion(char *format, int *sum, int *i);
bool handleFormatChar(va_list *args, int *sum, int *i);
bool handleFormatString(va_list *args, int *sum, int *i);

#endif
