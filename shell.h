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
int _implement(char **buffer, char **av, int idx);
char *get_path(char *input);
char *_getenv(char *name);

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

void print_error(char *name, char *cmd, int idx);
void reverse_string(char *str, int len);
char *_itoa(int n);
int _atoi(char *str);
int is_positive_number(char *str);

/* built-in commands */
int is_builtin(char *command);
void handle_builtin(char **command, char **av, int *status, int idx);
void exit_shell(char **command, char **av, int *status, int idx);
void print_env(char **command, int *status);


#endif
