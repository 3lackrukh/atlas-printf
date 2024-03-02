#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int op_d(va_list santa_bag)
{
	int i, count;
	int num = va_arg(santa_bag, int);
	int sign = num < 0 ? -1 : 1;
	char str[11];// allocates memory for max digits for int
		     // plus 1 for the - symbol

	num *= sign; // if num is - value, changes to + value
		     // for easier handling

	for(i = 0; num > 0; i++)
	{
		str[i] = (num % 10) + '0'; //converts int to ASCII value
		num /= 10;
	}

	if(sign == -1)
	{
		str[i++] = '-' //add the negative symbol to string
	}

	count = i; //saves the number of char's to be printed
	i--;
	while (i >= 0)
	{
		putchar(str[i]);//print the string in reverse
		i--;
	}
	return(count); //return value added to print_arg count in _printf
}

int op_int(va_list santa_bag)
{
	int i, count;
	int num = va_arg (santa_bag, int);
	int sign = num < 0 ? -1 : 1;
	char str[11];

	num *= sign;

	for (i = 0; num > 0; i++)
	{
		str[i] = (num % 10) + '0';
		num /= 10;
	}

	if(sign == -1)
	{
		str[i++] = '-'
	}

	count = i;
	i--;
	while (i >= 0)
	{
		putchar(str[i]);
		i--;
	}
	return(count);
}
