#include "shell.h"

/**
 * split_token - function that takes only the token and split them
 * without considering spaces and tabs
 * @input: input line or message
 * Return: buffer where there is the command
 */

char **split_token(char *input)
{
	int count = 0, a = 0;
	char *tokens = NULL, *dup = NULL;
	char **buffer = NULL;

	if (!input)
		return (NULL);
	dup = _strdup(input);
	tokens = strtok(dup, " \t\n");
	if (tokens == NULL)
	{
		free(input), input = NULL;
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
		free(input), input = NULL;
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
	buffer[a] = NULL;
	return (buffer);
}
