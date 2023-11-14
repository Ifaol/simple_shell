#include "shell.h"
/**
 *_puts - a function that writes a string to stdout
 *@ptr: a pointer to string
 *
 *Return: Void
 */
void _puts(char *ptr)
{
int j;
for (j = 0 ; ptr[j] != '\0' ; j++)
{
_putchar(ptr[j]);
}
}
/**
 *_strlen - a function that return a string's length
 *@s: pointer of a const char string input
 *
 *Return: string length
 */
size_t _strlen(const char *s)
{
int i = 0;
size_t count = 0;
if (s == NULL)
{
return (count);
}
while (s[i] != '\0')
{
count++;
i++;
}
return (count);
}
/**
*_strdup - a custome strdup function
*@str: const char pointer sourse input
*
*Return: duplicated string pointer
*/
char *_strdup(const char *str)
{
int i = 0, count = 0;
char *dup = NULL;
if (str == NULL)
{
return (NULL);
}
count = _strlen(str);
dup = (char *)malloc(sizeof(char) * (count + 1));
if (dup == NULL)
{
perror("malloc");
return (NULL);
}
while (*str != '\0')
{
dup[i] = *str;
str++;
i++;
}
dup[i] = *str;
return (dup);
}
/**
 *_strcpy - a custom strcpy function
 *@dest: a destination char pointer
 *@src: a source char pointer
 *
 *Return: char pointer of copied string
 */
char *_strcpy(char *dest, char *src)
{
int i = 0;
if (src == NULL || dest == src)
{
return (dest);
}
while (src[i] != '\0')
{
dest[i] = src[i];
i++;
}
dest[i] = src[i];
return (dest);
}

