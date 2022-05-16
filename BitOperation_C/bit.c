#include <stdio.h>
void swap() //交换2个变量的值
{
    int a = 1;
    int b = 2;
    printf("a=%d b=%d\n",a,b);
    a^=b;
    b^=a;
    a^=b;
    printf("a=%d b=%d\n",a,b);
}

void count1()//求二进制中1的个数
{
    int a = 5;
    int count = 0; 
    while(a)
    {
        a = a & (a - 1);//每次把最低位丢弃，直到a为0.
        count++;
    }
    printf("%d\n" ,count);
}

void count0()//求二进制中0的个数
{
    int a = 5; 
    int count = 0;
    while(a + 1)
    {
        a=a|(a+1);
        count++;
    }
    printf("%d\n" ,count);
}

void abs_()//求一个数的绝对值
{
    int i = -2;
    int j = i >> 31; 
    i = (i ^ j) - j;
    printf("%d\n" ,i);
}

void negative()//求一个数的相反数
{
    int i = -2; 
    i = ~i + 1;
    printf("%d\n" ,i);
}

void odd_even()//判断一个数的奇偶性
{
    int a = 3; 
    if((a & 1) == 1)
    {
        printf("奇数\n");
    }
    else
    {
        printf("偶数\n");
    }
}

void average()//求两个数的平均数
{
    int a = 3;
    int b = 7;
    printf("平均值:%d\n" ,(a + b) >> 1);
}

unsigned GetBits(unsigned x ,int p ,int n)//从无符号类型x的第p位开始，取n位数
{
    return(x >> (p + 1 - n)) & ~(~0 << n);
}

int main()
{
    swap(); //交换2个变量的值
    count1();//求二进制中1的个数
    count0();//求二进制中0的个数
    abs_();//求一个数的绝对值
    negative();//求一个数的相反数
    odd_even();//判断一个数的奇偶性
    average();//求两个数的平均数
    GetBits(65535 ,5 ,5);//从无符号类型x的第p位开始，取n位数
}