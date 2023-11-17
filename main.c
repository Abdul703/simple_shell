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
	char command[MAX_COMMAND_LENGTH];
	size_t len;
	(void)args;
	(void)argv;

	while (1)
	{
		printf("$ ");
		fflush(stdout);

		if (fgets(command, sizeof(command), stdin) == NULL)
		{
			perror("error");
			exit(1);
		}

		len = strlen(command);

		/* Remove the newline character */
		if (len > 0 && command[len - 1] == '\n')
		{
			command[len - 1] = '\0';
		}

		if (strcmp(command, "exit") == 0)
		{
			break;
		}

		handle_command(command, argenv);
	}

	putchar('\n');
	return (0);
}

/**
 * free_memory - free the allocated memory befor exiting
 *
 * Return: void
 */
void free_memory(void)
{
	/* Add any necessary cleanup code here */
}

