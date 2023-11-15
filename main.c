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
	(void)args;
	(void)argv;

	printf(":) ");

	while (getline(&command, &command_length, stdin) != -1)
	{
		newline = strchr(command, '\n');
		if (newline)
			*newline = '\0';

		/* Check if user typed exit */
		if (strcmp(command, "exit") == 0)
			break;

		handle_command(command, argenv);

		printf(":) ");
	}

	putchar('\n');
	free(command);
	return (0);
}
