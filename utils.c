#include "main.h"
#include <stdlib.h>

/**
 * reverse_str - reverses a string
 *
 * @str: string to reverse
 *
 * Return: reversed string
 */
char *reverse_str(char *str)
{
	int i;
	int len = 0;
	char c;

	if (!str)
		return (NULL);
	while (str[len] != '\0')
	{
		len++;
	}
	for (i = 0; i < (len / 2); i++)
	{
		c = str[i];
		str[i] = str[len - i - 1];
		str[len - i - 1] = c;
	}
	return (str);
}

/**
 * int_to_array - converts an integer to an array of characters
 *
 * @i: integer to convert
 * @final_array: array to store integer string in
 * @base: base of i
 *
 * Return: string representation of i
 */
const char *int_to_array(int i, char *final_array, int base)
{
	char *str = final_array;
	int digit, sign = 0;

	if (i < 0)
	{
		sign = 1;
		i *= -1;
	}
	while (i)
	{
		digit = i % base;
		*str = (digit > 9) ? ('A' + digit - 10) : '0' + digit;
		i = i / base;
		str++;
	}
	if (sign)
	{
		*str++ = '-';
	}
	*str = '\0';
	reverse_str(final_array);
	return (final_array);
}
