#include <stdio.h>
//Copies count characters from the object pointed to by src to the object pointed to by dest. If the objects overlap, the behavior is undefined. 
void *memcpy_(void *dest ,const void *src ,int count)
{
	char *p1 = dest;
	const char *p2 = src;
	for(int i = 0 ;i < count ;i++)
	{
		p1[i] = p2[i];
	}
	return dest;
}

#define LENGTH_STRING 20
int main()
{
	//cpp reference
    char source[LENGTH_STRING] = "Hello, world!";
    char target[LENGTH_STRING] = "";
    int integer[LENGTH_STRING / sizeof(int)] = {0};
    printf("source: %s\n", source);
    printf("target: %s\n", target);
    printf("integer: ");
    for (unsigned i = 0; i < sizeof(integer) / sizeof(integer[0]); ++i) {
        printf("%x ", integer[i]);
    }
    printf("\n========\n");
    memcpy_(target, source, sizeof source);
    memcpy_(integer, source, sizeof source);
    printf("source: %s\ntarget: %s\n", source, target);
    printf("source(hex): ");
    for (unsigned i = 0; i < sizeof(source) / sizeof(source[0]); ++i) {
        printf("%02x ", source[i]);
    }
    printf("\n");
    printf("integer(hex: %s-endian): ", integer[0] == 0x48656c6c ? "big" : "little");
    for (unsigned i = 0; i < sizeof(integer) / sizeof(integer[0]); ++i) {
        printf("%08x ", integer[i]);
    }
    printf("\n");
}
// 简单例子
// char src[] = "aaaaaaaaaa";
// char dest[100] = {0};
// memcpy_(dest ,src ,sizeof(src)); 
// printf("dest=%s\n" ,dest);