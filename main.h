#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <stdlib.h>

int _printf(const char *format, ...);
int op_char(va_list santa_bag);
int op_str(va_list santa_bag);
int op_int(va_list santa_bag);
int op_d(va_list santa_bag);

/**
 * struct box- a custom data type containing
 * a char to be used as a format specifier,
 * and a pointer to a funcion.
 *
 * @specifier: easily checked for finding the function to call.
 *
 * @function: a pointer to the function corresponding to the
 * format specifier.
 */
typedef struct box
	{
	char specifier;
	int (*function)(va_list);
	} box;
#endif
