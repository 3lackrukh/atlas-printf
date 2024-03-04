# `_PRINTF` - Format and Print Data

## NAME
`_printf` - A custom implementation of the printf function in C.

## SYNOPSIS
c #include <stdio.h> #include "main.h"
int `_printf`(const char `*format`, ...);

## FLOWCHART
![Flowchart](/flowchart_printf.png)

## DESCRIPTION
The `_printf` function writes output to the standard output (stdout) under the control of a format string. The format string is composed of zero or more directives, which control the formatting and insertion of data into an output stream.

The function is similar to the standard C library function `printf`, but with a limited set of features. It supports the following conversion specifiers:

- `%c` - character
- `%s` - string
- `%d` - decimal integer
- `%i` - integer

## RETURN VALUE
The `_printf` function returns the number of characters printed (excluding the null byte used to terminate strings). If an error occurs, it returns -1.

## EXAMPLES
Here's a simple example demonstrating the usage of `_printf`:
c #include <stdio.h> #include "main.h"
int main(void) { int len; len = `_printf`("Hello, %s!\n", world"); return 0; }

## SEE ALSO
- `printf(3)`
- `putchar(3)`

## AUTHOR
Jaylen Perez and Nathan Rhys
