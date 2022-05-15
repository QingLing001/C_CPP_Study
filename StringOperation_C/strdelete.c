#include <stdio.h>
#include <string.h>
//delete target from dest. return deleted times
int strdelete(char* dest, char* target)
{
    //有效性检验 备注：strlen返回的结果并不包含\0
	int dlen = strlen(dest);
	int tlen = strlen(target);
    if (tlen > dlen)
    {
        return 0;
    }

    //匹配次数
	int times=0;
	for(int i = 0 ;i <= dlen - tlen ;i++)
	{
        int j = 0;
		for(j = 0 ;j < tlen ;j++)
		{
			if(dest[i+j] != target[j])
                break;
		}

		if(j == tlen)
		{
			times++;
			//删除当前已匹配的target
			for(j = i ;j < dlen - tlen ;j++)
			{
				dest[j] = dest[j+tlen];
			}
			dlen -= tlen;
			i -= 1; //继续在当前位置查找
		}
	}
	dest[dlen]='\0';

    return times;
}

int main()
{
	char dest[100] = "abc123abc456abc";
	char target[10] = "abc";
	printf("dest=%s\n" ,dest);
	printf("delete target=%s\n" ,target);

    int count = strdelete(dest, target);

	printf("dest=%s\n" ,dest);
	printf("deleted match times=%d\n" ,count);
	return 0;
}