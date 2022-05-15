#include<stdio.h>
//dest  -  pointer to the null-terminated byte string to append to  
//src  -  pointer to the null-terminated byte string to copy from 
char* strcat_(char* dest,char *src)
{
    char *p = dest;
    while (*p)
        p++;
    while (*src)
        *p++ = *src++;
    *p='\0';
    return dest;
}

int main()
{
    //cpp Reference
    char str1[50] = "Hello ";
    char str2[50] = "World!";
    strcat_(str1, str2);
    strcat_(str1, " ...");
    strcat_(str1, " Goodbye World!");
    puts(str1);
    return 0;
}