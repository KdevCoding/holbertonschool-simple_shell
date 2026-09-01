#include "main.h"

/**
 * stringsplit - splits given 'string' by given delim
 * @str:str to split
 * @delim: what to split by
 * @token_count: where to put count of tokens/splits
 *
 * Return: Pointer to the value string, else NULL.
 */
char **stringsplit(char *str, const char *delim, int *token_count)
{
	char **tokens = NULL;
	char *token = NULL;
	int i = 0;
	int count = 0;
	int in_token = 0;

	if (str == NULL)
		return (NULL);
	while (str[i] != '\0')
	{
		if (strchr(delim, str[i]) == NULL)
		{
			if (in_token == 0)
			{
				count++;
				in_token = 1;
			}
		}
		else
			in_token = 0;
		i++;
	}
	tokens = malloc(sizeof(char *) * (count + 1));
	if (tokens == NULL)
		return (NULL);
	i = 0;
	token = strtok(str, delim);
	while (token != NULL)
	{
		tokens[i] = token;
		i++;
		token = strtok(NULL, delim);
	}
	tokens[i] = NULL;
	if (token_count != NULL)
	{
		*token_count = i;
	}
	return (tokens);
}
