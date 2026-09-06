#include "main.h"

/**
 * func_spec - choosing the correct function for printf.
 * @str: 'str' to compare
 *
 *
 * Return: pointer to function to use
 */

conv_t func_spec(char *str)
{
	func_t funcs[] = {
		{"env", printenv},
		{"setenv", _setenv},
		{"unsetenv", _unsetenv},

		{NULL, forkexec}};
	int i;

	i = 0;
	while (funcs[i].arg != NULL)
	{
		if (strcmp(str, funcs[i].arg) == 0)
		{
			break;
		}
		i += 1;
	}
	return (funcs[i].f);
}
