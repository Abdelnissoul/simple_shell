#include "shell.h"

/**
 * read_line - reads a line of input and displays a command prompt
 * this will be done using getline function
 *
 * Return: a pointer to the input string entered by user
 * or NULL if EOF is encountered or an error occurs
 */

char *read_line(void)
{
	char *input = NULL;
	size_t length = 0;
	size_t x;

	if (isatty(STDIN_FILENO) != 0)/* checks if program is interactive mode */
	{
		write(STDOUT_FILENO, "$ ", 2);
	}

	x = getline(&input, &length, stdin);

	if (x == (size_t)EOF)
	{
		free(input);
		return (NULL);
	}

	return (input);

}
