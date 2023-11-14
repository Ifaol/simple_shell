#include "shell.h"
/**
 *find_inside_path - a function that looks for a command in PATH
 *@args: input pointer of command string to look for
 *@argv: args vector
 *@count: int counter
 *
 *Return: string containing full path on success and  NULL on failure
 */
char *find_inside_path(char **args, char **argv, int count)
{
struct stat st;
int stat_ret, i;
char buf[MAX_INPUT_LENGTH], *path, *ret, **dir, *command = args[0];
path = path_find();
if (path == NULL)
{
token_free(args);
return (NULL);
}
dir = split_line2(path, ":");
if (dir == NULL)
{
token_free(args);
return (NULL);
}
for (i = 0 ; dir[i] != NULL ; i++)
{
if (build_path(buf, dir[i], command) == 0)
{
stat_ret = stat(buf, &st);
if (stat_ret == 0 && S_ISREG(st.st_mode) && (st.st_mode & S_IXUSR))
{
token_free(dir);
ret = malloc(sizeof(char) * (_strlen(buf) + 1));
if (ret == NULL)
{
perror("malloc"), token_free(args);
return (NULL);
}
_strcpy(ret, buf);
return (ret);
}
}
}
if (stat_ret == -1)
{
print_error(argv, count, args), token_free(dir), token_free(args);
return (NULL);
}
return (NULL);
}
/**
 *build_path - Builds the full path to a command.
 *@buf: buffer to store the result.
 *@dir: directory to concatenate.
 *@command: command to concatenate.
 *
 *Return: 0 on success, -1 on failure
 */
int build_path(char *buf, char *dir, char *command)
{
if (!buf || !dir || !command)
{
return (-1);
}
_memset(buf, 0, MAX_INPUT_LENGTH);
_strcpy(buf, dir);
_strcat(buf, "/");
_strcat(buf, command);
return (0);
}
/**
 *path_find - a function that gets the environment variable
 *
 *Return: pointer of environment
 */
char *path_find(void)
{
char **env;
size_t name_len = 4;
for (env = environ ; *env != NULL ; env++)
{
if (_strncmp(*env, "PATH", name_len) == 0 && (*env)[name_len] == '=')
{
return (&(*env)[name_len + 1]);
}
}
return (NULL);
}
/**
 *token_free - a functiom that free a double pointer
 *@token: a double pointer to be freed
 *
 *Return: void
 */
void token_free(char **token)
{
int i;
if (token == NULL)
{
return;
}
for (i = 0 ; token[i] != NULL ; i++)
{
free(token[i]);
}
free(token);
token = NULL;
}
