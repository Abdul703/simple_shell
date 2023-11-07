#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "main.h"

/**
 * handle_command - execute command
 *
 * @command: command to execute
 * @argenv: environment variables
 *
 * Return: void
 */
void handle_command(char *command, char *argenv[])
{
	int i;
	char *argv[MAX_COMMAND_LENGTH];

	/* Create an array to store the command and its arguments. */
	argv[0] = strtok(command, " ");
	for (i = 1; i < (MAX_COMMAND_LENGTH - 1); i++)
		argv[i] = strtok(NULL, " ");
	argv[i] = NULL;


	if (execve(argv[0], argv, argenv) == -1)
	{
		perror("error");
		exit(1);
	}

}
