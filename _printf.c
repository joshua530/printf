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
	char buff[100] = {0};

	va_start(args, format);
	handle_formatting(&args, format, buff, &i, &j);
	fwrite(buff, j, 1, stdout);
	va_end(args);
	return (j);
}

/**
 * handle_formatting - handles formatting of printf placeholders
 *
 * @args: variable length arguments
 * @format: format string
 * @buff: buffer for storing formatted items
 * @i: counter
 * @j: counter
 *
 * Return: void
 */
void handle_formatting(
	va_list *args,
	const char *format, char *buff, int *i, int *j)
{

	char tmp[20], *str_arg;

	while (format && format[*i])
	{
		if (format[*i] == '%')
		{
			i++;
			switch (format[*i])
			{
			case 'c':
			{
				buff[*j] = (char)va_arg(*args, int);
				j++;
				break;
			}
			case 's':
			{
				str_arg = va_arg(*args, char *);
				strcpy(&buff[*j], str_arg);
				j += strlen(str_arg);
				break;
			}
			case 'd':
			case 'i':
			{
				int_to_array(va_arg(*args, int), tmp, 10);
				strcpy(&buff[*j], tmp);
				j += strlen(tmp);
				break;
			}
			}
		}
		else
		{
			buff[*j] = format[*i];
			*j++;
		}
		*i++;
	}
}
