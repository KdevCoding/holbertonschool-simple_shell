#include "main.h"

/**
 * _getenv - Function to locate a specific environment variable.
 * @name: Name of the environment variable.
 * Return: Pointer to the value string, else NULL.
 */
char *_getenv(const char *name)
{
	int i;
	size_t len = strlen(name);

	/* Loop through the environment strings until we hit a NULL*/
	for (i = 0; environ[i] != NULL; i++)
	{
		/* Match variable name with the = sign. */
		if (strncmp(environ[i], name, len) == 0 && environ[i][len] == '=')
			return (environ[i] + len + 1);
	}
	return (NULL);
}

/**
 * find_path - Resolve a command token into a valid binary path.
 * @command: The user command token to search for.
 * Return: Heap-allocated path on success, else NULL.
 */
char *find_path(char *command)
{
	char *path_env, *path_copy, *token, *full_path;
	size_t path_len;

	/* Skip path searching if command is already explicit. */
	if (command[0] == '/' || command[0] == '.')
	{
		/* Check file visibility and execution status. */
		if (access(command, X_OK) == 0)
			return (strdup(command));
		return (NULL);
	}
	path_env = _getenv("PATH");
	if (!path_env || strlen(path_env) == 0)
		return (NULL);
	/* Duplicate environment string. */
	path_copy = strdup(path_env);
	token = strtok(path_copy, ":");
	/* Calculate the memory. */
	while (token != NULL)
	{
		path_len = strlen(token) + strlen(command) + 2;
		full_path = malloc(path_len);
		if (!full_path)
		{
			free(path_copy);
			return (NULL);
		}
		/* Stitch tokens into uniform test paths. */
		sprintf(full_path, "%s/%s", token, command);
		/* Verify binary file status inside current directory. */
		if (access(full_path, X_OK) == 0)
		{
			free(path_copy);
			return (full_path);
		}
		free(full_path);
		token = strtok(NULL, ":");
	}
	free(path_copy);
	return (NULL);
}
