#include "shell.h"

/**
 * split_token -tokenizes input, separating tokens by spaces and tabs
 * @input: input line or message
 *
 * Return: buffer containing the tokens passed from input or NULL
 */

char **split_token(char *input)
{
	int count = 0, a = 0;
	char *tokens = NULL, *dup = NULL, **buffer = NULL;

	if (!input)
		return (NULL);
	dup = _strdup(input);
	tokens = strtok(dup, DELIM);
	while (tokens)
	{
		count++;
		tokens = strtok(NULL, DELIM);
	}
	free(dup), dup = NULL;

	buffer = malloc(sizeof(char *) * (count + 1));
	if (!buffer)
	{
		free(input);
		return (NULL);
	}
	tokens = strtok(input, DELIM);
	while (tokens)
	{
		buffer[a] = _strdup(tokens);
		if (!buffer[a])
		{
			while (a > 0)
			{
				free(buffer[a - 1]);
				a--;
			}
			free(buffer), free(input);
			return (NULL);
		}
		tokens = strtok(NULL, DELIM);
		a++;
	}
	free(input);
	buffer[a] = NULL;
	return (buffer);
}
