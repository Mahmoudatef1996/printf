#include "main.h"
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#define STDOUT_FILENO 1
/**
 * _printf - function for print
 * @format: the formate
 * Return: returns the number of characters
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;
	char *c;

	va_start(args, format);
	for (c = (char *)format; *c; c++)
	{
		if (*c != '%')
		{
			write(STDOUT_FILENO, c, 1);
			count++;
		}
		else if (*(c + 1) == '%')
		{
			write(STDOUT_FILENO, c, 1);
			count++;
			c++;
		}
		else
        {
            switch (*(p + 1))
            {
                case 'c':
                    write(STDOUT_FILENO, &va_arg(args, int), 1);
                    break;
                case 's':
                    count += _puts(va_arg(args, char *));
                    break;
                default:
                    break;
            }
            p++;
            count++;
        }
    }
	va_end(args);
	return count;
}
/**
 * _puts - Prints a string to stdout
 * @s: The string to print
 *
 * Return: Number of characters printed
 */
int _puts(char *s)
{
    int count = 0;

    if (!s)
        s = "(null)";

    while (*s)
    {
        write(STDOUT_FILENO, s++, 1);
        count++;
    }

    return count;
}

