#include "head.h"

/**
 * exec - create new pid and exec the comand
 * @argv: poiinter array
 * @argc: words
 * @buf: if error free str
 *
 */

void exec(char **argv, char *buf, int argc)
{
	pid_t pid;

	if ((argc == 1) && (_strcmp(argv[0], "exit") == 0))
	{
		fflush(stdin);
		free_grid(argv, argc);
		free(buf);
		exit(1);
	}

	pid = fork();
	if (pid == 0)
	{
		if (execve(argv[0], argv, NULL) == -1)
			perror("./shell");

		free_grid(argv, argc);
		free(buf);
		exit(1);
	}
	else
	{
		free_grid(argv, argc);
		wait(NULL);
		kill(pid, SIGKILL);
	}
}
