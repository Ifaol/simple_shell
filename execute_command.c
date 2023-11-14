#include "shell.h"
/**
*execute_command - select functions for execution
*@args: command and its flags
*@argv: args vector
*@count: int counter
*
*Return: -1 on sucess, 0 otherwise
*/
int execute_command(char **args, char **argv, int count)
{
int i = 0;
char *builtin_func_list[] = {"cd", "env", "setenv", "unsetenv", "exit"};
if (args == NULL && args[0] == NULL)
{
return (-1);
}
for (i = 0 ; i < 5 ; i++)
{
if (_strcmp(args[0], builtin_func_list[i]) == 0)
{
return (builtin_func(args, i, count, argv));
}
}
return (new_process(args, argv, count));
}
