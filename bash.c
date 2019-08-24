#include "head.h"

int main(void)
{
	char *buf = NULL;
	char *str = NULL;
	pid_t pid;
	char **argv;
	int characters, argc;
	size_t buf_size = 0;

	while (1)
	{
		printf("lmao~weed$ ");
		fflush(stdin);
		characters = getline(&buf, &buf_size, stdin);
		if (characters  == -1)
		{
			perror("ERROR");
		}
		else
		{
			argc = new_argc(buf);
			str = rm_enter(buf);
			argv = new_argv(argc, str);
			free(str);
			if (argc != 0)
			{
				pid = fork();
				if (pid == 0)
				{
					if (execve(argv[0], argv, NULL) == -1)
						perror("ERROR");
					free_grid(argv, argc);
				}
				else
				{
					free_grid(argv, argc);
					free(buf);
					wait(NULL);
				}
			}
		}
	}
	free(buf);
	return (0);
}
