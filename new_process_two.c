#include "shell.h"
/**
*new_process_two - create a new process
*@args: array of strings that contains the command and its flags
*@argv: args vector
*@count: int counter
*
*Return: -1 if success, 0 otherwise.
*/
int new_process_two(char **args, char **argv, int count)
{
pid_t pid;
int status;
char *path = args[0];
pid = fork();
if (pid == 0)
{
if (execve(path, args, environ) == -1)
{
print_error(argv, count, args);
token_free(args);
exit(127);
}
}
else if (pid < 0)
{
perror("fork"), token_free(args);
exit(EXIT_FAILURE);
}
else
{
do {
waitpid(pid, &status, WUNTRACED);
} while (!WIFEXITED(status) && !WIFSIGNALED(status));
}
token_free(args);
return (WEXITSTATUS(status));
}
