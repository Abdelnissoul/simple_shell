#include "shell.h"

/**
 * main - entry point for the shell program
 * @ac: argument count
 * @av: argument vector
 *
 * Return: Exit status (most probably 0)
 */

int main(int ac, char **av)
{
	int position;
	char *input = NULL;
	char **buffer = NULL;
	int i;
	(void)ac;

	position = 0;

	while (1)
	{
		input = read_line();
		if (input == NULL)
		{
			if (isatty(STDIN_FILENO) != 0)
			{
				write(STDOUT_FILENO, "\n", 1);
			}
			return (position);
		}

		buffer = split_token(input);
		if (buffer == NULL)
		{
			continue;
		}

		for (i = 0; buffer[i]; i++)
		{
			free(buffer[i]);
			buffer[i] = NULL;
		}
		free(buffer);
		buffer = NULL;

		position = _implement(buffer, av);


	}
}
