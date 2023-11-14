#include "shell.h"
int command_check(char **args)
{
if (_strcmp(args[0], "echo") == 0)
{
if (_strcmp(args[1], "$$") == 0)
{
return (1);
}
else if (_strcmp(args[1], "$?") == 0)
{
return (2);
}
else if (_strcmp(args[1], "$PATH") == 0)
{
return (3);
}
}
else if (_strcmp(args[0], "/bin/echo") == 0)
{
if (_strcmp(args[1], "$$") == 0)
{
return (1);
}
else if (_strcmp(args[1], "$?") == 0)
{
return (2);
}
else if (_strcmp(args[1], "$PATH") == 0)
{
return (3);
}
}
return (0);
}
int var_rep(char **args)
{
pid_t my_pid = getpid();
int var_value = command_check(args);
char *path = NULL, **env = environ;
int stat = get_status(), stat_non = get_status_non();
int final_stat, i;
if (var_value == 1)
{
printf("%d", my_pid);
_putchar('\n');
token_free(args);
return (0);
}
else if (var_value == 3)
{
for (i = 0 ; env[i] != NULL ; i++)
{
if (_strncmp(env[i], "PATH=", 5) == 0)
{
path = env[i] + 5;
break;
}
}
if (path != NULL)
{
_puts(path);
_putchar('\n');
}
token_free(args);
return (0);
}
else if (var_value == 2)
{
if (stat == stat_non)
final_stat = stat;
else if (stat == 0 && stat_non != 0)
final_stat = stat_non;
else
{
final_stat = stat;
}
printf("%d", final_stat);
_putchar('\n');
token_free(args);
return (0);
}
return (0);
}

