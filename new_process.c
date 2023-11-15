#include "shell.h"
/**
*new_process - create a new process
*@args: array of strings that contains the command and its flags
*@argv: args vector
*@count: int counter
*
*Return: -1 if success, 0 otherwise.
*/
int new_process(char **args, char **argv, int count)
{
pid_t pid;
int status, state = 0;
char *path = NULL;
if (_strncmp(args[0], "./", 2) == 0)
state = 1;
if ((_strncmp(args[0], "/bin", 4) == 0) || (state == 1))
{
return (new_process_two(args, argv, count));
}
else
path = find_inside_path(args, argv, count);
if (path == NULL)
return (127);
if (path != NULL)
{
pid = fork();
if (pid == 0)
{
if (execve(path, args, environ) == -1)
{
print_error(argv, count, args);
free(path), token_free(args), exit(EXIT_FAILURE);
}
}
else if (pid < 0)
{
print_error(argv, count, args), free(path), token_free(args);
exit(EXIT_FAILURE);
}
else
{
do {
waitpid(pid, &status, WUNTRACED);
} while (!WIFEXITED(status) && !WIFSIGNALED(status));
}
free(path), token_free(args);
}
return (status);
}
