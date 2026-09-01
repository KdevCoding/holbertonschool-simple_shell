#include "main.h"

/**
 * forkexec - Forks the process and executes givenarg/file
 * @args: file to run
 *
 * Return: 1 if error else 0
 */
int forkexec(char **args)
{
	pid_t child_pid;
	int status;
	char *valid_path;
	/* char *const envp[] = {"USER=guest", NULL}; */

	valid_path = find_path(args[0]);
	if (valid_path == NULL)
	{
		fprintf(stderr, "Shell: %s: not found\n", args[0]);
		return (1);
	}

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Fork status failure");
		free(valid_path);
		return (1);
	}

	if (child_pid == 0)
	{
		if (execve(valid_path, args, environ) == -1)
		{
			perror("exec error");
			free(valid_path);
			exit(127);
		}
	}
	else
		wait(&status);

	free(valid_path);
	return (0);
}
