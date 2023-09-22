#include "main.h"
#include <stdarg.h>
#include <string.h>
#include <unistd.h>

/**
 * print_binary - function to handle binary conversion
 * @num: input variable
 * Return: ...
 */

int print_binary(unsigned int num)
{
	char binary[32];
	int x = 0, y;

	if (num == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	for (y = 31; y >= 0; y--)
	{
		binary[x++] = (num & (1 << y)) ? '1' : '0';
	}

	x = 0;
	while (binary[x] == '0')
	{
		x++;
	}

	write(1, binary + x, 32 - x);
	return (32 - x);
}
