#include<stdio.h>
#include<stdlib.h>

int firstUniqChar(char * s){
    
    //这里只考虑小写字母，所以开辟数组空间元素个数是26
    int *b = (int*)calloc(26,sizeof(int));
    
	char* p = s;
	//依次统计每个字母出现的次数，'\0':字符串结束符,它的ASCII码值为0.
	while(*p != '\0'){
		b[*(p++)-'a']++;
	}
    p = s;
    int index = 0;
	while(*p != '\0'){
		if (b[*(p++)-'a'] == 1) {
            return index;
		}
        index++;
	}
    return -1;
}


int main()
{
	char string[] = "adwdfdgdfdwaafsdgr";
	int index = firstUniqChar(string);
	printf("%d\n",index);
	return 0;
}