#include "shell.h"
static int status_non;
/**
*non_interactive - a command line interpreter function for non_interactive way
*@argv: args vector
*
*Return: void
*/
void non_interactive(char **argv)
{
char *line;
char **args;
int count = 1;
status_non = 0;
do {
line = read_line();
if (line == NULL)
{
exit(status_non);
}
else if (is_all_spaces(line) == 1)
{
free(line);
}
else
{
args = split_line(line, " \n\t;|&'\"`(){}><");
status_non = execute_command(args, argv, count);
}
} while (1);
}
/**
 *get_status_non - Get the value of the status variable
 *
 *Return: int - the value of the status_non variable
 */
int get_status_non(void)
{
return (status_non);
}

