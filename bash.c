#include "head.h"

int main(void)
{
	char *buf = NULL;
	char *chainArray;
	char *comm;
	int characters, i;
	size_t bufsize = 1024;
	while (1)
	{
		printf("lmao~weed$ ");
		characters = getline(&buf, &bufsize, stdin);
		if (characters  == -1)
		{
			perror("ERROR");
		}
		else
		{
			chainArray = strtok(buf, " ");
			i = 0;

			while (chainArray != NULL)
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
		}
	}
	free(buf);
	return (0);
}
