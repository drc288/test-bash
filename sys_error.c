#include "head.h"

void sys_error(char **argv, int count, char *error)
{
	_puts("#cisfun$: ");
	print_number(count);
	_puts(": ");
	_puts(argv[0]);
	_puts(": ");
	_puts(error);
	_putchar(10);
}

/**
 * print_number - print integer.
 * @n: the integer.
 **/

void print_number(int n)
{
	unsigned int i;

	if (n < 0)
	{
		_putchar('-');
		i = n * -1;
	}
	else
	{
		i = n;
	}
	if (n / 10 != 0)
	{
		print_number(i / 10);
	}
	_putchar(i % 10 + '0');
}

