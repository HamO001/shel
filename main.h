#ifndef MAIN_H
#define MAIN_H
#include <stdbool.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#define MAX_BUFFER_SIZE 1024
char *_strcpy(char *dest, char *src);
int _strlen(char *s);
char **split_string(char *str, char *sep, int *wcount);
void _execute(char *args, struct stat *statbuffer, char **envp);
char *get_location(char *command);
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);
int _strcmp(char *s1, char *s2);
char *_strcat(char *dest, char *src);
char *_strdup(const char *str);
char *_strtok(char *str, const char *delim);
int _strncmp(char *str1, const char *str2, size_t num);
char *_strchr(char *s, char c);
int setenv(const char *name, const char *value, int overwrite);
int unsetenv(const char *name);
#endif
