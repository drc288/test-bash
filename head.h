#ifndef _HEAD_H_
#define _HEAD_H_
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#define DELIM " \t\r\n\a"

/* GET ENV */
extern char **environ;

/* FUNCTIONS STR */
int _strlen(char *);
void _puts(char *);
int _putchar(char);
char *_strcpy(char *, char *);
char *rm_enter(char *);
int _strcmp(char *, char *);
int _atoi(char *);
void print_number(int);

/* ARGC | ARGV | FREE | EXEC | ERROR */
int new_argc(char *);
char **new_argv(int, char *);
void free_grid(char **, int);
void exec(char **, char *, int, int);
void str_def(char **, char*, int);
void new_proccess(char **, char *, int);
char *split_path(char *, char *);
char *check_access(char *, char *, char *, char *);
char *add_path(char *,  char **, int, char *);
char *_strcat(char *, char *);
void sys_error(char **, int, char *);

#endif
