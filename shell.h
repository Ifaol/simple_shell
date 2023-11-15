#ifndef SHELL_H
#define SHELL_H
/* Included heares */
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>
#include <limits.h>
#include <fcntl.h>
#include <stdarg.h>
#include <ctype.h>
/* Exeterns and variable definations */
extern char **environ;
#define BUFFER_SIZE 1024
#define MAX_INPUT_LENGTH 4096
/* Used function's prototypes */
void interactive(char **argv);
void non_interactive(char **argv);
char *read_line(void);
char _putchar(char char_to_be_written);
void _puts(char *ptr);
char *_strcpy(char *dest, char *src);
char *_strdup(const char *str);
size_t _strlen(const char *s);
char **split_line(char *line, char *deli);
char **split_line2(char *line, char *deli);
int new_process(char **args, char **argv, int count);
int new_process_two(char **args, char **argv, int count);
int _atoi(char *src);
int builtin_func(char **args, int i, int count, char **argv);
int _strcmp(const char *s1, const char *s2);
int _strncmp(const char *s1, const char *s2, size_t n);
int execute_command(char **args, char **argv, int count);
char *_strcat(char *dest, const char *src);
char *_memset(char *ptr, char ch, unsigned int n);
char *path_find(void);
char *find_inside_path(char **args, char **argv, int count);
int build_path(char *buf, char *dir, char *command);
void token_free(char **token);
int write_integer_error(int number);
void print_error(char **argv, int count, char **av);
void print_error2(char **argv, int count, char **av);
int write_integer(int number);
int my_exit(char **args, int count, char **argv);
int my_env(char **args);
int is_all_spaces(char *str);
int is_space(char c);
int convert_2range(int num);
int get_status(void);
int get_status_non(void);
char *_getline(void);
#endif
