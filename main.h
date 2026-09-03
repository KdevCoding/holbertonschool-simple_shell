#ifndef _main_h_
#define _main_h_

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

extern char **environ;

char **readline(int *token_count, char **input_buffer);
int forkexec(char **args);
char **stringsplit(char *str, const char *delim, int *token_count);
char *_getenv(const char *name);
char *find_path(char *command);
void printenv(void);
int _atoi(char *s);

#endif /*_main_h_*/
