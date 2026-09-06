#include "main.h"

/**
 * printenv - prints environment
 * @args: user input
 *
 * Return: always 0
 */
int printenv(char **args)
{
	int i = 0;

	(void)args;
	while (environ[i] != NULL)
	{
		printf("%s\n", environ[i]);
		i++;
	}
	return (0);
}

/**
 * _setenv - sets enviro variable
 * @args: user input
 *
 * Return: always 0
 */
int _setenv(char **args)
{
	int res;

	res = setenv(args[1], args[2], 1);
	if (res == -1)
	{
		if (errno == EINVAL)
			fprintf(stderr, "./hsh: 1: setenv: No name given: %s\n", args[0]);
		else if (errno == ENOMEM)
			fprintf(stderr, "./hsh: 1: setenv: Insufficient memory: %s\n", args[0]);
	}
	return (0);
}

/**
 * _unsetenv - sets enviro variable
 * @args: user input
 *
 * Return: always 0
 */
int _unsetenv(char **args)
{
	int res;

	res = unsetenv(args[1]);
	if (res == -1)
	{
		if (errno == EINVAL)
			fprintf(stderr, "./hsh: 1: unsetenv: No name given: %s\n", args[0]);
	}
	return (0);
}
