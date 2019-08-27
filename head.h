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
void _puts(char *str);
int _putchar(char c);
char *_strcpy(char *, char *);
char *rm_enter(char *);
int _strcmp(char *s1, char *s2);
int _atoi(char *);

/* ARGC | ARGV | FREE | EXEC */
int new_argc(char *);
char **new_argv(int, char *);
void free_grid(char **, int);
void exec(char **, char *, int);
void str_def(char **, char*, int);
void new_proccess(char **, char *, int);

#endif
