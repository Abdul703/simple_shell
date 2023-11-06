#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "main.h"

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

