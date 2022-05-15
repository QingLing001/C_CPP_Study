#include <stdio.h>
#include <string.h>
//strupr在C标准库里没有，当年谭浩强老师教的课本里就不该提这个，唉...
//小写转大写
char* strupr_(char *str)
{
    char* p = str;
    while (*p)
    {
        if (*p >= 'a' && *p <= 'z')
        {
            *p -= 32;
        }
        p++;
    }
    return str;
}

int main()
{
    char buff[] = "123AaBbCcDdEeFfXxYyZz456@#$";
    printf("%s\n" ,strupr_(buff));

    return 0;
}