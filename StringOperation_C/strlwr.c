#include <stdio.h>
#include <string.h>

//strlwr在C标准库里没有，当年谭浩强老师教的课本里就不该提这个，唉...
//大写转小写
char* strlwr_(char *str)
{
    char* p = str;
    while (*p)
    {
        if (*p >= 'A' && *p <= 'Z')
        {
            *p += 32;
        }
        p++;
    }
    return str;
}

int main()
{
    char buff[] = "123AaBbCcDdEeFfXxYyZz456@#$";
    printf("%s\n" ,strlwr_(buff));

    return 0;
}

