#include "shell.h"
/**
 * main - this is the main code of the shell project
 * ac: argument count
 * av: argument vector
 * 
 * Return: 0 most probably
*/
int main(int ac, char **av)
{
	int position;
	char *input = NULL;
	char **buffer = NULL;
	int i;
	(void)ac;
	(void)av;

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
			printf("%s\n", buffer[i]);
			free(buffer[i]);
			buffer = NULL;
		}
		free(buffer);
		buffer = NULL;

		/*position = _implement(buffer, av); */
	}
}
