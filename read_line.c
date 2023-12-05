#include "shell.h"

/**
 * read_line - this function is gonna read the line and print it as command
 * this will be done using getline function
 * 
 * Return: the input of the user that will write
 */
char *read_line(void)
{
	char *input = NULL;
	size_t length = 0;
	size_t x;

	write(STDOUT_FILENO, "$ ", 2);
	x = getline(&input, &length, stdin);
	
	if (x == (size_t)EOF)
	{
		free(input);
		return (NULL);
	}

	return (input);

}
