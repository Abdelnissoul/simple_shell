#include "shell.h"

/**
 * free_2d - frees 2D array
 * @arr: array to be freed
 *
 * Return: void
 */

void free_2d(char **arr)
{
	int a;

	if (arr)
	{
		for (a = 0; arr[a] != NULL; a++)
		{
			free(arr[a]);
			arr[a] = NULL;
		}
		free(arr);
		arr = NULL;
	}
	else
		return;
}
