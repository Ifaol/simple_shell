#include "shell.h"
/**
 *_putchar - a custom putchar function
 *@char_to_be_written: char input
 *
 *Return: no of chars written
 */
char _putchar(char char_to_be_written)
{
if (write(1, &char_to_be_written, 1) == -1)
{
return ((char)(-1));
}
return (char_to_be_written);
}

