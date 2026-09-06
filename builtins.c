#include "main.h"

/**
 * printenv - prints environment
 * @args: user input
 *
 * Return: always 0
 */
int printenv(int token_count, char **args)
{
	int i = 0;

	(void)args;
	(void)token_count;
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
int _setenv(int token_count, char **args)
{
	int res = 0;

	if (token_count >= 3)
		res = setenv(args[1], args[2], 1);
	else
		fprintf(stderr, "./hsh: 1: setenv: No name/var given: %s\n", args[0]);

	if (res == -1)
	{
		if (errno == ENOMEM)
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
int _unsetenv(int token_count, char **args)
{
	int res;
	(void)token_count;

	res = unsetenv(args[1]);
	if (res == -1)
	{
		if (errno == EINVAL)
			fprintf(stderr, "./hsh: 1: unsetenv: No name given: %s\n", args[0]);
	}
	return (0);
}
