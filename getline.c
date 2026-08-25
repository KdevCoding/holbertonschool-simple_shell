#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "main.h"

int main(void)
{
	char **args = NULL;
	char *buffer = NULL;
	int i = 0;
	size_t bufsize = 0;
	ssize_t char_read;

	/** Keep program in a loop */
	while (1)
	{
		write(STDOUT_FILENO, "$", 2);
		/** Read the input from stdin */
		char_read = getline(&buffer, &bufsize, stdin);
		
		/** Check for EOF / ctrl D */
		if (char_read == -1)
		{
			free(buffer);
			write(STDOUT_FILENO, "\n", 1);
			break;
		}

		/** Remove trailing newline added by getline() */
		if (char_read > 0 && buffer[char_read - 1] == '\n')
			buffer[char_read - 1] = '\0';

		/** Tokenise the input string using spaces as the delim */
		args = stringsplit(buffer, " ");
		if (args == NULL)
			continue;

		/** Print out each tokenised argument */
		for (i = 0; args[i] != NULL; i++)
		{
			write(STDOUT_FILENO, "Token: ", 7);
			write(STDOUT_FILENO, args[i], strlen(args[i]));
			write(STDOUT_FILENO, "\n", 1);
		}

		free(args);
	}

	return (0);
}
