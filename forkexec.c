#include "main.h"

/**
 * forkexec - Forks the process and executes givenarg/file
 * @args: file to run
 *
 * Return: 127 if error else 0
 */
int forkexec(char **args)
{
	pid_t child_pid;
	int status;
	char *valid_path;

	valid_path = find_path(args[0]);
	if (valid_path == NULL)
	{
		fprintf(stderr, "./hsh: 1: %s: not found\n", args[0]);
		return (127);
	}
	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Fork status failure");
		free(valid_path);
		return (127);
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
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	return (1);
}
