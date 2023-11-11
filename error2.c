#include "shell.h"
/**
 *print_error2 - prints an error message on stderr
 *
 *@argv: name of the executable
 *@count: counter of errors
 *@av: name of the command
 */
void print_error2(char **argv, int count, char **av)
{
write(2, *av, _strlen(*av));
write(2, ": ", 2);
write_integer_error(count);
write(2, ": ", 2);
write(2, *argv, _strlen(*argv));
write(2, ": ", 2);
write(2, "Illegal number: ", 16);
write(2, argv[1], _strlen(argv[1]));
write(2, "\n", 1);
}
