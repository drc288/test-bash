#include "head.h"

/**
 * main - execute new shell
 *
 * Return: 0 to success.
 */

int main(void)
{
	char *buf = NULL;
	char *str = NULL;
	char **argv = NULL;
	int argc = 0, characters = 0, count =1;
	size_t buf_size = 0;

	while (EOF)
	{
		printf("#cisfun$ ");
		fflush(stdin);
		characters = getline(&buf, &buf_size, stdin);
		if (characters  == -1)
		{
			fflush(stdin);
			free(buf);
			exit(1);
		}
		else
		{
			argc = new_argc(buf);
			str = rm_enter(buf);
			argv = new_argv(argc, str);

			if (argc != 0)
			{
				argv[0] = add_path(argv[0], argv, argc, buf);
				exec(argv, buf, argc, count);
			}
			count++;
		}
	}
	free(buf);
	return (0);
}
