#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <string.h>
#include <stdarg.h>

int _printf(const char *format, ...);
int op_char(va_list santa_bag);
int op_str(va_list santa_bag);
int op_int(va_list santa_bag);
int op_d(va_list santa_bag);

#endif
