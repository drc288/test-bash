#include "head.h"


int main(void)
{
	char *buf = NULL;
	pid_t pid;
	char **argv;
	int characters = 0, argc = 0;
	size_t buf_size = 0;

	while (1)
	{
		printf("lmao~weed$ ");
		fflush(stdin);
		characters = getline(&buf, &buf_size, stdin);
		if (characters  == -1)
		{
			putchar(10);
			exit(1);
		}
	else
		{
			argc = new_argc(buf);
			buf = rm_enter(buf);
			argv = new_argv(argc, buf);

			if (argc != 0)
			{
				if ((argc == 1) && (_strcmp(argv[0], "exit") == 0))
				{
					fflush(stdin);
					exit(1);
				}

				pid = fork();
				if (pid == 0)
				{
					if (execve(argv[0], argv, NULL) == -1)
						perror("ERROR");
				}
				else
				{
					wait(pid);
				}
			}
		}
	}
	free(buf);
	return (0);
}
