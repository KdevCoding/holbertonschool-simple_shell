#ifndef _main_h_
#define _main_h_

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <stdarg.h>
#include <errno.h>

extern char **environ;

/**
 * struct func - struct to pick a function to run
 * @arg: args to pick from
 * @f: function to give
 *
 *
 */
typedef struct func
{
	char *arg;
	int (*f)(char **args);
} func_t;

typedef int (*conv_t)(char **args);
conv_t func_spec(char *str);

char **readline(int *token_count, char **input_buffer);
int forkexec(char **args);
char **stringsplit(char *str, const char *delim, int *token_count);
char *_getenv(const char *name);
char *find_path(char *command);
int printenv(char **args);
int _atoi(char *s);
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);
void remall(size_t *n, char **new_line, size_t *count, char **lineptr);
int _setenv(char **args);
int _unsetenv(char **args);
#endif /*_main_h_*/
