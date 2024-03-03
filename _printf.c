#include "main.h"

/**
 * _printf- prints a string to standard output
 * handling the insertion of chars, strings, and
 * integers into the string at positions designated
 * with a '%' followed by a designated format operator.
 *
 * @format: the string to be printed containing 0 or more
 * format specifiers.
 *
 * @...: a list containing additional arguments handed in
 * to be formatted and printed after each specifier.
 *
 * Return: the number of chars printed.
 */

int _printf(const char *format, ...)
{
	int i, k, total;
	int char_print = 0;
	int arg_print = 0;
	va_list santa_bag;
	box specifier_calls[] = {
		{'c', op_char},
		{'s', op_str},
		{'d', op_d},
		{'i', op_int},
		{'\0', NULL},
	};

	va_start(santa_bag, format);
	if (format == NULL)
	{
		return (-1);
	}

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			putchar(format[i]);
			char_print++;
		}
		else
		{
			i++;
			if (format[i] == '%')
			{
				putchar('%');
			}
			for (k = 0; specifier_calls[k].specifier != '\0'; k++)
			{
				if (format[i] == specifier_calls[k].specifier)
				{
					arg_print += (specifier_calls[k].function(santa_bag));
				}
			}
		}
	}
	va_end(santa_bag);
	total = (char_print + arg_print);
	return (total);
}
