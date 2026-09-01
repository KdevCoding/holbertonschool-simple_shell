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
		char *input_buffer;
		int token_count;

		input_buffer = NULL;
		args = readline(&token_count, &input_buffer);

		if (args == NULL)
		{
			free(input_buffer);
			return (1);
		}
		if (token_count == 0)
		{
			free(args);
			free(input_buffer);
			continue;
		}
		if (strcmp(args[0], "exit") == 0)
		{
			free(args);
			free(input_buffer);
			exit(1);
		}
		if (token_count >= 1)
		{
			forkexec(args);
			free(args);
			free(input_buffer);
			continue;
		}
		else
		{
			perror("error");
			free(args);
			free(input_buffer);
			return (1);
		}
	}
	return (0);
}
