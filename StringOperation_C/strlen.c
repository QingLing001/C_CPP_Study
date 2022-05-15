#include <stdio.h>
//Returns the length of the given null-terminated byte string, that is, the number of characters that precede the terminating null character.
size_t strlen_(const char *str)
{
    size_t size = 0;
    while(*str++)
        size++;
    return size;
}
int main()
{
    //cpp Reference
    const char str[] = "How many characters does this string contain?";
 
    printf("without null character: %zu\n", strlen_(str));
    printf("with null character: %zu\n", sizeof(str));
 
    return 0;
}