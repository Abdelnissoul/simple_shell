#include "shell.h"

int is_builtin(char *command)
{
	char *builtin[] = {
		"exit", "env", "setenv", "cd", NULL
	};
	int i;

	for (i = 0; builtin[i]; i++)
	{
		if (strcmp(command, builtin[i]) == 0)
			return (1);
	}
	return (0);
}

void handle_builtin(char **command, char **av, int *status, int idx)
{
	
	if (_strcmp(command[0], "exit") == 0)
		exit_shell(command, av, status, idx);

	else if (_strcmp(command[0], "env") == 0)
		print_env(command, status);
}

void exit_shell(char **command, char **av, int *status, int idx)
{
	int exit_value = (*status);
	char *index, msg[] = "exit: illegal number: ";

	if (command[1])
	{
		if (is_positive_number(command[1]))
		{
			exit_value = atoi(command[1]);
		}
		else
		{
			index = _itoa(idx);
			write(STDERR_FILENO, av[0], _strlen(av[0]));
			write(STDERR_FILENO, ": ", 2);
			write(STDERR_FILENO, index, _strlen(index));
			write(STDERR_FILENO, msg, _strlen(msg));
			write(STDERR_FILENO, command[1], _strlen(command[1]));
			write(STDERR_FILENO, "\n", 1);
			free_2d(command);
			free(index);
			(*status) = 2;
			return;
		}
	}
	free_2d(command);
	exit(exit_value);
}

void print_env(char **command, int *status)
{
	int i;

	for (i = 0; environ[i]; i++)
	{
		write(STDOUT_FILENO, command[i], _strlen(command[i]));
		write(STDOUT_FILENO, "\n", 1);
	}
	free_2d(command);
	(*status) = 0;
}
