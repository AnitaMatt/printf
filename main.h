#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
/**
 * struct myPrintf - struct defining a print function
 * @ch:  charcter to a data type
 * @f: function pointing to printing a data type
 */

typedef struct myPrintf
{
	char *ch;
	void (*f)(va_list args);
} printAll;

int _printf(const char *format, ...);

#endif
