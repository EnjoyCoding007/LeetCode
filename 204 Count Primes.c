#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<math.h>

//第二个参数 numsArray 自己加的，为了输出具体是那些质数.
int countPrimes(int n,int* numsArray){
    
    if(n<=2)return 0;
    
    int sq=sqrt(n);
    
    bool *arr = (bool*)calloc(n,sizeof(bool));
    for(int i=3;i<=sq;i+=2){
        if(arr[i]){
            continue;
        }
        else{
            for(int j=i*i;j<n;j+=2*i){
                arr[j]=true;
            }
        }
    }
    
    int sum=1;
    numsArray[0] = 2;
    for(int i=3;i<n;i+=2){
        if(arr[i]==false){
            numsArray[sum]=i;//记录每个质数 解题时不需要
            sum++;
        }
    }
    free(arr);
    
    return sum;
}

int main()
{
    int n = 66;
    int sq=sqrt(n);
    int *numsArray = (int*)calloc(sq,sizeof(int));
    int num = countPrimes(n,numsArray);
    printf("%d 的质数个数: %d个，分别为:\n",n,num);
    for (int i = 0; i < num; i++) {
        printf("%d%s",numsArray[i],i==num-1?"\n":",");
    }
}
