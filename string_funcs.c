#include "shell.h"

/*
 * _strlen - returns the length of a string
 * @str: the string to be checked
 * Return: length of the string, otherwise 0 (F)
 */
int _strlen(char *str)
{
	int a = 0;

	if (!str)
	{
		return (0);
	}
	while (*str++)
	{
		a = a + 1;
	}
	return (a);
}

/**
 * _strcmp - it compares between two strings
 * @str1: first string
 * @str2: second one
 * Return: compare
 */
int _strcmp(char *str1, char *str2)
{
	int compare;

	while (*str1 && (*str1 == *str2))
	{
		str1 = str1 + 1;
		str2 = str2 + 1;
	}
	compare = (int)(*str1) - (int)(*str2);

	return (compare);
}

/**
 * _strcat - it concatenates two strings
 * @dest: destination
 * @src: the source
 * Return: pointer of destination.
 */
char *_strcat(char *dest, char *src)
{
	char *ptr = dest;

	while (*dest)
	{
		dest = dest + 1;
	}
	while (*src)
	{
		*ptr++ = *src++;
	}
	*dest = *src;

	return (ptr);
}
/**
 * _strcpy - copy the string
 * @dest: destination
 * @src: source
 * Return: destination pointer
 */
char *_strcpy(char *dest, char *src)
{
	int a;

	a = 0;
	if (dest == src || src == 0)
	{
		return (dest);
	}
	while (src[a])
	{
		a = a + 1;
	}
	dest[a] = 0;

	return (dest);
}

/**
 * _strdup - duplicating the string
 * @str: string ti be duplicated
 * Return: ptr of duplicated string
 */
char *_strdup(const char *str)
{
	char *ptr;
	int a;
	int length;

	length = 0;

	if (str == NULL)
	{
		return (NULL);
	}
	while (*str)
	{
		length = length + 1;
		str = str + 1;
	}
	str = str - length;

	ptr = malloc(sizeof(char) * (length + 1));

	if (ptr == NULL)
	{
		return (NULL);
	}
	a = 0;
	while (a <= length)
	{
		ptr[a] = str[a];
		a = a + 1;
	}
	return (ptr);
}
