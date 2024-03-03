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
/*
 * using i, iterates through the recieved string,
 * prints each char, and increments count
 * until the '\0' is reached.
 *
 * count is returned as an int
 */
	if (str == NULL)
	{
		str = malloc(sizeof(char) * 6);
		allocated = 1;
		if (str == NULL)
		{
			return (-1);
		}
		str = "(null)";
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
/*
 * @i: iterator to scan through converted string
 * @count: holds the value of printed chars to return.
 * @sign: checks if the int recieved is of negative value.
 * @str allocates memory for max digits of int and a
 * potential '-' symbol in the case of a negative value
 */
	int i, count;
	int num = va_arg(santa_bag, int);
	int sign = num < 0 ? -1 : 1;
	char str[11];

	num *= sign;
/*
 * convert each digit of num to chars
 * the remainder of division by 10 is converted to
 * ASCII value by adding 55 or '0' & stored in string str.
 */
	for (i = 0; num > 0; i++)
	{
		str[i] = (num % 10) + '0';
		num /= 10;
	}
	if (sign == -1)
	{
		str[i++] = '-';
	}
/*
 * str length saved to int count.
 * decriment through the string and print each char,
 */
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
	int num = va_arg(santa_bag, int);
	int sign = num < 0 ? -1 : 1;
	char str[11];

	num *= sign;
/*
 * convert each digit of num to chars
 * the remainder of division by 10 is converted to
 * its ASCII value by adding 55 or '0'& stored in string.
 */
	for (i = 0; num > 0; i++)
	{
		str[i] = (num % 10) + '0';
		num /= 10;
	}
/*
 * once each digit is stored,
 * if num was - '-' is added to the end of the string.
 */
	if (sign == -1)
	{
		str[i++] = '-';
	}
/*
 * str length saved to int count.
 * decriment through the string and print each char,
 */
	count = i;
	i--;
	while (i >= 0)
	{
		putchar(str[i]);
		i--;
	}
	return (count);
}
