#include "head.h"

/**
 * new_proccess - create new pid and exec the comand.
 * @argv: pointer to array.
 * @argc: words.
 * @buf: if error free *
 */

void new_proccess(char **argv, char *buf, int argc, int count)
{
	pid_t pid;

	pid = fork();
	if (pid == 0)
	{
		if (execve(argv[0], argv, NULL) == -1)
		{
			sys_error(argv, count, "not found");
			count--;
		}

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
