#ifndef MAIN_H
#define MAIN_H

#define MAX_COMMAND_LENGTH 1024

void handle_command(char *command, char *argenv[]);
void print_env(char *argenv[]);
void process_command(char *command, char *argenv[]);

#endif
