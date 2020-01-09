#include<stdio.h>
#include<stdlib.h>

int candy(int* ratings, int ratingsSize){

    int n = ratingsSize;
    int sum = 0;
    int *ca = (int *)malloc(sizeof(int) * n);

    ca[0] = 1;
    /* 从左往右 */
    for (int i = 0; i < n - 1; i++){
        if (ratings[i + 1] > ratings[i]){
            ca[i + 1] = ca[i] + 1;
        } else {
            ca[i + 1] = 1;
        }
    }
    /* 从右往左 */
    for (int i = n - 1; i > 0; i--){
        if (ratings[i - 1] > ratings[i] && ca[i - 1] <= ca[i]){
            ca[i - 1] = ca[i] + 1;
        }
    }
    
    for (int i = 0; i < n; i++){
        sum += ca[i];
    }
    free(ca);
    return sum;
}

int main() {
    
    /**
     *  参考 https://leetcode-cn.com/problems/candy/solution/fen-fa-tang-guo-by-leetcode/
     *  例如 输入: [1,2,2] 输出: 4
     */
    int a[3] = {1,2,2};
    int candyNum = candy(a,3);
    printf("%d\n",candyNum);
    return 0;
}
