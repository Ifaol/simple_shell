#include "shell.h"
/**
*read_line - a function that reads from the stdin
*
*Return: pointer to an input string
*/
char *read_line(void)
{
char *line = NULL;
line = _getline();
if (line == NULL)
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
}
}
return (line);
}

