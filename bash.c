#include "head.h"


int main(void)
{
	char *buf = NULL;
	char **argv;
/*	char *chainArray; */
/*	char *newenviron[] = { NULL }; */
/*	char *comm; */
	int characters, argc;
	size_t buf_size = 1024;
/*	char *argv[] = {"/bin/ls", "-l", "/usr/", NULL}; */

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
			printf("%s", buf);
			printf("%i\n", argc);
			argv = new_argv(argc, buf);
			printf("%s\n", argv[1]);
			/*
			chainArray = strtok(buf, " ");
			i = 0;

			while ((*chainArray) != NULL)
			{
				if (i == 0)
				{
					comm = chainArray; 
					chainArray = strtok(NULL, " ");
					i++;
				}

				chainArray = strtok(NULL, " ");
			}
			
			if (execve(comm, &chainArray, NULL) == -1)
			{
				perror("ERROR");
			}
			

			execve(argv[0], argv, NULL);
			perror("execve");
			*/
		}
	}
	free(buf);
	return (0);
}
