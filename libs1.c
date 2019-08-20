#include "head.h"

/**
 * _strlen - Count the maximum number of a array
 * @s: Input Array
 *
 * Return: counter
 */

int _strlen(char *s)
{
	int cont;

	cont = 0;
	while (s[cont])
		cont++;

	return (cont);
}

/**
 * _strcpy - copy pointers
 * @dest: destination
 * @src: string to copy
 * Return: the pointer to dest
 */

char *_strcpy(char *dest, char *src)
{
	int i;

	for (i = 0; src[i] != 0; i++)
		dest[i] = src[i];

	dest[i] = '\0';
	return (dest);
}

/**
 * strgs_count - Count the strings in str
 * @str: the string
 *
 * Return: the numbers of strings separate with " "
 */

int new_argc(char *str)
{
	char *buf;
	int i = 0, ch;

	ch = _strlen(str);
	buf = malloc(ch + 1);
	if (buf == NULL)
		perror("ERROR");

	buf = _strcpy(buf, str);
	buf = strtok(buf, " ");
	if (buf == NULL)
		perror("ERROR");

	while (buf != NULL)
	{
		i++;
		buf = strtok(NULL, " ");
	}
	free(buf);
	return (i);
}
