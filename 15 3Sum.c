#include<stdio.h>
#include<stdlib.h>
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

//快速排序 
void quickSort(int* nums, int first, int end) {
	int temp, l, r;
	if (first >= end) {
		return;
	}
	temp = nums[first];
	l = first;
	r = end;
	while (l < r) {
		while (l < r && nums[r] >= temp) {
			r--;
		}
		if (l < r) {
			nums[l] = nums[r];
		}
		while (l < r && nums[l] <= temp) {
			l++;
		}
		if (l < r) {
			nums[r] = nums[l];
		}
	}
	nums[l] = temp;
	quickSort(nums, first, l - 1);
	quickSort(nums, l + 1, end);
}

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){

    int i = 0;								//当前数值下标
	int left = i+1;							//左指针
	int right = numsSize - 1;				//右指针
	int sum = 0;							//和
	int base_alloc_size = 16;				//基本内存
	int** result = (int**)malloc(sizeof(int*) * base_alloc_size);
	(*returnSize) = 0;
	*returnColumnSizes = (int*)malloc(sizeof(int) * base_alloc_size);

	if (numsSize < 3 || nums == NULL) {
		return NULL;
	}

	quickSort(nums, 0, numsSize - 1);                           //排序

	for (i = 0; i <= numsSize - 3; i++) {
		left = i + 1;
		right = numsSize - 1;
		if (nums[i] > 0) {										// 如果当前数字大于0，则三数之和一定大于0，所以结束循环
			break;
		}
		if (i > 0 && nums[i] == nums[i - 1]) {					// 去重
			continue;
		}
		while (left < right) {
			sum = nums[i] + nums[left] + nums[right];
			if (sum > 0) {
				right--;
			}
			else if (sum < 0) {
				left++;
			}
			else {
				result[*returnSize] = (int*)calloc(3, sizeof(int));
				result[*returnSize][0] = nums[i];
				result[*returnSize][1] = nums[left];
				result[*returnSize][2] = nums[right];

				(*returnColumnSizes)[*returnSize] = 3;
				(*returnSize)++;
                
				while (left < right && nums[left] == nums[left + 1]) {		//去除重复的
					left++;
				}
				while (left < right && nums[right] == nums[right - 1]) {
					right--;
				}
				left++; right--;
			}

			if (*returnSize == base_alloc_size) {							//空间不足，扩充内存
				base_alloc_size = base_alloc_size * 2;
				result = (int**)realloc(result, base_alloc_size * sizeof(int*));
				(*returnColumnSizes) = (int*)realloc((*returnColumnSizes), base_alloc_size * sizeof(int));
			}
		}
	}
	return result;
}


int main()
{
    int a[6] = {-1,0,1,2,-1,-4};
    int returnSize;
    int *returnCreturnColumnSizes;
    int **res = threeSum(a, 6, &returnSize, &returnCreturnColumnSizes);
    printf("[\n");
    for (int i = 0; i < returnSize; ++i)
    {
    	printf("  [");
    	for (int j = 0; j < *returnCreturnColumnSizes; ++j)
    	{
			printf("%d",res[i][j]);
    		if (j != *returnCreturnColumnSizes - 1)
    		{
    			printf(",");
    		}
		}
    	printf("]\n");
    }
    printf("]\n");
    return 0;
}

