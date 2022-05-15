#include <stdio.h>
//Reinterprets the objects pointed to by lhs and rhs as arrays of unsigned char and compares the first count characters of these arrays. The comparison is done lexicographically. 
int memcmp_(const void *lhs ,const void *rhs ,int count)
{
	const char *p1 = lhs;
	const char *p2 = rhs;
	for(int i = 0 ;i < count ;i++)
	{
		if(p1[i] != p2[i])
            return 1;
	}
	return 0;
}

int main()
{	
	char lhs[] = "abcdefgh";
	char rhs[] = "abc";
	printf("%d\n",memcmp_(lhs ,rhs ,sizeof(lhs) - 1));
    printf("%d\n",memcmp_(lhs ,rhs ,sizeof(rhs) - 1));//数组实际存储有结尾符\0，需-1
	return 0;
}