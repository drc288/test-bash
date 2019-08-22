#include "head.h"
/**
 * strgs_count - Count the strings in str
 * @str: the string
 *
 * Return: the numbers of strings separate with DELIM
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
	buf = strtok(buf, DELIM);
	if (buf == NULL)
		perror("ERROR");

	while (buf != NULL)
	{
		i++;
		buf = strtok(NULL, DELIM);
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
		printf("%p", *(array + lengthArray));
                free(*(array + lengthArray));
		i++;
        }
        free(array);

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
	char *temp;
	char **array;
	int length, i;

	array = malloc(sizeof(char *) * argc);
	if (array == NULL)
	{
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
	temp = strtok(temp, DELIM);
	if (temp == NULL)
	{
		free(array);
		perror("ERROR");
	}

	i = 0;
	while (temp != NULL)
	{
		length = _strlen(temp);
		array[i] = malloc(sizeof(char) * (length + 1));
		array[i] = _strcpy(array[i], temp);
		i++;
		temp = strtok(NULL, DELIM);
	}
	free(temp);
	return (array);
}

/**
 * first_string - remove the character '\n' in str
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

	buf[i - 1] = '\0';
	return (buf);
}
