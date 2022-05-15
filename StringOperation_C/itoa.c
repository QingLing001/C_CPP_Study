#include <stdio.h>
#include <string.h>
//这个实现把参数中的底数去掉了，没啥意思，直接就10好了。
char* itoa_(int n ,char* buff)
{
	int i=0;
	char tmp;
	while(n)
	{
		buff[i] = n % 10 + '0';
		n /= 10;
		i++;
	}
	buff[i] = '\0';
	
	for(int j = 0 ;j < i / 2 ;j++)
	{
		tmp = buff[j];
		buff[j] = buff[i-j-1];
		buff[i-j-1] = tmp;
	}

    return buff;
}

int main()
{
	//cpp reference
	char buf[100];
	printf("%s\n", itoa_(12346, buf));
	printf("%s\n", itoa_(-12346, buf));//本实现中没考虑符号，所以这个不能转
	printf("%s\n", itoa_(65535, buf));
	return 0;
}
