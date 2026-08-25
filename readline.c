#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

int readline(char **buffer)
{
	size_t bufsize = 0;
	ssize_t chars;
	printf("$ ");
	chars = getline(buffer, &bufsize, stdin);

	if (chars == -1)
		printf("Error or EOF reached.\n");

	return (chars);
}
