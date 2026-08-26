#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

int readline(char **buffer)
{
	size_t bufsize = 0;
	ssize_t char_read;

	printf("$ ");
	char_read = getline(buffer, &bufsize, stdin);
	if (char_read == -1)
	{
		printf("Error or EOF reached.\n");
		return (char_read);
	}

	return (char_read);
}
