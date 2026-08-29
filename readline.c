#include "main.h"

/**
 * readline - reads user input
 *
 * Return: file and args to run
 */
char **readline(int *token_count)
{
	char **args;
	char *buffer = NULL;
	size_t bufsize = 0;
	ssize_t char_read;

	printf("Shell$ ");
	char_read = getline(&buffer, &bufsize, stdin);
	if (char_read == -1)
	{
		printf("Error or EOF reached.\n");
		free(buffer);
		return (NULL);
	}
	else
	{
		buffer[strcspn(buffer, "\n")] = '\0';
		args = stringsplit(buffer, " ", token_count);
		return (args);
	}
}