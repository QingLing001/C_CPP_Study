#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//dest  -  pointer to the byte string to copy to  
//src  -  pointer to the null-terminated byte string to copy from  

void strcpy_(char *dest,char *src)
{
    while (*src)
        *dest++ = *src++;
    *dest = '\0';
}

int main()
{
    //cpp Reference
    char A[] = "Take the test.";
    char *B = malloc(strlen(A) + 1);
    strcpy_(B, A);
    A[0] = 'M';
    printf("A = %s\nB = %s\n", A, B);
 
    return 0;
}