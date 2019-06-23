#include<stdio.h>
#include <string.h>

void reverseString(char* s, int sSize){
    char* begin = s;
	char* end = s + sSize - 1;
	while(begin<end){
		char temp = *begin;
		*(begin++) = *end;
		*(end--) = temp;
	}
}

int main()
{
	char str[] = "hello,world";
	reverseString(str,strlen(str));
	printf("%s\n",str);
	return 0;
}