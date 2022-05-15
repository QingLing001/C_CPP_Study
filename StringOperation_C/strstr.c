#include <stdio.h>
#include <string.h>
/*
char *strstr_(const char *str, const char *substr);
str  -  pointer to the null-terminated byte string to examine
substr  -  pointer to the null-terminated byte string to search for
*/
//这是最简单的一种暴力实现，有更好的KMP算法，c库中用的什么算法？ 不清楚。
char *strstr_(const char *str, const char *substr)
{
	int len1 = strlen(str);
	int len2 = strlen(substr);
	if(len1 < len2)
        return NULL;
    int i = 0;
	for(;i < len1 ;i++)
	{
        int j = 0;
		for(; j < len2 ;j++)
		{
			if(str[i + j] != substr[j])
            break;
		}
		if(j == len2)
            return (void*)(str + i);
	}

	return NULL;
}

int main()
{
	char str[] = "abc123d123";
	printf("str首地址:%p\n" ,str);
	char *p = strstr_(str ,"123");
	printf("地址：%p,值：%s\n" ,p ,p);

	return 0;
}

