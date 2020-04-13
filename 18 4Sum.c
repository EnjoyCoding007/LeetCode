#include<stdio.h>
#include<stdlib.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int comp(const void *a,const void *b)
{
    return *(int *)a - *(int *)b;
}

int** fourSum(int* nums, int numsSize, int target, int* returnSize, int** returnColumnSizes){
    *returnSize = 0;
    if (numsSize == 0) {
        return 0;
    }
    int **ret = (int **)malloc(sizeof(int *) * (numsSize + 1) * 3);
    *returnSize = 0;
    short left = 0;
    short right = numsSize - 1;
    short begin = 0;
    short end = numsSize - 1;
    int loopTarget = 0;
    int subTarget = 0;
    
    *returnColumnSizes = malloc(sizeof(int) * (numsSize + 1) * 3);
    qsort(nums, numsSize, sizeof(int), comp);
    ret[*returnSize] = malloc(sizeof(int) * 4);
    
    while (begin + 2 < end) {
        left = begin + 1;
        right = end;
        loopTarget = target - nums[begin];
        while (left + 1 < right) {
            int i = left + 1;
            int j = right;
            subTarget = loopTarget - nums[left];
            while (i < j) {
                if (nums[i] + nums[j] < subTarget) {
                    i++;
                } else if (nums[i] + nums[j] > subTarget) {
                    j--;
                } else {
                    ret[*returnSize][0] = nums[begin];
                    ret[*returnSize][1] = nums[left];
                    ret[*returnSize][2] = nums[i];
                    ret[*returnSize][3] = nums[j];
                    (*returnColumnSizes)[*returnSize] = 4;
                    (*returnSize)++;
                    ret[*returnSize] = malloc(sizeof(int) * 4);
                    
                    i++;
                    while(nums[i-1] == nums[i] && i < j) {
                        i++;
                    }
                    j--;
                    while(nums[j+1] == nums[j] && i < j) {
                        j--;
                    }
                }
            }
            left++;
            while(nums[left-1] == nums[left] && left + 1 < right) {
                left++;
            }
        }
        begin++;
        while(nums[begin-1] == nums[begin] && begin + 2 < end) {
            begin++;
        }
    }
    
    return ret;
}

int main()
{
    int a[6] = {1,0,-1,0,-2,2};
    int returnSize;
    int *returnCreturnColumnSizes;
    int **res = fourSum(a, 6, 0, &returnSize, &returnCreturnColumnSizes);
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