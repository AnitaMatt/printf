#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>

/**
 * struct convert - A convert struct
 * @type: First member
 * @func: Second member
 * Description: Define a new type struct } converter
 */
struct convert
{
	char *type;
	int (*func)();
};

/**
 * converter - Typedef for struct convert
 */
typedef struct convert converter;

int _putchar(int ch);
int _printf(const char *format, ...);
int _printString(va_list myList);
int _printFloat(va_list myList);
int _printInt(va_list myList);
int _printChar(va_list myList);
int _printCent(va_list myList);
int _print_specifier(const char *format, converter myarray[], va_list my_list);
int _print_number(va_list args);


#endif
