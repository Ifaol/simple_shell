#include "shell.h"
/**
 *_strcmp - a custom string compare function
 *@s1: constant char string pointer input 1
 *@s2: constant char string pointer input 2
 *
 * Return: 0 for equal strings, positive and negative values for else
 */
int _strcmp(const char *s1, const char *s2)
{
while (*s1 != '\0' && *s2 != '\0')
{
if (*s1 == *s2)
{
s1++;
s2++;
}
else
{
return ((int)((*s1)-(*s2)));
}
}
return ((int)((*s1)-(*s2)));
}
/**
*_atoi - a custom atoi function
*@src: char string input to be converted to int
*
*Return: converted string as an int
*/
int _atoi(char *src)
{
int num = 0, i = 0, sign = 1, start = 0;
if (src[0] == '-')
{
sign = -1;
start = 1;
}
for (i = start ; src[i] != '\0' ; i++)
{
if (src[i] >= '0' && src[i] <= '9')
{
num = (num * 10) + (src[i] - '0');
}
else
{
break;
}
}
return ((num)*(sign));
}
/**
*_strcat - a custom strcat function
*@dest: a destination char pointer
*@src: a sourse char pointer
*
*Return: concatenated string char pointer
*/
char *_strcat(char *dest, const char *src)
{
int i = 0, j = 0;
while (dest[i] != '\0')
{
i++;
}
while (src[j] != '\0')
{
dest[i] = src[j];
j++;
i++;
}
dest[i] = '\0';
return (dest);
}
/**
 *_strncmp - a custome strncmp function
 *@s1: constant chat string pointer input 1
 *@s2: constant chat string pointer input 1
 *@n: size_t length of comparision
 *
 *Return: 0 for equal strings and posive numbers for else
 */
int _strncmp(const char *s1, const char *s2, size_t n)
{
size_t i;
for (i = 0 ; i < n ; i++)
{
if (*s1 != *s2)
{
return ((int)((*s1)-(*s2)));
}
if (*s1 == '\0')
{
break;
}
s1++;
s2++;
}
return (0);
}

