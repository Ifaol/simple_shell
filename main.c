#include "shell.h"
/**
*main -function that checks input type and calls apropriate functions
*@argc: no of args intered
*@argv: args vector
*
*Return: 0 on success
*/
int main(int argc, char *argv[])
{
int fd_type = isatty(STDIN_FILENO);
if (fd_type == 1 && argc != 0)
{
interactive(argv);
}
else
{
non_interactive(argv);
}
return (0);
}

