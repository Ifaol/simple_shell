#include "shell.h"
/**
 *builtin_func - a builtin command executer functio
 *@args: array of pointers of user input
 *@i: int value for builtin funcs
 *@count: no of command count
 *@argv: input string array
 *
 *Return: -1 on sucessful and o else
 */
int builtin_func(char **args, int i, int count, char **argv)
{
int status;
switch (i)
{
case 0:
_puts("cd command executed\n");
token_free(args);
status = -1;
break;
case 1:
status = my_env(args);
break;
case 2:
_puts("setenv command executed\n");
token_free(args);
status = -1;
break;
case 3:
_puts("unsetenv command executed\n");
token_free(args);
status = -1;
break;
case 4:
status = my_exit(args, count, argv);
break;
default:
status = -1;
break;
}
return (status);
}
