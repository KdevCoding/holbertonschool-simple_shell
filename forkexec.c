#include "main.h"

int forkexec(char *buffer)
{
	pid_t child_pid;
	int status;
	char *argv[] = {"", NULL};
	char *const envp[] = {"USER=guest", NULL};

	argv[0] = buffer;
	child_pid = fork();

	if (child_pid == 0)
	{
		if (execve(argv[0], argv, envp) == -1)
			perror("exec error: ");
	}
	else
		wait(&status);

	return (0);
}
