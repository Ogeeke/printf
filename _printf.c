#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * _printf - Custom printf function
 * @format: The format string
 * @...: Variable number of arguments
 * Return: Number of characters printed
 */
int _printf(const char *format, ...)
{
    va_list args;
    int count = 0;

    va_start(args, format);

    while (*format)
    {
        if (*format != '%')
        {
            write(1, format, 1); // Print non-% characters
            count++;
        }
        else
        {
            format++; // Move to the character after '%'
            switch (*format)
            {
                case 'c':
                {
                    char c = va_arg(args, int); // Get the character argument
                    write(1, &c, 1); // Print the character
                    count++;
                    break;
                }
                case 's':
                {
                    char *str = va_arg(args, char *); // Get the string argument
                    while (*str)
                    {
                        write(1, str, 1); // Print each character of the string
                        str++;
                        count++;
                    }
                    break;
                }
                case '%':
                {
                    write(1, "%", 1); // Print a literal %
                    count++;
                    break;
                }
                default:
                    write(1, "%", 1); // Print the original % and the unknown character
                    write(1, format, 1);
                    count += 2;
                    break;
            }
        }
        format++; // Move to the next character in the format string
    }

    va_end(args);
    return count;
}

