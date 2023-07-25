#ifndef _MAIN_H
#define _MAIN_H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>

int _printf(const char *format, ...);
int _putchar(char c);
int _puts(char *str);

void handleFormat(const char *format, int *sum, int *i, va_list *args);
void handleFormatPersion(const char *format, int *sum, int *i);
void handleFormatChar(va_list *args, int *sum, int *i);
void handleFormatString(va_list *args, int *sum, int *i);

#endif
