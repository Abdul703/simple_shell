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

	if (strcmp(command, "env") == 0)
	{
		print_env(argenv);
		return;
	}

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

/**
 * print_env - print the environment variables
 *
 * @argenv: array of enviroment variables
 *
 * Return: void
*/
void print_env(char *argenv[])
{
	int i = 0;

	while (argenv[i] != NULL)
	{
		printf("%s\n", argenv[i]);
		i++;
	}	
}
