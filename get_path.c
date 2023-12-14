#include "shell.h"

/**
 * get_path - locates full path of an exec program
 * @input: command or program to find
 *
 * Return: path of exec if found, or NULL
 */

char *get_path(char *input)
{
	char *env_path, *full_cmd, *dir;
	struct stat st;

	if (!input || !input[0])
		return (NULL);
	if (strchr(input, '/'))
	{
		if (stat(input, &st) == 0)
		{
			return (_strdup(input));
		}
		return (NULL);
	}
	env_path = _getenv("PATH");

	if (!env_path)
		return (NULL);

	dir = strtok(env_path, ":");
	while (dir)
	{
		full_cmd = malloc(_strlen(dir) + _strlen(input) + 2);
		if (full_cmd)
		{
			_strcpy(full_cmd, dir);
			_strcat(full_cmd, "/");
			_strcat(full_cmd, input);
			if (stat(full_cmd, &st) == 0)
			{
				free(env_path);
				return (full_cmd);
			}
			free(full_cmd);
		}
		dir = strtok(NULL, ":");
	}
	free(env_path);
	return (NULL);
}
