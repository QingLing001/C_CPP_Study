#include <stdio.h>
#include <string.h>
//insert src to dest at pos
char* strinsert_(char* dest, char* src, int pos)
{
    //有效性检验 备注：strlen返回的结果并不包含\0
	int dlen = strlen(dest);
	int slen = strlen(src);
    if (pos > dlen)
    {
        return NULL;
    }
		
	//向后移动slen
	for(int i = dlen - 1 ;i >= pos ;i--)
	{
		dest[i + slen] = dest[i];
	}
	dest[dlen + slen] = 0;//\0

	//insert src to dest at pos
	for(int j = 0 ;j < slen ;j++)
    {
        dest[pos + j] = src[j];
    }
    
    return dest;
}

int main()
{
	char dest[100]="1234567890";  
	char src[]="abc";

    strinsert_(dest ,src ,3);

	printf("dest=%s\n" ,dest);
	return 0;
}