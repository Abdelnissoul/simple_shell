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
	int idx = 0;
	(void)ac;

	position = 0;

	while (1)
	{
		input = read_line();
		if (input == NULL)
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			return (position);
		}

		buffer = split_token(input);
		if (!buffer)
			continue;

		if (is_builtin(buffer[0]))
			handle_builtin(buffer, av, &position, idx);
		else
			position = _implement(buffer, av, idx);

	}
}
