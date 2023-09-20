#include <stdio.h>
#include <stdarg.h>

int _printf(const char *format, ...);

/*
 * _printf - unction that produces output according to a format
 * @*format: ...
 * @...: ...
 *
 * Return: Alway 0
 */

int _printf(const char *format, ...)
{
	va_list args;

	va_start(args, format);

	int chars_printed = 0;

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == '\0')
			{
				break;
			}
			if (*format == 'c')
			{
				int c = va_arg(args, int);

				putchar(c);

				chars_printed++;
			}
			else if (*format == 's')
			{
				char *str = va_arg(args, char *);

				if (str != NULL)
				{
					while (*str)
					{
						putchar(*str);
						str++;
						chars_printed++;
					}
				}
			}
			else if (*format == '%')
			{
				putchar('%');
				chars_printed++;
			}
		}
		else
		{
			putchar(*format);
			chars_printed++;
		}
		format++;
	}
	va_end(args);
	return (chars_printed);
}
