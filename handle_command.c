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
	if (strchr(command, '/'))
	{
		execute_full_path(command, argenv);
	}
	else
	{
		char *path = getenv("PATH");
		char *path_copy = strdup(path);
		char *directory = strtok(path_copy, ":");
		char command_path[COMMAND_PATH_LENGTH];

		while (directory != NULL)
		{
			snprintf(command_path, sizeof(command_path), "%s/%s", directory, command);

			if (access(command_path, X_OK) != -1)
			{
				execute_full_path(command_path, argenv);
				free(path_copy);
				return;
			}

			directory = strtok(NULL, ":");
		}

		free(path_copy);
		printf("Command not found: %s\n", command);
	}
}

/**
 * execute_full_path - creating a child process for command execution
 *
 * @command: command to execute
 * @argenv: environments variables
 *
 * Return: void
 */
void execute_full_path(char *command, char *argenv[])
{
	pid_t child_process = fork();

	if (child_process == -1)
	{
		perror("fork");
		exit(1);
	}
	else if (child_process == 0)
	{
		process_command(command, argenv);
		exit(0);  /* Make sure child process exits after executing the command */
	}
	else
	{
		waitpid(child_process, NULL, 0);
	}
}

/**
 * process_command - process the command entered by user
 *
 * @command: command to process
 * @argenv: environments variables
 *
 * Return: void
*/
void process_command(char *command, char *argenv[])
{
	int i;
	char *argv[MAX_COMMAND_LENGTH];

	/* Create an array to store the command and its arguments. */
	argv[0] = strtok(command, " ");
	for (i = 1; i < (MAX_COMMAND_LENGTH - 1); i++)
	{
		argv[i] = strtok(NULL, " ");
		if (argv[i] == NULL)
		{
			break;
		}
	}
	argv[i] = NULL;

	if (execve(argv[0], argv, argenv) == -1)
	{
		perror("execve");
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

