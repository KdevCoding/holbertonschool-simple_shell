#include "main.h"

/**
 * main - main loop for shell
 *
 * Return: 1 on error else 0
 */
void printenv(void)
{
	int i = 0;
	while (environ[i] != NULL)
	{
		printf("%s\n", environ[i]);
		i++;
	}
	return;
}
