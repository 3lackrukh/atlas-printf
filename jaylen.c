#include "main.h"

int op_char(va_list santa_bag)
{
	char a = va_arg(santa_bag, int);
	putchar(a);
	return (1);
}

int op_str(va_list santa_bag)
{
	char *str = va_arg(santa_bag, char *);
	int i = 0;
	int count = 0;

	while (str[i])
	{
		putchar(str[i]);
		i++;
		count++;
	}

	return (count);
}
