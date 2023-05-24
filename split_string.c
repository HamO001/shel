#include "main.h"
/**
 * split_string - function to split command string into command and options
 * @str: the input string
 * @sep: the separator used in command
 * @wcount: length of command
 * Return: the string split into tokens
 */
char **split_string(char *str, char *sep, int *wcount)
{
	int max_tokens = _strlen(str) / 2 + 1;
	char **argv = (char **)malloc(max_tokens * sizeof(char *));
	int count = 0;
	int i;
	char *token = _strtok(str, sep);

	if (argv == NULL)
	{
		perror("Memory allocation failed");
		*wcount = 0;
		return (NULL);
	}
	while (token != NULL)
	{
		argv[count] = (char *)malloc((_strlen(token) + 1) * sizeof(char));
		if (argv[count] == NULL)
		{
			perror("Memory allocation failed");
			for (i = 0; i < count; i++)
			{
				free(argv[i]);
			}
			free(argv);
			*wcount = 0;
			return (NULL);
		}
		_strcpy(argv[count], token);
		count++;
		token = _strtok(NULL, sep);
	}
	*wcount = count;
	return (argv);
}

