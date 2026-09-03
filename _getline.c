#include "main.h"

/**
 * remall - expands buffer if over cap
 * @lineptr: pointer to the input buffer
 * @n: pointer to the buffer capacity
 * @new_line: extra buffer to write to
 * @count: size of lineptr
 *
 */
void remall(size_t *n, char **new_line, size_t *count, char **lineptr)
{
	size_t i;

	*n *= 2;
	new_line = malloc(*n);
	if (!new_line)
		return;
	i = 0;
	while (i < *count)
	{
		*new_line[i] = (*lineptr)[i];
		i++;
	}
	free(*lineptr);
	*lineptr = *new_line;
}
/**
 * _getline - reads one line from a stream
 * @lineptr: pointer to the input buffer
 * @n: pointer to the buffer capacity
 * @stream: stream to read from
 * Return: number of characters read, or -1 on EOF/error
 */
ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
	char c;
	char *new_line;
	int res;
	size_t count = 0;

	if (!lineptr || !n || !stream)
		return (-1);
	if (!*lineptr)
	{
		*n = 128;
		*lineptr = malloc(*n);
		if (!*lineptr)
			return (-1);
	}
	res = read(0, &c, 1);
	while (res >= 0)
	{
		if (res == 0)
		{
			printf("\n");
			break;
		}
		if (count + 1 >= *n)
		{
			remall(n, &new_line, &count, lineptr);
		}
		(*lineptr)[count++] = c;
		if (c == '\n')
			break;
		res = read(0, &c, 1);
	}
	if (count == 0 && c == EOF)
		return (-1);
	(*lineptr)[count] = '\0';
	return ((ssize_t)count);
}
