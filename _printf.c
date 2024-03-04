#include "main.h"
/**
 * _printf- prints a string to standard output
 * handling the insertion of chars, strings, and
 * integers into the string at positions designated
 * with a '%' followed by a designated format operator.
 * @format: the string to be printed containing 0 or more
 * format specifiers.
 * @...: a list containing additional arguments handed in
 * to be formatted and printed after each specifier.
 * Return: the number of chars printed.
 */
int _printf(const char *format, ...)
{
	int i, k, match, total;
	va_list santa_bag;
	box specifier_calls[] = {
		{'c', op_char},
		{'s', op_str},
		{'d', op_d},
		{'i', op_int},
		{'\0', NULL},
	};

	va_start(santa_bag, format);
	if (format == NULL) return (-1);

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			putchar(format[i]);
			total++;
		}
		else
		{
			i++;
			if (format[i] == '%')
			{
				putchar('%');
				total++;
			}
			for (k = 0; specifier_calls[k].specifier != '\0'; k++)
			{
				if (format[i] == specifier_calls[k].specifier)
				{
					total += (specifier_calls[k].function(santa_bag));
					match = 1;
					break;
				}
			}
			if (!match && format[i] != ' ' && format[i] != '\0' && format[i] != '%')
			{
				putchar('%');
				putchar(format[i]);
				total += 2;
			}
			match = 0;
		}
	}
	va_end(santa_bag);
	return (total);
}
