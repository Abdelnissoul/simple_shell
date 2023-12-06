#include "shell.h"
/**
 * split_token - function that takes only the token and split them 
 * without considering spaces and tabs
 * @input: input line or message
 * Return: 0 most probably
*/
char **split_token(char *input)
{
	int count;
	char *tokens = NULL;
	char **buffer = NULL;
	char *dup = NULL;
	int a = 0;

	count = 0;


	if (!input)
	{
		return (NULL);
	}

	dup = _strdup(input);
	tokens = strtok(dup, " \t\n");

	if (tokens == NULL)
	{
		free(input);
		input = NULL;
		free(dup);
		dup = NULL;
		return (NULL);
	}

	while (tokens)
	{
		count = count + 1;
		tokens = strtok(NULL, " \t\n");
	}

	free(dup);
	dup = NULL;

	buffer = malloc(sizeof(char *) * (count + 1));
	if (!buffer)
	{
		free(input);
		input = NULL;
		return (NULL);
	}

	tokens = strtok(input, " \t\n");

	while (tokens)
	{
		buffer[a] = _strdup(tokens);
		tokens = strtok(NULL, " \t\n");
		a = a + 1;
	}

	free(input);
	input = NULL;
	buffer [a] = NULL;

	return (buffer);
}
