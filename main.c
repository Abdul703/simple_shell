#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "main.h"


/**
 * main - Entry point
 *
 * @args: number of arguments pass during program call
 * @argv: array of arguments passed
 * @argenv: evironments variables
 *
 * Return: always 0 for success
*/
int main(int args, char *argv[], char *argenv[])
{
	char *command = NULL;
	char *newline;
	size_t command_length = 0;
	pid_t child_process;
	int status;
	(void)args;
        (void)argv;

	printf("$ ");

	while (getline(&command, &command_length, stdin) != -1)
	{

		/* replace newline with null terminator */
		newline = strchr(command, '\n');
		if (newline)
			*newline = '\0';


		child_process = fork();
		if (child_process == -1)
		{
			perror("Error:");
			exit(1);
		}
		if (child_process == 0)
		{
			handle_command(command, argenv);
		}
		else
		{
			wait(&status);
		}

		printf("$ ");
	}

	putchar('\n');
	free(command);
	return (0);
}

