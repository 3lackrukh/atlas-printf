#include <stdio.h>
#include <string.h>
#include "main.h"

// we will have to include our own header file and 
// inside we will need our table of format specifiers 
// and functions and prototypes

_printf(const char *format, ...)
{
	va_list santa_bag;
	int i, L1;
	int char_print = 0;
	int arg_cnt = 0;

	if (format == NULL)
	{
		return (-1);
	}
	L1 = strlen(format);
	va_start (santa_bag, format);

	while(i = 0; i < L1; i++) // iterate through string to print
	{
		if (format[i] != '%')
		{
			putchar(format[i];
			char_print++;
		}
		else // % is found
		{
			form_spec(format[i + 1]);//send next char
						 //to form_spec 
						 //to check if c,s,i,d
}
	
