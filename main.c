#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "main.h"

void handle_command(char *command)
{
    char *args[] = {"/bin/ls", "-l", NULL};

    execve(command, args, NULL);
    fflush(stdout);
}

/**
 * main - Entry point
 *
 * Return: always 0 for success
*/
int main()
{
    char *command = NULL;
    char *newline;
    size_t command_length = 0;

    while (1)
    {
        printf("$ ");

        if (getline(&command, &command_length, stdin) == -1)
        {
            perror("getline");
            exit(1);
        }

        /* remove newline */
        newline = strchr(command, '\n');
        if (newline)
            *newline = '\0';

        /* call function that handle command */
        handle_command(command);
    }

    free(command);
    return (0);
}

