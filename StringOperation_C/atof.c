#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//Interprets an floating point value in a byte string pointed to by str. 
double atof_(char* str)
{
	int integer = 0; //整数部分
	int float_ = 0; //从str转换来的小数部分暂时使用int存储
	int divisor = 1;//小数部分最终除以这个除数
	int i = 0;//str下标
	//处理整数
	while((str[i] != '\0') && (str[i] >= '0' && str[i] <= '9'))
	{
		integer *= 10;
		integer += str[i] - '0';
		i++;
	}
	
	if (str[i] == '.')
    {
        i++; //跨过小数点
    }
    else
    {
        return (double)integer;
    }

	while(str[i] >= '0' && str[i] <= '9')
	{
		float_ *= 10;
		float_ += str[i] - '0';
		i++;
		divisor *= 10;
	}

	return integer + float_ / (double)divisor;
}

int main()
{
    char str1[] = "123456.12345";
    char str2[] = "123456.123456";
	char str3[] = "123456.1234567";
    char str4[] = "123456aa";
    char str5[] = "123456.1111aa";
    char str6[] = "aa123456.1111aa";

	printf("d=%lf\n" ,atof_(str1));
    printf("d=%lf\n" ,atof_(str2));
    printf("d=%lf\n" ,atof_(str3));
    printf("d=%lf\n" ,atof_(str4));
    printf("d=%lf\n" ,atof_(str5));
    printf("d=%lf\n" ,atof_(str6));
	return 0;
}

//以下例子取自cpp reference atof. 本实现中没有这么强
// printf("%g\n", atof("  -0.0000000123junk"));
// printf("%g\n", atof("0.012"));
// printf("%g\n", atof("15e16"));
// printf("%g\n", atof("-0x1afp-2"));
// printf("%g\n", atof("inF"));
// printf("%g\n", atof("Nan"));

// 输出
// -1.23e-08
// 0.012
// 1.5e+17
// -107.75
// inf
// nan