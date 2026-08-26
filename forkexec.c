#include "main.h"

int forkexec(char **args)
{
	pid_t child_pid;
	int status;
	char *const envp[] = {"USER=guest", NULL};

	child_pid = fork();

	if (child_pid == 0)
	{
		if (execve(args[0], args, envp) == -1)
		{
			perror("exec error");
			exit(0);
		}
	}
	else
		wait(&status);

	return (0);
}
