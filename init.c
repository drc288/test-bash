#include "head.h"

/**
 * exec - execute the default options
 * @argv: pointer to array.
 * @buf: if error free
 * @argc: worlds.
 */

void exec(char **argv, char *buf, int argc, int count)
{
	int i = 0, status = 0;

	if ((_strcmp(argv[0], "exit") == 0) && (argc == 1))
	{
		fflush(stdin);
		free_grid(argv, argc);
		free(buf);
		exit(1);
	}

	if ((_strcmp(argv[0], "exit") == 0) && (argc == 2))
	{
		if (argv[1])
		status = _atoi(argv[1]);
		fflush(stdin);
		free_grid(argv, argc);
		free(buf);
		exit(status);
	}

	if ((_strcmp(argv[0], "/usr/bin/env") == 0) && (argc == 1))
	{
		while (environ[i] != NULL)
		{
			_puts(environ[i]);
			_putchar(10);
			i++;
		}
	}
	else
		new_proccess(argv, buf, argc, count);
}

/**
 * _atoi - Convert strintg to integer
 * @s: pointer to the string to be iterated
 *
 * Return: the number and sign of an array, 0 if no number.
 */
int _atoi(char *s)
{
	int i, sign = 0, num = 0, out = 0;

	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] == '-')
		{
			sign++;
		}
		if (s[i] >= 48 && s[i] <= 57)
		{
			num = num * 10 - (s[i] - '0');
			out = 1;
		}
		else if (out == 1)
		{
			break;
		}
	}
	if ((sign - 1) % 2 != 0)
	{
		num = num * -1;
	}
	return (num);
}
