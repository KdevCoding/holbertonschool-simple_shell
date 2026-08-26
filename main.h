<<<<<<< HEAD
#ifndef MAIN_H
#define MAIN_H

char **stringsplit(char *str, const char *delim);

#endif
=======
#ifndef _main_h_
#define _main_h_

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int readline(char **buffer);
int forkexec(char *buffer);

#endif /*_main_h_*/
>>>>>>> origin/main
