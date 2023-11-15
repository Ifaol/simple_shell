#include "shell.h"
/**
*_getline - A custom getline function
*
*Return: A pointer to input string or null if error or eof
*/
char *_getline(void)
{
static char buffer[BUFFER_SIZE];
static int buffer_index, chars_read, cursor_position;
char *line = NULL;
int line_index;
chars_read = read(0, buffer, BUFFER_SIZE);
buffer_index = 0;
cursor_position = 0;
if (chars_read <= 0)
{
return (NULL);
}
line = malloc(BUFFER_SIZE);
if (line == NULL)
{
perror("malloc");
return (NULL);
}
line_index = 0;
while ((buffer_index < chars_read)&&(buffer[buffer_index] != '\n'))
{
line[line_index++] = buffer[buffer_index++];
cursor_position++;
}
if ((buffer_index < chars_read)&&(buffer[buffer_index] == '\n'))
{
line[line_index++] = buffer[buffer_index++];
cursor_position++;
}
line[line_index] = '\0';
return (line);
}
