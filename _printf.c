#include "main.h"

/**
 * _printf - Function entry
 * Description: A function that produces output according to a format
 * @format: is a character string
 * @...: list of arguments
 * Return: the number of characters printed
 * (excluding the null byte used to end output to strings)
 */
int _printf(const char *format, ...)
{
	/**
	 * unsigned int i = 0;
	 * int return_count;
	 */
	int my_print = 0;
	va_list args;
	converter formatchar[] = {
		{"s", _printString},
		{"i", _printInt},
		{"f", _printFloat},
		{"c", _printChar},
		{"%", _printCent},
		{NULL, NULL}
	};

	va_start(args, format);

	my_print = _print_specifier(format, formatchar, args);

	va_end(args);

	return (my_print);
}
