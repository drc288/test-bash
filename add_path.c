#include "head.h"

/**
 * split_path - Split the path and the token to keep only the path and not PATH=
 * @path: str to be split with strtok
 * @token: pointer to the str after =
 *
 * Return: token with the correct str
 */
char *split_path(char *path, char *token)
{
        token = strtok(path, "=");
        token = strtok(NULL, "=");
        token = strtok(token, ":");
        return (token);
}

/**
 * check_access - check wheter the file exist or not in the path
 * @temp: malloc created to store the path to test with access
 * @token: path to be copy into temp
 * @command: command to be concatenated with the path
 * @path: path to be freed in sucess case
 *
 * Return: temp if access worked - NULL otherwise
 */
char *check_access(char *temp, char *token, char *command, char *path)
{
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
        temp = NULL;
        return (temp);
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
	token = NULL;
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
                token = split_path(path, token);
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
			temp = check_access(temp, token, command, path);
			if (temp != NULL)
				return (temp);
                        token = strtok(NULL, ":");
                }
                free(path);
                return(command);
        }
        return (command);
}
