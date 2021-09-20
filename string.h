/*
	string.h - String manipulation functions
    Copyright (C) 2021 anic17 Software

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>

*/

/* Existent functions:

    strcat() - Concatenates two strings
    strcpy() - Copies a string
    strcmp() - Compares two strings
    strlen() - Returns the length of a string
    strlower() - Converts a string to lowercase
    strncmp() - Compares two strings up to a certain length
    strtok() - Tokenizes a string
    strstr() - Finds a substring in a string
    strupper() - Converts a string to uppercase
    strxlen() - Returns the length of a string excluding specified characters

*/

// Definitions for some macros

#ifndef NULL
    #define NULL ((void *)0)
#endif

unsigned long strlen(char *s)
{
    int i;
    while (s[i] != '\0')
    {
        i++;
    }
    return i;
}

unsigned long strxlen(char *s, char *exclude)
{
    int i = 0, n = 0, a = 0;
    while (s[i] != '\0')
    {
        for (int j = 0; j < strlen(exclude); j++)
        {
            if (s[i] == exclude[j])
            {
                a = 0;
            }
        }
        if (a == 1)
        {
            n++;
        }
        else
        {
            a = 1;
        }
        i++;
    }
    return n;
}

char *strtok(char *str, char *tok)
{
    int i = 0;
    while (str[i] != '\0')
    {
        for (int j = 0; j < strlen(tok); j++)
        {
            if (str[i] == tok[j])
            {
                str[i] = '\0';
                return str;
            }
        }
        i++;
    }
    return NULL;
}

int strcmp(char *s1, char *s2)
{
    while(*s1 != '\0' && *s2 != '\0')
    {
        if(*s1++ != *s2++)
        {
            return 0;
        }

    }
    return 1;
}

int strncmp(char *s1, char *s2, unsigned long count)
{
    for (int i = 0; i < count; i++)
    {
        if (s1[i] != s2[i])
        {
            return i;
        }
    }
    return 0;
}

int strstr(char *str, char *find)

{
    int n = strlen(find);
    for (int i = 0; i < strlen(str); i++)
    {
        if (!strncmp(str + i, find, n))
        {
            return i;
        }
    }
    return -1;
}

char *strlower(char *s)
{
    for (int i = 0; i < strlen(s); i++)
    {
        if (s[i] >= 'A' && s[i] <= 'Z')
        {
            s[i] += 32;
        }
    }
}

char *strupper(char *s)
{
    for (int i = 0; i < strlen(s); i++)
    {
        if (s[i] >= 'a' && s[i] <= 'z')
        {
            s[i] -= 32;
        }
    }
}

char *strcat(char s1[], char s2[])
{

    int i;
    unsigned long n = strlen(s1);

    while (s1[i] != 0)
    {
        s1[i + n] = s2[i];
        i++;
    }

    return s1;
}

char *strcpy(char *dest, char *src)
{
    while (*src != '\0')
    {
        *dest++ = *src++;
    }
    return dest;
}

char *strncpy(char *dest, char *src, unsigned long count)
{
    while (*src != '\0' && *dest < count)
    {
        *dest++ = *src++;
    }
    return dest;
}