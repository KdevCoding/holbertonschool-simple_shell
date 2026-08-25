#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
	char *buffer = NULL;
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

		write(STDOUT_FILENO, buffer, char_read);
	}

	return (0);
}
