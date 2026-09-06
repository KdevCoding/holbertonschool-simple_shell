#include "main.h"

/**
 * printenv - prints environment
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
