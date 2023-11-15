#include "shell.h"
/**
*read_line - a function that reads from the stdin
*
*Return: pointer to an input string
*/
char *read_line(void)
{
char *line = NULL;
size_t bufsize = 0;
if (getline(&line, &bufsize, stdin) == -1)
{
if (feof(stdin))
{
free(line);
return (NULL);
}
else
{
if (line != NULL)
{
free(line);
}
perror("error reading from stdin");
exit(EXIT_FAILURE);
}
}
return (line);
}
