#include "shell.h"

/**
 * _getenv - obtains value of specified environment variable
 * @variable: name of the variable
 *
 * Return: value of specified environment or NULL
 */

char *_getenv(char *variable)
{
	char *tmp;
	char *key;
	char *value;
	char *env;
	int i;

	for (i = 0; environ[i]; i++)
	{
		tmp = _strdup(environ[i]);
		key = strtok(tmp, "=");
		if (_strcmp(key, variable) == 0)
		{
			value = strtok(NULL, "\n");
			env = _strdup(value);
			free(tmp);
			return (env);
		}
		free(tmp), tmp = NULL;
	}
	return (NULL);
}
