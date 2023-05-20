/*header files*/
#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdbool.h>
#include <sys/stat.h>
#include <string.h>


int main(int argc __attribute__((unused)), char *argv[] __attribute__((unused)), char **env)
{
 
	char *buffer = NULL, *prompt = "$ ";
	size_t buff_size = 0;
	ssize_t bytes = 0;
	int wait_status;
	pid_t wpid;
	bool pipe = false;
	struct stat statbuffer;


	while (true && !pipe)
	{
		if (isatty(STDIN_FILENO) == 0)
			pipe = true;

		write(STDOUT_FILENO, prompt, 2);
		/*read data from user*/
		bytes = getline(&buffer,&buff_size, stdin);
		if (bytes == -1)
		{
			perror("Error no line");
			free(buffer);
			exit(EXIT_FAILURE);
		}
		/* read and replace newline character with terminator*/
		else
		{
			if (buffer[bytes -1] == '\n')
			{
				buffer[bytes - 1] = '\0';
			}
		}
		if (strcmp(buffer, "exit") == 0)
		{
			break;
		}
		/* create child process to handle command*/
		wpid = fork();
		if (wpid == -1)
		{
			perror("child process not created");
			exit(EXIT_FAILURE);
		}
		/*execute child process*/
		if (wpid == 0)
		{
			_execute(buffer, &statbuffer,env);
		}
		/* make parent process wait for child process */
		if (waitpid(wpid, &wait_status,0) == -1)
		{
			perror("Error wait for child process to finish");
			exit(EXIT_FAILURE);
		}
	}


	free(buffer);
	return (0);
}

void _execute(char *args, struct stat *statbuffer, char **envp)
{

	char **argv;
	int argc;
	char *command = NULL, *actual_command = NULL;


	(void)envp;
	(void)statbuffer;
	argv = split_string(args, " ", &argc);

	command = argv[0];

	actual_command = get_location(command);
	execve(actual_command, argv, envp);
	perror("error executing");
	exit(EXIT_FAILURE);

}



