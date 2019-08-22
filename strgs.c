#include "head.h"

/**
 * _strcmp - print te charecter ++ or --
 * @s1: input char # 1
 * @s2: input char # 2
 *
 * Return: integer
 */

int _strcmp(char *s1, char *s2)
{
	int i;

	for (i = 0; (s1[i] != '\0') && (s2[i] != '\0'); i++)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
	}
	return (0);
}

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
 *
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
