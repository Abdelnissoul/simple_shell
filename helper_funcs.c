#include "shell.h"

/**
 * print_error - prints error message
 * @name: name or identifier of error
 * @cmd: command associated with error
 * @idx: index of command within sequence
 *
 * Return: index
 */

void print_error(char *name, char *cmd, int idx)
{
	char *index = _itoa(idx);
	char msg[] = ": command not found";

	write(STDERR_FILENO, name, _strlen(name));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, index, _strlen(index));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, cmd, _strlen(cmd));
	write(STDERR_FILENO, msg, _strlen(msg));

	free(index);
}

/**
 * reverse_string - reverses a string of characters
 * @str: string to be reversed
 * @len: length of the string
 *
 * Return: void
 */

void reverse_string(char *str, int len)
{
	char tmp;
	int start = 0;
	int end = len - 1;

	while (start < end)
	{
		tmp = str[start];
		str[start] = str[end];
		str[end] = tmp;
		start++;
		end--;
	}
}

/**
 * _itoa - converts integer to string value
 * @n: value that needs to be converted
 *
 * Return: pointer to a string containing ASCII representation of n
 */

char *_itoa(int n)
{
	char buffer[20];
	int i = 0;

	if (n == 0)
		buffer[i++] = '0';
	else
	{
		while (n > 0)
		{
			buffer[i++] = (n % 10) + '0';
			n /= 10;
		}
	}
	buffer[i] = '\0';
	reverse_string(buffer, i);
	return (_strdup(buffer));
}

/**
 * is_positive_number - determines if a given string is positive
 * @str: input string
 *
 * Return: 1 if positive, 0 otherwise
 */

int is_positive_number(char *str)
{
	int i;

	if (!str)
		return (0);

	for (i = 0; str[i]; i++)
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
	}
	return (1);
}

/**
 * _atoi - converts string representation to int value
 * @str: input string
 *
 * Return: integer value of string
 */

int _atoi(char *str)
{
	int i, num = 0;

	for (i = 0; str[i]; i++)
	{
		num *= 10;
		num += (str[i] - '0');
	}
	return (num);
}
