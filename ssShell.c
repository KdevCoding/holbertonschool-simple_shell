#include "main.h"

/**
 * main - main loop for shell
 *
 * Return: 1 on error else 0
 */
int main(void)
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
		if (token_count >= 1)
		{
			forkexec(args);
			free(args[0]);
			free(args);
			continue;
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
