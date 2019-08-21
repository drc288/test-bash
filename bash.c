#include "head.h"


int main(void)
{
	char *buf = NULL;
	pid_t pid;
	char **argv;
	int characters, argc;
	size_t buf_size = 1024;

	while (1)
	{
		printf("lmao~weed$ ");
		characters = getline(&buf, &buf_size, stdin);
		if (characters  == -1)
		{
			perror("ERROR");
		}
		else
		{

			argc = new_argc(buf);
			argv = new_argv(argc, buf);

/*			if (argc == 1) */
/*				buf = first_string(buf); */

			pid = fork();
			if (pid == 0)
			{
				if (execve(argv[0], argv, NULL) == -1)
					perror("ERROR");
			}
		}
		free_grid(argv, argc);
	}
	free(buf);
	return (0);
}
