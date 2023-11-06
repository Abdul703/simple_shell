#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "main.h"

void handle_command(char *command, char *argenv[])
{
    char *command_splits = strtok(command, " ");

    if (execve(command_splits[1], command_splits, NULL) == -1)
    {
        perror("error");
        exit(1);
    }

}

/**
 * main - Entry point
 *
 * Return: always 0 for success
*/
int main(int args, char *argv[], char *argenv[])
{
    char *command = NULL;
    char *newline;
    size_t command_length = 0;

    printf("$ ");

    while (getline(&command, &command_length, stdin) != -1)
    {

        /* replace newline with null terminator */
        newline = strchr(command, '\n');
        if (newline)
            *newline = '\0';

        /* call function that handle command */
        handle_command(command, argenv);

        printf("$ ");
    }

    putchar('\n');
    free(command);
    return (0);
}

