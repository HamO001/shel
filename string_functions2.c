/* header files */
#include "main.h"

/**
 * _strchr - function to locate character in a string
 * @s: the string
 * @c: the character to search for
 * Return: string with the character found or NUll if not
 */
char *_strchr(char *s, char c)
{

	while (*s != '\0')
	{
		if (*s == c)
		{
			return (s);
		}
		s++;
	}
	return (0);
}
/**
 * _strncmp - function to compare n chars in str 1 and 2
 * @str1: the first string
 * @str2: the second string
 * @num: number of bits to compare
 * Return: 0 if string matches -if not
 */
int _strncmp(char *str1, const char *str2, size_t num)
{
	size_t i;

	for (i = 0; i < num; i++)
	{
		if (str1[i] != str2[i])
		{
			return ((unsigned char)str1[i] - (unsigned char)str2[i]);
		}
		else if (str1[i] == '\0')
		{
			return (0);
		}
	}
	return (0);
}
