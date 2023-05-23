#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **split_string(char *str, char *sep, int *wcount)
{
int max_tokens = _strlen(str) / 2 + 1;
char **argv = (char **)malloc(max_tokens * sizeof(char *));
int count = 0;
int i;
char *token = strtok(str, sep);

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

token = strtok(NULL, sep);
}
*wcount = count;
return (argv);
}

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
