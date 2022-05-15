#include <stdio.h>
#include <string.h>

//str倒转
char* strreverse(char *str)
{
    size_t n = strlen(str);
    for (size_t i = 0; i < n / 2; i++)
    {
        char tmp = str[i];
        str[i] = str[n-1-i];
        str[n-1-i] = tmp;
    }

    return str;
}

int main()
{
    char buff[] = "1234567890abcdefghigklmnopqrstuvwxyz";
    printf("%s\n" ,buff);
    printf("%s\n" ,strreverse(buff));

    return 0;
}

