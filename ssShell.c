#include "main.h"

int main()
{
	while (1)
	{
		char **args;
		int token_count;

		args = readline(&token_count);

		if (strcmp(args[0], "exit") == 0)
		{
			free(args[0]);
			free(args);
			exit(1);
		}
		if (ret >= 0)
		{
			forkexec(inbuf);
			free(inbuf);
		}
		else
		{
			perror("error");
			free(args[0]);
			free(args);
			return (1);
		}
	}
	return (0);
}