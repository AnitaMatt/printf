#include <stdio.h>
#include <stdarg.h>
#include "main.h"

void print_char(va_list a);
void print_int(va_list a);
void print_float(va_list a);
void print_string(va_list a);
void print_num(va_list a);
/**
 * _printf - this function prints all characters
 * @format:  format
 * Return: number of characters printed
 */

int _printf(const char *format, ...)
{
	int i = 0;
	int count = 0;
	va_list arg;
	int j = 0;
	char *separator = "";
	printAll funcs[] = {
		{"c", print_char},
		{"i", print_int},
		{"f", print_float},
		{"s", print_string},
		{"d", print_num}
	};

	va_start(arg, format);

	while (format && format[i] != '\0')
	{
		if (format[i] == '%')
		{
			j = 0;

			while (j < 5 && (*(format + i + 1)) != *(funcs[j].ch))
				j++;
			if (j < 5)
			{
				printf("%s", separator);
				funcs[j].f(arg);
				separator = " ";
			}
			i += 2;
		}
		putchar(format[i]);
		i++;
		count++;
	}
	va_end(arg);
	return (count);
}
/**
 * print_num - prints a number
 * @a: arga passed
 */
void print_num(va_list a)
{
	int num;
	num = va_arg(a, int);
	printf("%d", num);
}

/**
 * print_char - prints a char
 * @a: args passed
 */
void print_char(va_list a)
{
	char ch;

	ch = va_arg(a, int);
	printf("%c", ch);
}
/**
 * print_int - prints an int
 * @a: args passed
 */
void print_int(va_list a)
{
	int num1;

	num1 = va_arg(a, int);
	printf("%d", num1);
}
/**
 * print_float - prints a float
 * @a: args passed
 */
void print_float(va_list a)
{
	double fl;

	fl = va_arg(a, double);
	printf("%f", fl);
}
/**
 * print_string - prints  a string
 * @a: args passed
 */
void print_string(va_list a)
{
	char *s;

	s = va_arg(a, char *);

	if (s == NULL)
	{
		printf("(nil)");
		return;
	}
	printf("%s", s);
}
