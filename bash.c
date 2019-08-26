#include "head.h"

int main(void)
{
	char *buf = NULL;
	char *str = NULL;
	pid_t pid;
	char **argv = NULL;
	int argc = 0, characters = 0;
	size_t buf_size = 0;

	while (1)
	{
		printf("#cisfun$ ");
		fflush(stdin);
		characters = getline(&buf, &buf_size, stdin);
		if (characters  == -1)
		{
			exit(1);
		}
		else
		{
			argc = new_argc(buf);
			str = rm_enter(buf);
			argv = new_argv(argc, str);
			free(str);
			if (argc != 0)
			{
				if ((argc == 1) && (_strcmp(argv[0], "exit") == 0))
				{
					fflush(stdin);
					free_grid(argv,argc);
					free(buf);
					exit(1);
				}

				pid = fork();
				if (pid == 0)
				{
					if (execve(argv[0], argv, NULL) == -1)
						perror("./shell");
				/*		perror("./hsh: 1: %s: not found", errno); */
					free_grid(argv, argc);
					free(buf);
					exit(1);
				}
				else
				{
					free_grid(argv, argc);
					wait(NULL);
					kill(pid, SIGKILL);
					/*
					free_grid(argv, argc);
					free(buf);
					wait(pid);
					*/
				}
			}
		}
	}
	free(buf);
	return (0);
}
