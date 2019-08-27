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

int _strlen(char *s);
char *_strcpy(char *dest, char *src);
int new_argc(char *str);
char **new_argv(int, char *);
void free_grid(char **, int);
char *rm_enter(char *str);
int _strcmp(char *s1, char *s2);
void exec(char **, char *, int);

#endif
