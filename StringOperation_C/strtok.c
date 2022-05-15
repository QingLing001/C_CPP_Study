#include <stdio.h>

//备注：此函数过于复杂，本人暂时没空，直接使用他人实现拿来学习 20220515 王亚飞
//原文链接：https://blog.csdn.net/m0_50945504/article/details/121218799
// 功能：将字符串根据分隔符分割
// 原理：全局变量状态实现缓存
// 关键：由于缺少strspn()和strpbrk()，根据自己实现了strspn()、strcspn()和strpbrk()后，发现就是建立集合进行判断移动指针的过程。
// 为了节省空间我这边将每一个位都利用了，大家如果看不懂，可以用256个bool(一个字节)变量之间存。
// 还是怕有人看不懂，问为什么需要256个位置进行映射，为什么需要uchar？在这里进行解答：因为一个字符为1个字节，所以如果不考虑符号，则最多表示0~255，由于我们是用数组下标对字符的数值进行映射，所以需要为非负数，故转uchar，而我typedef为uchar只是单纯的觉得unsigned char太长了而已🤣

// 性能分析
// 问题规模N为字符串的长度，由于设计strtok采用的是集合存储方式，而不是暴力枚举，所以时间复杂度占优为 O(n) ！而用于存储集合元素的数组也通过位运算实现了空间优化，空间不随问题规模改变，所以 O(1) 的空间复杂度。
// 时间复杂度：O ( N ) O(N)O(N)
// 空间复杂度：O ( 1 ) O(1)O(1)
typedef unsigned char uchar;

int get_pos(uchar x)
{
    return x % 32;
}

char *strtok_(char *src, const char *delimiters)
{
    char *sbegin, *send;
    static char *ssave = NULL;
    sbegin = src ? src : ssave;           //如果src为NULL就继续上一次的缓存
    uchar cset[32] = {0};                 //用32个unsigned char对每个位进行bool运算可以更节省内存
    while ((*delimiters) != '\0')
    {       //更新set
        uchar t = (uchar) *delimiters++;
        cset[get_pos(t)] |= 1 << (t / 32);//由于最大值255所以t/32为0~7
    }
    //让sbegin指向不在set中的位置
    while (*sbegin != '\0' && (cset[get_pos(*sbegin)] & (1 << (((uchar) *sbegin) / 32))))
    {
        ++sbegin;
    }
    if (*sbegin == '\0')
    {
        ssave = NULL;
        return NULL;
    }
    int idx = 0;
    //相当于strcspn的功能了
    while (sbegin[idx] != '\0' && !(cset[get_pos(sbegin[idx])] & (1 << ((uchar) sbegin[idx] / 32))))
    {
        ++idx;
    }
    send = sbegin + idx;
    if (*send != '\0')
        *send++ = '\0';                   //画上终止符
    ssave = send;                         //更新下一次处理的缓存位置
    return sbegin;
}

int main()
{
    char str[] = "- This 3234d s3242- -d-, a sample string.";
    char *pch;
    printf("Splitting string \"%s\" into tokens:\n", str);
    pch = strtok_(str, " ,.-");
    while (pch != NULL)
    {
        printf("%s\n", pch);
        pch = strtok_(NULL, " ,.-");
    }
    return 0;
}

//原文链接：https://blog.csdn.net/m0_50945504/article/details/121218799