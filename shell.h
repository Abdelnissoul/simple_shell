#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <errno.h>

char *read_line(void);
char **split_token(char *input);
int _implement(char **buffer, char **av);
char *get_path(char *input);
char *_getenv(char *variable);

/* environ for execve */
extern char **environ;

/* freeing 2d arrays */
void free_2d(char **arr);

/*for strings functions */
int _strlen(char *);
int _strcmp(char *, char *);
char *_strcat(char *, char *);
char *_strcpy(char *, char *);
char *_strdup(const char *);


#endif
