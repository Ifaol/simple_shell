#include "shell.h"
/**
*split_line2 - a func that splits a string into multiple strings
*@line: string to be splited
*@deli: delimiter characters string
*
*Return: pointer that points to the new array
*/
char **split_line2(char *line, char *deli)
{
char *token = NULL, *line_copy = NULL, **tokens = NULL, *line_copy2 = NULL;
int count = 0, len = 0, i = 0;
line_copy = _strdup(line);
if (line_copy == NULL)
{
perror("_strdup");
return (NULL);
}
token = strtok(line_copy, deli);
for (count = 0 ; token != NULL ; count++)
{
token = strtok(NULL, deli);
}
tokens = (char **)malloc(sizeof(char *) * (count + 1));
if (tokens == NULL)
{
perror("malloc"), free(line_copy);
return (NULL);
}
line_copy2 = _strdup(line);
if (line_copy2 == NULL)
{
perror("_strdup"), free(line_copy);
return (NULL);
}
token = strtok(line_copy2, deli);
for (i = 0 ; token != NULL ; i++)
{
len = _strlen(token);
tokens[i] = (char *)malloc(sizeof(char) * (len + 1));
if (tokens[i] == NULL)
{
perror("malloc"), free(line_copy), free(line_copy2), token_free(tokens);
return (NULL);
}
_strcpy(tokens[i], token);
token = strtok(NULL, deli);
}
tokens[i] = NULL, free(line_copy), free(line_copy2);
return (tokens);
}
