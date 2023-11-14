#include "shell.h"
static int status;
/**
*interactive - a command line interpreter function in interactive way
*@argv: args vector
*
*Return: void
*/
void interactive(char **argv)
{
char *line = NULL, **args = NULL;
int count = 0;
status = 0;
do {
count++;
_puts("$ ");
line = read_line();
if (line == NULL)
{
_putchar('\n');
exit(status);
}
else if (is_all_spaces(line) == 1)
{
free(line);
}
else
{
args = split_line(line, " \n\t;|&'\"`(){}><");
status = execute_command(args, argv, count);
}
} while (1);
}
/**
 *get_status - Get the value of the status variable
 *
 *Return: int - the value of the status variable
 */
int get_status(void)
{
return (status);
}
