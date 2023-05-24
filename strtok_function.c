/* header files */
#include "main.h"
/**
 * _strtok - function to tokenize string from command
 * @str: the string to tokenize
 * @delim: the character used to space the command options
 * Return: tokens
 */

char *_strtok(char *str, const char *delim)
{
	static char *next_t;
	char *token;

	if (str != NULL)
	{

		next_t = str;
	}
	while (*next_t != '\0' && strchr(delim, *next_t) != NULL)
	{
		++next_t;
	}
	if (*next_t == '\0')
	{
		return (NULL);
	}
	token = next_t;
	while (*next_t != '\0' && strchr(delim, *next_t) == NULL)
	{
		++next_t;
	}
	if (*next_t != '\0')
	{
		*next_t++ = '\0';
	}
	return (token);
}
