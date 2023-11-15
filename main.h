#ifndef MAIN_H
#define MAIN_H

#include <limits.h>

#define MAX_COMMAND_LENGTH 1024
#define COMMAND_PATH_LENGTH (PATH_MAX + 1)

void handle_command(char *command, char *argenv[]);
void print_env(char *argenv[]);
void process_command(char *command, char *argenv[]);

#endif
