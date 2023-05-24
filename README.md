main.c

file contains the main function and _execute function

main 
takes command string
if command is exit it exits program
if command is cd it calls chdir function
else it forks the process and calls _execute function

_execute
calls the split_string function (split_string.c) to tokenize the string
calls get_location command (get_loc.c) to get file with wpecific command from PATH
calls execve to run the command

string_functions.c && string_functions2.c

contains various string manipulation functions
_strlen - finds length of string
_strchr - finds a character in a string
_strcpy - copies the content of a string to another string
_strdup - duplicates content of string
_strcmp - compares if a string 1 is equal to string 2
_strcat - concatenates a string 1 to string 2
_strncmp - compares n specied characters from 2 strings
