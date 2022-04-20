#include "main.h"
#include <stdarg.h>
#include <stdio.h>
#include <string.h>

/**
 * _printf - printf implementation
 *
 * @format: the format string
 *
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	int i = 0, j = 0;
	char buff[100] = {0}, tmp[20];
	char *str_arg;

	va_start(args, format);
	while (format && format[i])
	{
		if (format[i] == '%')
		{
			i++;
			switch (format[i])
			{
			case 'c':
			{
				buff[j] = (char)va_arg(args, int);
				j++;
				break;
			}
			case 's':
			{
				str_arg = va_arg(args, char *);
				strcpy(&buff[j], str_arg);
				j += strlen(str_arg);
				break;
			}
			}
		}
		else
		{
			buff[j] = format[i];
			j++;
		}
		i++;
	}
	fwrite(buff, j, 1, stdout);
	va_end(args);
	return (j);
}
