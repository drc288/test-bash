#include "head.h"


int main(void)
{
	char *buf = NULL;
	pid_t pid;
	char **argv;
	int characters, argc;
	size_t buf_size = 0;

	while (1)
	{
		printf("lmao~weed$ ");
		fflush( stdin );
		characters = getline(&buf, &buf_size, stdin);
		if (characters  == -1)
		{
			perror("ERROR");
		}
		else
		{
			argc = new_argc(buf);
			buf = rm_enter(buf);
			argv = new_argv(argc, buf);

			if (argc != 0)
			{
				pid = fork();
				if (pid == 0)
				{
					if (execve(argv[0], argv, NULL) == -1)
						perror("ERROR");
					free_grid(argv, argc);
					free(argv);
					free(buf);
				}
				else
				{
					free_grid(argv, argc);
					free(argv);
					free(buf);
					wait(NULL);
				}
			}
		}
	}
	return (0);
}
