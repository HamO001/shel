#ifndef MAIN_H
#define MAIN_H
#include <stdbool.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#define MAX_BUFFER_SIZE 1024
char *_strcpy(char *dest, char *src);
int _strlen(char *s);
char **split_string(char *str, char *sep, int *wcount);
void _execute(char *args, struct stat *statbuffer, char **envp);
bool check_executable(char *pathname, struct stat *statbuffer);
char *get_location(char *command);
#endif
