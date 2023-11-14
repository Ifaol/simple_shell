#include "shell.h"
/**
*_memset - a custom memset function
*@ptr: buffer to be setted
*@ch: char byte value that is setted
*@n: no of chars to be setted
*
*Return: setted char pointer of the strings
*/
char *_memset(char *ptr, char ch, unsigned int n)
{
unsigned int i;
char *temp = ptr;
for (i = 0 ; i < n ; i++)
{
*ptr = ch;
ptr++;
}
return (temp);
}

