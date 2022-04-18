#include "main.h"

/**
 * _print_specifier - Function entry
 * Description: A function that loop through a string,
 * run the format specifier function where true
 * @format: is a character string
 * @myarray: an array of conversion specifier
 * @my_list: list of arguments
 * Return: the count of the character in format
 */
int _print_specifier(const char *format, converter myarray[], va_list my_list)
{
	int count = 0, i = 0;

	while (format && format[i] != '\0')
	{

		if (format[i] == '%' && format[i + 1] != '\0')
		{
			int j = 0;
			int ret_count = 0;

			while ((*(myarray + j)).type != NULL)
			{
				if ((*(myarray + j)).type[0] == format[i  + 1])
				{
					ret_count = (myarray[j]).func(my_list);
					if (ret_count == -1)
						return (-1);
					count += ret_count;
					break;
				}
				j++;
			}
			i++;
		}
		else
		{
			_putchar(format[i]);
			count++;
		}
		i++;
	}
	return (count);

}

/**
 * _putchar - function name
 * @ch: The input character to print
 * Description: A program that print a character to standard output
 *
 * Return: The provided character or an EOF error
 */
int _putchar(int ch)
{
	return (write(1, &ch, 1));
}
