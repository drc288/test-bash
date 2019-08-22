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
			buf = rm_enter(buf);
			argv = new_argv(argc, buf);

			printf("%s\n", buf);

			pid = fork();
			if (pid == 0)
			{
				if (execve(argv[0], argv, NULL) == -1)
					perror("ERROR");
			}
		}
	}
	free(buf);
	return (0);
}
