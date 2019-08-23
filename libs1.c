#include "head.h"

/**
 * strgs_count - Count the strings in str
 * @str: the string
 *
 * Return: the numbers of strings separate with DELIM
 */

int new_argc(char *str)
{
	char *buf, *token;
	int i = 0, ch;

	ch = _strlen(str);
	buf = malloc(ch + 1);
	if (buf == NULL || str == NULL)
		perror("ERROR");

	buf = _strcpy(buf, str);
	token = strtok(buf, DELIM);

	while (token != NULL)
	{
		i++;
		token = strtok(NULL, DELIM);
	}
	free(buf);
	return (i);
}

/**
 * free_grid - frees a 2 dimensional grid
 * @grid: grid created. (array of pointers)
 * @height: rows
 *
 * Return: void. Frees memory
 */
void free_grid(char **array, int lengthArray)
{
        int i;

        i = 0;
        while (i < lengthArray)
        {
                free(*(array + i));
		i++;
        }
}

/**
 * new_argv - split a string and create an array of strs
 * @argc: counter of strs given
 * @str: string to be split
 *
 * Return: Pointer to an array of strs
 */
char **new_argv(int argc, char *str)
{
	char *temp, *token;
	char **array;
	int length, i;

	array = NULL;
	array = malloc(sizeof(char *) * (argc + 1));
	if (array == NULL)
	{
		perror("ERROR");
	}
	if (str == NULL)
	{
		free(array);
		perror("ERROR");
	}

	length = _strlen(str);
	temp = malloc(sizeof(char) * (length + 1));
	if (temp == NULL)
	{
		free(array);
		perror("ERROR");
	}

	temp = _strcpy(temp, str);
	token = strtok(temp, DELIM);
	i = 0;
	while (token != NULL)
	{
		length = _strlen(token);
		array[i] = malloc(sizeof(char) * (length + 1));
		array[i] = _strcpy(array[i], token);
		token = strtok(NULL, DELIM);
		i++;
	}
	array[i] = NULL;
	free(temp);
	return (array);
}

/**
 * rm_enter - remove the character '\n' in str
 * @str: string to edit
 *
 * Return: the string
 */

char *rm_enter(char *str)
{
	char *buf;
	int sLen, i;

	sLen = _strlen(str);
	buf = (char *)malloc(sLen * sizeof(char));
	if (buf == NULL)
	{
		perror("ERROR");
	}

	for (i = 0; str[i] != 0; i++)
		buf[i] = str[i];

	free(str);
	buf[i - 1] = '\0';
	return (buf);
}
