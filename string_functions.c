/*header files*/
#include "main.h"

/**
 * _strlen - function to find length of string
 * @s: parameter passed to _strlen
 * Return: length
 */
int _strlen(char *s)
{
	int length = 0;

	while (s[length] != '\0')
	{
		length++;
	}
	return (length);
}
/**
 * _strcpy - function to copy content of string to new memory location
 * @dest: destination memory
 * @src: source string
 * Return: 0
 */
char *_strcpy(char *dest, char *src)
{

	int i, j;
	int length = 0;

	for (i = 0; src[i] != '\0'; i++)
		length++;

	for (j = 0; j <= length; j++)
		dest[j] = src[j];
	return (dest);
}
/**
 * *_strcat - function to concatenate two strings
 * @dest: destination string
 * @src: source string
 * Return: destination string
 */
char *_strcat(char *dest, char *src)
{
	int i, j;

	i = 0;
	while (dest[i] != '\0')
		i++;
	j = 0;
	while (src[j] != '\0')
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';

	return (dest);
}
/**
 * _strcmp - function to compare two strings
 * @s1: first string to compare
 * @s2: second string to compare
 * Return: value of comparison
 */
int _strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
		{
			return (s1[i] - s2[i]);
		}
		i++;
	}
	return (0);
}
/**
 * _strdup - function to duplicate string
 * @str: string to duplicate
 * Return: new_string
 */
char *_strdup(const char *str)
{
	size_t len = strlen(str) + 1;
	char *new_str = malloc(len);

	if (new_str != NULL)
	{
		memcpy(new_str, str, len);
	}
	return (new_str);
}
