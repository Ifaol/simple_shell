#include "shell.h"
/**
*is_space - a function that checkes for space input
*@c: char input
*
*Return: 1 if space and 0 else
*/
int is_space(char c)
{
int s = 0;
if ((c == '\r' || c == '\f' || c == '\v'))
{
s = 1;
}
if ((c == ' ' || c == '\t' || c == '\n' || s == 1))
{
return (1);
}
return (0);
}
/**
*is_all_spaces - a function that checkes if input string is all space
*@str: input string
*
*Return: 1 if all space and 0 else
*
*/
int is_all_spaces(char *str)
{
int i = 0;
while (str[i] != '\0')
{
if (is_space(str[i]) == 0)
return (0);
i++;
}
return (1);
}

