#include <stdio.h>
#include <string.h>

//Interprets a buff by an floating point value in a byte string pointed to. 
//最终输出不会像代码中字面常量那么整齐，double数值总有很长的尾数，没有做四舍五入处理
//ftoa在C库中并没有，实现起来意义也不大，因为大多数时候还不如sprintf好用，此处仅为示例
char* ftoa_(double f ,char buff[])
{
	int integer = f;//整数部分
	int float_ = (f - integer) * 1000000;//最多保留6位小数
	int i=0;
	int f_pos;//小数起始位置
	char tmp;

	//处理整数部分
	while(integer)
	{
		buff[i] = integer % 10 + '0';
		integer /= 10;
		i++;
	}

	//逆序
	for(int j = 0 ;j < i / 2 ;j++)
	{
		tmp = buff[j];
		buff[j] = buff[i-j-1];
		buff[i-j-1] = tmp;
	}

	//小数点
	buff[i] = '.'; 
	i++; 
	f_pos = i;

	//处理小数部分
	while(float_)
	{
		buff[i] = float_ % 10 + '0';
		float_ /= 10;
		i++;
	}
	buff[i] = '\0';

	//逆序
	for(int j = 0 ;j < 3 ;j++)
	{
		tmp = buff[f_pos+j];
		buff[f_pos+j] = buff[i-j-1];
		buff[i-j-1] = tmp;
	}

	return buff;
}

int main()
{
	char buff1[20] = {0};
	char buff2[20] = {0};
	char buff3[20] = {0};
	printf("buff=%s\n" ,ftoa_(12345.12345 ,buff1));
	printf("buff=%s\n" ,ftoa_(12345.123456 ,buff2));
	printf("buff=%s\n" ,ftoa_(12345.1234567 ,buff3));
	return 0;
}

