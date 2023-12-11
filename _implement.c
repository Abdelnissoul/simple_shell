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

	fork_child = fork();

	if (fork_child == 0)
	{
		if (execve(buffer[0], buffer, environ) == -1)
		{
			perror(av[0]);
			free_2d(buffer);
			exit(0);
		}
	}
	else
	{
		waitpid(fork_child, &position, 0);
		free_2d(buffer);
	}
	exit_position = WEXITSTATUS(position);
	return (exit_position);
}
