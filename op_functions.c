#include "main.h"

/**
 * op_char- A helper function that prints a char
 * handed in from _printf.
 *
 * @santa_bag: the argument handed in from
 * _printf of expected type char.
 *
 * Return: always 1.
 */

int op_char(va_list santa_bag)
{
	char a = va_arg(santa_bag, int);

	putchar(a);
		return (1);
}
/**
 * op_str- A helper function that prints a string
 * handed in from _printf.
 *
 * @santa_bag: the argument handed in from
 * print_f of expected type char *.
 *
 * Return: the number of printed chars.
 */
int op_str(va_list santa_bag)
{
	char *str = va_arg(santa_bag, char *);
	int i = 0;
	int count = 0;
	int allocated = 0;

	if (str == NULL)
	{
		str = malloc(sizeof(char) * 7);
		allocated = 1;
		if (str == NULL)
		{
			return (-1);
		}
		strcpy(str, "(null)");
	}
	while (str[i])
	{
		putchar(str[i]);
		i++;
		count++;
	}
	if (allocated)
	{
		free(str);
	}
	return (count);
}
/**
 * op_d- A helper function that converts and prints
 * an integer handed in from _printf, into a char string
 * @santa_bag: the argument handed in from _printf
 * of expected type int.
 * Return: the number of printed chars.
 */
int op_d(va_list santa_bag)
{
	int i, count;
	int overflow = 0;
	int num = va_arg(santa_bag, int);
	int sign = num < 0 ? -1 : 1;
	char str[11];

	if (num == 0)
	{
		putchar('0');
		return (1);
	}
	if (num == INT_MIN)
	{
		overflow = 1;
		num += 1;
	}
	num *= sign;
	for (i = 0; num > 0; i++)
	{
		if (overflow)
		{
			str[i] = (num % 10) + '1';
			num /= 10;
			overflow = 0;
			i++;
		}
		str[i] = (num % 10) + '0';
		num /= 10;
	}
	if (sign == -1)
		str[i++] = '-';
	count = i;
	i--;
	while (i >= 0)
	{
		putchar(str[i]);
		i--;
	}
	return (count);
}
/**
 * op_int- A helper function that converts an integer
 * into a char string and prints to standard output.
 * @santa_bag: the argument handed in from _printf
 * of expected type int.
 * Return: the number of printed chars.
 */
int op_int(va_list santa_bag)
{
	int i, count;
	int overflow = 0;
	int num = va_arg(santa_bag, int);
	int sign = num < 0 ? -1 : 1;
	char str[11];

	if (num == 0)
	{
		putchar('0');
		return (1);
	}
	if (num == INT_MIN)
	{
		overflow = 1;
		num += 1;
	}
	num *= sign;
	for (i = 0; num > 0; i++)
	{
		if (overflow)
		{
			str[i] = (num % 10) + '1';
			num /= 10;
			overflow = 0;
			i++;
		}
		str[i] = (num % 10) + '0';
		num /= 10;
	}
	if (sign == -1)
		str[i++] = '-';
	count = i;
	i--;
	while (i >= 0)
	{
		putchar(str[i]);
		i--;
	}
	return (count);
}
