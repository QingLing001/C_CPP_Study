#include <stdio.h>
//#include <stdlib.h>
int atoi_(char* str)
{
	int value = 0;
	for (size_t i = 0; str[i] >= '0' && str[i]<='9'; i++)
	{
		value *= 10;
		value += str[i] - '0';
	}
	return value;
}

int main()
{
    //以前表现与c/c++标准库中一致
	printf("i=%d\n" ,atoi_("42"));
    printf("i=%d\n" ,atoi_("3.14159"));
    printf("i=%d\n" ,atoi_("31337 with words"));
    printf("i=%d\n" ,atoi_("words and 2"));
	return 0;
}
//以下例子取自c++ reference
// std::atoi("42") is 42
// std::atoi("3.14159") is 3
// std::atoi("31337 with words") is 31337
// std::atoi("words and 2") is 0