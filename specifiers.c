#include "main.h"

/**
 * _printCent - Function entry
 * Description: A function that print the % type
 * @myList: va_list passed to the function
 * Return: See nothing!
 */
int _printCent(__attribute__((__unused__))va_list myList)
{
	_putchar('%');
	return (1);
}


/**
 * _printString - Function entry
 * Description: A function that print the string type
 * @myList: va_list passed to the function
 * Return: See nothing!
 */
int _printString(va_list myList)
{
	int i = 0;
	char *string = va_arg(myList, char *);

	if (string == NULL)
		string = "(nil)";
	while (string[i] != '\0')
	{
		_putchar(string[i]);
		i++;
	}
	return (i);
}


/**
 * _printFloat - Function entry
 * Description: A function that print the float type
 * @myList: va_list passed to the function
 * Return: See nothing!
 */
int _printFloat(va_list myList)
{
	printf("%f", va_arg(myList, double));
	return (1);
}

/**
 * _printInt - Function entry
 * Description: A function that print the int type
 * @myList: va_list passed to the function
 * Return: See nothing!
 */
int _printInt(va_list myList)
{
	int length = _print_number(myList);
	return (length);
}


/**
 * _printChar - Function entry
 * Description: A function that print the char type
 * @myList: va_list passed to the function
 * Return: See nothing!
 */
int _printChar(va_list myList)
{
	int c = va_arg(myList, int);

	_putchar(c);
	return (1);
}
