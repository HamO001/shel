/*header files */
#include "main.h"

/**
 * _getline - function to read line from stdinput
 * @lineptr: pointer to memory location with command string
 * @n: length of command
 * @stream: stdin
 * Return: number of bytes read
 */
ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
	ssize_t characters;
	char ch;
	size_t i = 0, j = 0;
	size_t buffsize = *n;
	char *buff = *lineptr;
	char *newBuff;
	size_t newBuffSize;

	if (lineptr == NULL || n == NULL || stream == NULL)
	{
		return (-1);
	}
	if (buff == NULL || buffsize == 0)
	{
		buffsize = 1028;
		buff = (char *)malloc(buffsize);
		if (buff == NULL)
		{
			return (-1);
		}
	}

	while ((characters = read(fileno(stream), &ch, 1)) > 0)
	{
		if (i >= buffsize - 1)
		{
			newBuffSize = buffsize * 2;
			newBuff = (char *)malloc(newBuffSize);
			if (newBuff == NULL)
			{
				free(buff);
				return (-1);
			}
			for (; j < i; j++)
			{
				newBuff[j] = buff[j];
			}
			free(buff);
			buff = newBuff;
			buffsize = newBuffSize;
		}
		buff[i++] = ch;
		if (ch == '\n')
		{
			break;
		}
	}
	if (characters == -1)
	{
		free(buff);
		return (-1);
	}
	buff[i] = '\0';
	*lineptr = buff;
	*n = buffsize;

	if (i == 0 && ch == 0)
		return (-1);

	return (i);
}
