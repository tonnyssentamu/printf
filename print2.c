#include <unistd.h>
#include <stdarg.h>
#include "main.h"
#include <string.h>
#include <stdio.h>

/**
 * print_integer - func for %d and %i for integers
 * @num: input variable
 *
 * Return: decimal or interger
 */

int print_integer(int num)
{
	char buffer[1024];
	int num_chars = 0;
	int is_negative = 0;
	int a, b;
	char temp;
	unsigned int num2;

	if (num < 0)
	{
		is_negative = 1;
		num2 = -num;
	}
	else
	{
		num2 = num;
	}
	do {
		buffer[num_chars++] = num2 % 10 + '0';
		num2 /= 10;
	} while (num2 > 0);

	if (is_negative)
	{
		buffer[num_chars++] = '-';
	}
	for (a = 0, b = num_chars - 1; a < b; a++, b--)
	{
		temp = buffer[a];

		buffer[a] = buffer[b];
		buffer[b] = temp;
	}
	buffer[num_chars] = '\0';

	write(1, buffer, num_chars);
	return (num_chars);
}
