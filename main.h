#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <string.h>
#include <stdarg.h>

int _printf(const char *format, ...);
int op_char(char a);
int op_str(char *str);
int op_int(int n);
int op_d(signed int n);

#endif
