/*header files*/
#include "main.h"

/**
 * main - main function
 * @argc: argument count
 * @argv: array containing arguments
 * @env: environment the program runs in
 * Return: 0
 */
int main(int argc __attribute__((unused)), char *argv[] __attribute__((unused)), char **env)
{
	char *buffer = NULL, *prompt = "$ ";
	size_t buff_size = 0;
	ssize_t bytes = 0;
	int wait_status;
	pid_t wpid;
	bool pipe = false;
	struct stat statbuffer;
	char *directory;


	while (true && !pipe)
	{
		if (isatty(STDIN_FILENO) == 0)
			pipe = true;

		write(STDOUT_FILENO, prompt, 2);
		bytes = _getline(&buffer, &buff_size, stdin);
		if (bytes == -1)
		{
			perror("Error no line");
			free(buffer);
			exit(EXIT_FAILURE);
		}
		else
		{
			if (buffer[bytes - 1] == '\n')
			{
				buffer[bytes - 1] = '\0';
			}
		}
		if (_strcmp(buffer, "exit") == 0)
		{
			break;
		}
		if (_strncmp(buffer, "cd", 2) == 0)
		{
			directory = buffer + 3;
			if (chdir(directory) != 0)
				perror("cd");
			continue;
		}
		wpid = fork();
		if (wpid == -1)
		{
			perror("child process not created");
			exit(EXIT_FAILURE);
		}
		if (wpid == 0)
		{
			_execute(buffer, &statbuffer, env);
		}
		if (waitpid(wpid, &wait_status, 0) == -1)
		{
			perror("Error wait for child process to finish");
			exit(EXIT_FAILURE);
		}
	}
	free(buffer);
	return (0);
}
/**
 * _execute - function to execute chirld process
 * @args: pointer to memory with arguments
 * @statbuffer: pointer to memory statbuffer
 * @envp: the environment to run the commands
 * Return: void
 */
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
