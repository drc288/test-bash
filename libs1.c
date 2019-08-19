#include "head.h"

/**
 * strgs_count - Count the strings in str
 * @str: the string
 *
 * Return: the numbers of strings separate with " "
 */

int strgs_count(char *str)
{
	char *buf;
	int i = 0;

	buf = strtok(str, " ");
	if (buf == NULL)
		perror("ERROR");

	while (buf != NULL)
	{
		i++;
		buf = strtok(NULL, " ");
	}

	return (i);
}
