#include<stdio.h>

double min(double a, double b) {
    if(a < b) return a;
    return b;
}

int findKthNumber(int n, int k){

    int cur = 1;
        k--;
        
        while (k > 0)
        {
            long long left = cur;
            long long right = cur + 1;
            int node_num = 0;
            
            while (left <= n) // 统计树中每一层的节点个数
            {
                node_num += min(right, (long long)(n+1)) - left;
                left *= 10;
                right *= 10;
            }
            
            if (node_num <= k) // 向后查找
            {
                k -= node_num;
                cur++;
            }
            else // 进入子树查找
            {
                k--;
                cur *= 10;
            }
        }
        
        return cur;
}


int main() {
    /**
     *  参考：https://leetcode-cn.com/problems/k-th-smallest-in-lexicographical-order/solution/ben-ti-shi-shang-zui-wan-zheng-ju-ti-de-shou-mo-sh/
     */
    printf("%d\n",findKthNumber(13,2));
    return 0;
}
