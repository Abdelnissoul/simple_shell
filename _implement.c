#include "shell.h"

/**
 * _implement - it will execute the program
 * @buffer: 2D array represent the command line
 * @av: 2d argument vector
 * Return: exit the position
 */

int _implement(char **buffer, char **av)
{
	pid_t fork_child;
	int position;
	int exit_position;
	char *full_cmd;

	full_cmd = get_path(buffer[0]);
	if (full_cmd)
	{
		printerror();

		return();
	}

	fork_child = fork();

	if (fork_child == 0)
	{
		if (execve(full_cmd, buffer, environ) == -1)
		{
			free(full_cmd), full_cmd = NULL;
			free_2d(buffer);
		}
	}
	else
	{
		waitpid(fork_child, &position, 0);
		free_2d(buffer);
		free(full_cmd), full_cmd = NULL;
	}
	exit_position = WEXITSTATUS(position);
	return (exit_position);
}
