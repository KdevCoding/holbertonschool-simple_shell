#include "main.h"

/**
 * main - main loop for shell
 *
 * Return: 1 on error else 0
 */
int exitc(int token_count, char *args, int *last_status)
{
	int ret = 1;

	if (token_count > 1)
		*last_status = _atoi(args);
	if (*last_status < 0)
	{
		printf("./hsh: 1: exit: Illegal number: %i", *last_status);
		if (isatty(STDIN_FILENO))
			printf("\n");
		*last_status = 2;
		ret = -1;
	}
	return (ret);
}

/**
 * main - main loop for shell
 *
 * Return: 1 on error else 0
 */
int main(void)
{
	int last_status = 0;

	signal(SIGINT, SIG_IGN);
	while (1)
	{
		char **args;
		char *input_buffer;
		int token_count, ret;

		input_buffer = NULL;
		args = readline(&token_count, &input_buffer);
		if (args == NULL)
		{
			free(input_buffer);
			return (last_status);
		}
		if (token_count > 0)
		{
			if (strcmp(args[0], "exit") == 0)
			{
				ret = exitc(token_count, args[1], &last_status);
				if (ret >= 0)
				{
					free(args);
					free(input_buffer);
					exit(last_status);
				}
			}
			else if (strcmp(args[0], "env") == 0)
				printenv();
			else
				last_status = forkexec(args);
		}
		free(args);
		free(input_buffer);
	}
	return (0);
}
