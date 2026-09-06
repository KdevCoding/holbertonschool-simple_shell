#include "main.h"

/**
 * exitc - does calcs to exit
 * @token_count: how many input arguments
 * @arg: argument to convert to int
 * @last_status: where to put exit status
 *
 * Return: -1 if negative else 1
 */
int exitc(int token_count, char *arg, int *last_status)
{
	int ret = 1;

	if (token_count > 1)
	{
		*last_status = _atoi(arg);
		if (*last_status < 0 || (arg[1] < 48 || arg[1] > 57))
		{
			fprintf(stderr, "./hsh: 1: exit: Illegal number: %s\n", arg);
			*last_status = 2;
			ret = -1;
		}
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
		conv_t f;

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
			else
			{
				f = func_spec(args[0]);
				last_status = f(args);
			}
		}
		free(args);
		free(input_buffer);
	}
	return (0);
}
