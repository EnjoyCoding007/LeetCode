#include<stdio.h>


unsigned long long fib(int N){
    /*
     递归法:
     //会产生大量重复计算，时间复杂度为 O(2^n)
     if (N<=1) {
        return N;
     }else{
        return fib(N-1)+fib(N-2);
     }
     */
    
    /*
     数组法:
     内存消耗较大 空间复杂度为O(n)
     unsigned long long array[N+1];
     for (int i = 0; i <= N; ++i)
     {
        if (i<=1)
     {
        array[i] = i;
     }else{
        array[i] = array[i-1]+array[i-2];
     }
     }
     return array[N];
     */
    
    // 变量替换法 空间复杂度为O(1)
    unsigned long long curr = 0, next = 1;
    while(N-- > 0) {
        next = next + curr;
        curr = next - curr;
    }
    return curr;
}

int main()
{
    int n = 50;
    printf("斐波那契数列第%d个元素是：%llu\n",n,fib(n));
    return 0;
}

