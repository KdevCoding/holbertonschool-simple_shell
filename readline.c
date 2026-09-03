#include "main.h"

/**
 * readline - reads user input
 * @token_count: amount of tokens
 * @input_buffer: input_buffer
 *
 * Return: file and args to run
 */
char **readline(int *token_count, char **input_buffer)
{
	char **args;
	char *buffer = NULL;
	size_t bufsize = 0;
	ssize_t char_read;

	if (isatty(STDIN_FILENO))
	{
		printf("Shell$ ");
	}
	char_read = _getline(&buffer, &bufsize, stdin);
	if (char_read == -1)
	{
		free(buffer);
		*input_buffer = NULL;
		return (NULL);
	}
	else
	{
		buffer[strcspn(buffer, "\n")] = '\0';
		args = stringsplit(buffer, " ", token_count);
		*input_buffer = buffer;
		return (args);
	}
}
