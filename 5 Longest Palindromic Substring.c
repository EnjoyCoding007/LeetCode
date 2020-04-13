#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char * longestPalindrome(char * s){
    int length=strlen(s);
    if (length < 2) {
        return s;
    }
    int posi,count=0,i,j;
    char *mark=(char *)malloc(sizeof(char)*(2*length+3));
    length=length*2+2;
    memset(mark,'#',length+1);//一个位置留给结束符
    mark[length]='\0';//字符串结尾符
    mark[0]='$';

    for(i=2,j=0;i<length;i+=2,j++)//初始化字符
        mark[i]=s[j];
    
    for(i=1;i<length;i++)//开始求步长和驻点
    {
        for(j=1;i+j<length;j++)
        {
            if(mark[i-j]!=mark[i+j])//两者不相等
            break;
        }
        if(2*j-1>count)
        {
            count=2*j-1;//得到字符串的总长度
            posi=i;
        }        
    }
    
    for(i=posi-count/2+1,j=0;i<posi+count/2;i+=2,j++)
    {
        s[j]=mark[i];
    }
    s[j]='\0';
    return s;
}


int main()
{
    char *b = "babad";
    char *a = (char*)calloc(5, sizeof(char));
    for(int i = 0; i <5; i++)
    {
        a[i]=b[i];
    }
    printf("The longestPalindrome is %s \n",longestPalindrome(a)); 
    return 0;
}
