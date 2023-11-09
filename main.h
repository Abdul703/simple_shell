#ifndef MAIN_H
#define MAIN_H

#define MAX_COMMAND_LENGTH 1024

void handle_command(char *command, char *argenv[]);
void print_env(char *argenv[]);

#endif
