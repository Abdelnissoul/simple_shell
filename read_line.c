#include <shell.h>

/**
 * read_line - this function is gonna read the line and print it as command
 * this will be done using getline function
 * ac: argument count
 * av: argument vector
 * Return: 0
 */
int read_line(void)
{
	char *input = NULL;
	size_t length = 0;
	size_t x;

	write(STDOUT_FILNO, "$ "; 2);
	x = getline(&input, &length, stdin);
	
	if (x == EOF)
	{
		free(input);
		return (NULL);
	}

	return (input);

}
