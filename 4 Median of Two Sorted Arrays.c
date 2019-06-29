#include<stdio.h>
#include<limits.h>

double max(double a, double b) {
    if(a > b) return a;
    return b;
}
double min(double a, double b) {
    if(a < b) return a;
    return b;
}

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
	/*
	详细的算法思路讲解请参考：
	https://leetcode-cn.com/problems/median-of-two-sorted-arrays/solution/4-xun-zhao-liang-ge-you-xu-shu-zu-de-zhong-wei-shu/
	*/

    //让数组1一定最短
    if (nums1Size > nums2Size) {
        return findMedianSortedArrays(nums2, nums2Size, nums1, nums1Size);
    }

    // Ci 为第i个数组的割,比如C1为2时表示第1个数组只有2个元素。LMaxi为第i个数组割后的左元素。RMini为第i个数组割后的右元素。
    int LMax1, LMax2, RMin1, RMin2, c1, c2, lo = 0, hi = 2 * nums1Size;  //这里虚拟加了'#'所以数组1是2*nums1Size长度

    while (lo <= hi)   //二分
    {
        c1 = (lo + hi) / 2;  //c1是二分的结果
        c2 = nums2Size + nums1Size - c1;

        LMax1 = (c1 == 0) ? INT_MIN : nums1[(c1 - 1) / 2];
        RMin1 = (c1 == 2 * nums1Size) ? INT_MAX : nums1[c1 / 2];
        LMax2 = (c2 == 0) ? INT_MIN : nums2[(c2 - 1) / 2];
        RMin2 = (c2 == 2 * nums2Size) ? INT_MAX : nums2[c2 / 2];

        if (LMax1 > RMin2)
            hi = c1 - 1;
        else if (LMax2 > RMin1)
            lo = c1 + 1;
        else
            break;
    }
    return (max(LMax1, LMax2) + min(RMin1, RMin2)) / 2;
}



int main()
{
    int a[] = {1,2};
    int b[] = {3,4};
   	double median = findMedianSortedArrays(a,2,b,2);
    printf("The median is %lf\n",median);
    return 0;
}
