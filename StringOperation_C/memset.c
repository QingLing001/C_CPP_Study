#include <stdio.h>
//Converts the value ch to unsigned char and copies it into each of the first count characters of the object pointed to by dest. 
void *memset_(void *dest ,char ch ,int count)
{
	char *p = dest;
	for(int i = 0; i < count ;i++)
	{
		p[i] = ch;
	}
	return dest;
}

int main()
{
	//cpp reference
	char str[] = "ghghghghghghghghghghgh";
    puts(str);
    memset_(str,'a',5);
    puts(str);
	//self
	char dest[20] = "aaaaaaa";
    printf("dest=%s\n" ,dest);
	memset_(dest ,0 ,20);
	printf("dest=%s\n" ,dest);

	return 0;
}