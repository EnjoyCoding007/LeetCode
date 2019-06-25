#include<stdio.h>


//递归法
int iterBiSearch(int nums[], int first, int last, int target)
{
    int mid = -1;
    if (first<=last) {
        mid = (first + last) / 2;
    }
    if (mid >= 0){
        if (target == nums[mid]) {
            return mid;
        }
        else if (target < nums[mid]) {
            return iterBiSearch(nums, first, mid - 1, target);
        }
        else if (target > nums[mid]) {
            return iterBiSearch(nums, mid + 1, last, target);
        }
    }
    return -1;
}


int search(int* nums, int numsSize, int target)
{
    //非递归方法
    /*
    int left = 0;
    int right = numsSize - 1;
    while (left<=right) {
        int  mid = (left+right)/2;
        if (nums[mid]>target) {
            right = mid - 1;
        }else if (nums[mid]<target){
            left = mid + 1;
        }else{
            return mid;
        }
    }
    return -1;

    */
    return iterBiSearch(nums,0,numsSize-1,target);
}

int main()
{
    int array[] = {1,2,3,4,5,6,7,8,9};
    int numsSize = sizeof(array)/sizeof(array[0]);
    int element = 0;//定义查找的元素并初始化为0
    printf("请输入要查找的元素:");
    scanf("%d",&element);
   int location = search(array,numsSize,element);
    if(location>=0)
        printf("The element's location is %d\n",location);
    else
        printf("Don't exit this element.\n");
    return 0;
}
