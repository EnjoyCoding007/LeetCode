#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int partition(int arr[], int left, int right) {
    int i = left, j = right;
    int tmp = arr[left];
    while (i < j) {
        while (i < j && arr[j] > tmp)
            j--;
        if (i < j) {
            arr[i] = arr[j];
            i++;
        }
        while (i < j && arr[i] < tmp)
            i++;
        if (i < j) {
            arr[j] = arr[i];
            j--;
        }
    }
    arr[i] = tmp;
    return i;
}
//快速排序
void quick_sort(int arr[], int left, int right) {
    if(left > right)
        return;
    int j = partition(arr, left, right);
    quick_sort(arr, left, j - 1);
    quick_sort(arr, j + 1, right);
}

//希尔排序
void shellSort(int arr[],int len) {
    for (int gap = floor(len / 2); gap > 0; gap = floor(gap / 2)) {
        //多个分组交替执行
        for (int i = gap; i < len; i++) {
            int j = i;
            int current = arr[i];
            while (j - gap >= 0 && current < arr[j - gap]) {
                arr[j] = arr[j - gap];
                j = j - gap;
            }
            arr[j] = current;
        }
    }
}


void merge(int *arr,int low,int m,int high)
{
    //将两个有序的子文件arr[low..m)和arr[m+1..high]归并成一个有序的子文件arr[low..high]
    int i=low,j=m+1,p=0;                //置初始值
    int *arr1;                          //arr1是局部向量
    arr1=(int*)malloc((high-low+1)*sizeof(int));
    if(!arr1){
        return;                         //申请空间失败
    }
    
    while(i<=m&&j<=high){               //两子文件非空时取其小者输出到arr1[p]上
        arr1[p++]=(arr[i]<=arr[j])?arr[i++]:arr[j++];
    }
    
    while(i<=m){                        //若第1个子文件非空，则复制剩余记录到arr1中
        arr1[p++]=arr[i++];
    }
    while(j<=high){                     //若第2个子文件非空，则复制剩余记录到arr1中
        arr1[p++]=arr[j++];
    }
    
    for(p=0,i=low;i<=high;p++,i++){
        arr[i]=arr1[p];                 //归并完成后将结果复制回arr[low..high]
    }
}
// 归并排序
void mergeSort(int *arr,int left,int right) {
    if (left<right) {
        int middle = floor((right + left) / 2);
        mergeSort(arr,left,middle);
        mergeSort(arr,middle+1,right);
        merge(arr,left,middle,right);
    }
}

int* sortArray(int* nums, int numsSize, int* returnSize){
    
    /*
     参考博客：
     https://www.cnblogs.com/onepixel/p/7674659.html
     https://blog.csdn.net/cwj649956781/article/details/7409635
     */
    
//    quick_sort(nums,0,(numsSize-1));
    
//    shellSort(nums,numsSize);
    
    mergeSort(nums,0,(numsSize-1));
    * returnSize = numsSize;
    return nums;
}

int main(int argc, char const *argv[])
{
    int a[13] = {3,2,4,5,1,7,6,9,8,14,11,13,12};
    int length = sizeof(a)/sizeof(a[0]);
    sortArray(a,length,&length);
    for (int i = 0; i < length; ++i)
    {
        printf("%d\n", a[i]);
    }
    return 0;
}
