#include "shell.h"
/**
 * _implement - it will execute the program
*/
int _implement(char **buffer, char **av)
{
	pid_t fork_child;
	int position;

	fork_child = fork();

	if (fork_child == 0)
	{
		if (execve(buffer[0], buffer,env) == -1)
		{
			perror(av[0]);
			free(buffer[0]);
		}
	}
	else
	{
		waitpid(fork_child, &position, 0);
		free(buffer[0]);
	}
	return(WEXITSTATUS(position));
}
