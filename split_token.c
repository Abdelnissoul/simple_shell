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
	tokens = strtok(input, " \t\n");
	
	for (count = 0; tokens; count++)
	{
		tokens = strtok(NULL, " \t\n");
	}
	free(input);
	buffer = malloc(sizeof(char *) * (count + 1));
	if (!buffer)
	{
		free(input);
		return (NULL);
	}

	tokens = strtok(input, " \t\n");
	
	while (tokens)
	{
		buffer[a++] = tokens;
		tokens = strtok(NULL, " \t\n");
	}
	free(input);
	buffer [a] = NULL;

	return (buffer);
}
