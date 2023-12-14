#include "shell"

/**
 * _getenv - function that gets an environment variable
 * without using getenv function
 * @name: name of the environment variable
 *
 * Return: path value or NULL
 */
char *getenv(char *name)
{
	int a = 0;
	char *dup, *ptr, *val;
	char *val_copy;

	while (environ[a])
	{
		dup = _strdup(environ[a]);
		ptr = strtok(dup, "=");

		if (_strcmp(ptr, name) == 0)
		{
			val = strtok(NULL, "\n");
			val_copy = _strdup(val);
			free(dup);
			return (val_copy);
		}
		free(dup);
		dup = NULL;
		a = a + 1;
	}
	return NULL;
}
int main()
{
	printf("%s\n", _getenv("PATH"));
	return (0);
}
