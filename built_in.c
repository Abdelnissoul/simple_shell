#include "shell.h"

/**
 * is_builtin - determines if a command is built in or not
 * @command: command to check
 *
 * Return: 1 if command is recognised, 0 if otherwise
 */

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
/**
 * handle_builtin - handles the execution of buitin commands
 * @command: command to be handled
 * @av: argument vector
 * @status: status of the command
 * @idx: position of command in sequence
 *
 * Return: NULL
 */

void handle_builtin(char **command, char **av, int *status, int idx)
{

	if (_strcmp(command[0], "exit") == 0)
		exit_shell(command, av, status, idx);

	else if (_strcmp(command[0], "env") == 0)
		print_env(command, status);
}
/**
 * exit_shell - terminates or exits the shell
 * @command: action that triggers exit
 * @av: argument vector
 * @status: status of the shell
 * @idx: position of the shell command
 *
 * Return: exit or 0
 */

void exit_shell(char **command, char **av, int *status, int idx)
{
	int exit_value = (*status);
	char *index = NULL;
	char msg[] = "exit: illegal number: ";

	if (command[1])
	{
		if (is_positive_number(command[1]))
		{
			exit_value = _atoi(command[1]);
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
			(*status) = 1;

			return;
		}
	}
	free_2d(command);
	exit(exit_value);
}

/**
 * print_env - prints environment variable within a shell
 * @command: a pointer to a string array
 * @status: status of the printing process
 *
 * Return: void
 */

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
