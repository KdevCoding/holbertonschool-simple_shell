#ifndef _main_h_
#define _main_h_

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

char **readline(int *token_count, char **input_buffer);
int forkexec(char **args);
char **stringsplit(char *str, const char *delim, int *token_count);

#endif /*_main_h_*/
