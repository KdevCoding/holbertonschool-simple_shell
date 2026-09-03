#include "main.h"

/**
 * _getline - reads one line from a stream
 * @lineptr: pointer to the input buffer
 * @n: pointer to the buffer capacity
 * @stream: stream to read from
 * Return: number of characters read, or -1 on EOF/error
 */
ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
	int c;
	char *new_line;
	size_t i;
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
	while ((c = fgetc(stream)) != EOF)
	{
		if (count + 1 >= *n)
		{
			new_line = malloc(*n * 2);
			if (!new_line)
				return (-1);
			i = 0;
			while (i < count)
			{
				new_line[i] = (*lineptr)[i];
				i++;
			}
			free(*lineptr);
			*lineptr = new_line;
			*n *= 2;
		}
		(*lineptr)[count++] = (char)c;
		if (c == '\n')
			break;
	}
	if (count == 0 && c == EOF)
		return (-1);
	(*lineptr)[count] = '\0';
	return ((ssize_t)count);
}
