#include "main.h"

char **stringsplit(char *str, const char *delim, int *token_count)
{
	char **tokens = NULL;
	char *token = NULL;
	int i = 0;
	int capacity = 10;

	if (str == NULL)
		return (NULL);

	tokens = malloc(sizeof(char *) * capacity);
	if (tokens == NULL)
		return (NULL);

	token = strtok(str, delim);
	while (token != NULL)
	{
		tokens[i] = token;
		i++;

		/** no realloc
		 * 	char **temp = NULL;
		if (i >= capacity - 1)
		{
			capacity += 10;
			temp = realloc(tokens, sizeof(char *) * capacity);
			if (temp == NULL)
			{
				return (NULL);
			}
			tokens = temp;
		}
		*/
		token = strtok(NULL, delim);
	}

	tokens[i] = NULL;
	if (token_count != NULL)
	{
		*token_count = i;
	}
	return (tokens);
}
