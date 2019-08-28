#include "head.h"

/**
 * new_argc - Count the strings in str
 * @str: the string
 *
 * Return: the numbers of strings separate with DELIM
 */

int new_argc(char *str)
{
	char *buf, *token;
	int i = 0, ch;

	buf = NULL;
	token = NULL;
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
 * @array: grid created. (array of pointers)
 * @lengthArray: rows
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
	char *temp = NULL;
	char *token = NULL;
	char **array = NULL;
	int length = 0, i = 0;

	array = malloc(sizeof(char *) * (argc + 1));
	if (array == NULL)
		perror("ERROR");

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
	while (token != NULL)
	{
		length = _strlen(token);
		array[i] = malloc(sizeof(char) * (length + 1));
		if (array[i] == NULL)
		{
			free_grid(array, argc);
			perror("ERROR");
		}
		array[i] = _strcpy(array[i], token);
		token = strtok(NULL, DELIM);
		i++;
	}
	array[i] = NULL;
	free(temp);
	free(str);
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

	buf[i - 1] = '\0';
	return (buf);
}

/**
 * _strcat - pointer to pointer
 * @dest: Input data array 1
 * @src: Input data array 2
 *
 * Return: dest
 */
char *_strcat(char *dest, char *src)
{
	int i, j;

	for (i = 0; dest[i] != '\0'; i++)
	{
	}
	for (j = 0; src[j] != '\0'; j++, i++)
	{
		dest[i] = src[j];
	}
	dest[i] = '\0';
	return (dest);
}


/**
 * add_path - check if there's an executable file in any of the PATH folders
 * @command: argv[0] command entered
 *
 * Return: argv[0] modified with the path the file is located at
 */
char *add_path(char *command, char **argv, int argc, char *buf)
{
	int length, i;
	char *path, *token, *temp;

	path = NULL;
	if (command[0] != '/')
	{
		for (i = 0; environ[i] != NULL; i++)
			if (_strcmp(environ[i], "PATH") == 0)
			{
				length = _strlen(environ[i]);
				path = malloc(sizeof(char) * length + 1);
				if (path == NULL)
				{
					free_grid(argv, argc);
					free(buf);
					perror("ERROR");
				}
				path = _strcpy(path, environ[i]);
			}
		token = strtok(path, "=");
		token = strtok(NULL, "=");
		token = strtok(token, ":");
		while (token != NULL)
		{
			length = _strlen(token);
			temp = malloc(sizeof(char) * (length + _strlen(command) + 2));
			if (temp == NULL)
			{
				free(path);
				free_grid(argv, argc);
				free(buf);
				perror("ERROR");
			}
			temp = _strcpy(temp, token);
			temp = _strcat(temp, "/");
			temp = _strcat(temp, command);
			if (access(temp, X_OK) == 0)
			{
				free(path);
				free(command);
				return (temp);
			}
			free(temp);
			token = strtok(NULL, ":");
		}
		free(path);
		return (command);
	}
	return (command);
}
