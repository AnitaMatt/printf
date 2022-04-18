#include <stdio.h>
11;rgb:0000/0000/0000#include <stdarg.h>
#include "main.h"

void print_char(va_list a);
void print_int(va_list a);
void print_float(va_list a);
void print_string(va_list a);

/**
 * allch - this function prints all characters
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
		{"s", print_string}
	};

	va_start(arg, format);

	while (format && format[i] != '\0')
	{
		if (format[i] == '%')
		{
			j = 0;

			while (j < 4 && (*(format + i + 1)) != *(funcs[j].ch))
				j++;
			if (j < 4)
			{
				printf("%s", separator);
				funcs[j].f(arg);
				separator = " ";
			}
			if (!(format[i + 1] == '%'))
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
	int i;

	i = va_arg(a, int);
	printf("%d", i);
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
