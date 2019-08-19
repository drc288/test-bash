#include "head.h"


int main(void)
{
	char *buf = NULL;
/*	char *chainArray; */
/*	char *newenviron[] = { NULL }; */
/*	char *comm; */
	int characters, count;
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
			count = strgs_count(buf);
			printf("%d\n", count);

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
