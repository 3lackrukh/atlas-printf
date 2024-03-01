#include <stdio.h>
#include <string.h>
#include "main.h"

// we will have to include our own header file and 
// inside we will need our table of format specifiers 
// and function]s and prototypes

_printf(const char *format, ...)
{
	va_list santa_bag;
	va_start(santa_bag, format);

	int i, k;
	int char_print = 0;
	int arg_print = 0;

	typedef struct box
	{
		char specifier;
		int (*function)(va_list);
	} box;

	box specifier_calls[] = {
		{'c', op_char},
		{'s', op_str},
		{'d', op_d},
		{'i', op_int},
		{NULL, NULL},
	};

	if (format == NULL)
	{
		return (-1);
	}

	for(i = 0; format[i] != '\0'; i++) // iterate through string to print
	{
		if (format[i] != '%')
		{
			putchar(format[i]);
			char_print++;
		}
		else // % is found
		{
			i ++;
			for(k = 0; specifier_calls[k].specifier != NULL; k++)
			{
				if (format[i] == specifier_calls[k].specifier)
				{
					arg_print += (specifier_calls[k].function(santa_bag);
				}
			}
		}
	{
	va_end(santa_bag);
	return(char_print + arg_print);
}
	
