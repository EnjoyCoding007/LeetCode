#include<stdio.h>
#include<stdlib.h>

/*方法2：

struct node {
    int val;
    int index;
};

int comp(const void* a, const void* b) {
    return (((struct node*)a)->val > ((struct node*)b)->val ? 1 : -1);
}
*/

//方法3：
struct nodeNew {
    long val;
    int index;
    struct nodeNew* next;
};

void insert(struct nodeNew** hashTable, long val, int index, int n) {
    int t = labs(val) % n;
    struct nodeNew* temp = hashTable[t];
    // head-add
    struct nodeNew* add = (struct nodeNew*)malloc(sizeof(struct nodeNew));
    add->val = val;
    add->index = index;
    add->next = temp->next;
    temp->next = add;
}

int search(struct nodeNew** hashTable, long target, int n) {
    int index = labs(target) % n;
    struct nodeNew* temp = hashTable[index]->next;
    while(temp) {
        if(temp->val == target) {
            return temp->index;
        }
        temp = temp->next;
    }
    return -1;
}

void freeHashTable(struct nodeNew** hashTable, int n) {
    int i = 0;
    struct nodeNew *temp = NULL, *delete = NULL;
    for(i = 0; i < n; i++) {
        temp = hashTable[i];
        delete = temp;
        while(temp) {
            delete = temp;
            temp = temp->next;
            free(delete);
        }
    }
    free(hashTable);
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    /*
     方法1：暴力解法，两轮遍历
     该方法简单但是时间复杂度为O(n^2),空间复杂度为O(1);运行速度慢且内存空间消耗大
     Runtime: 136 ms
    int i,j;
    int *two_nums = (int *)malloc(sizeof(int)*2);
    for(i=0;i<numsSize-1;i++)
    {
        for(j=i+1;j<numsSize;j++)
        {
            if(nums[i]+nums[j]==target)
            {
                *returnSize = 2;
                two_nums[0]=i;
                two_nums[1]=j;
                return two_nums;
            }
        }
    }
    */
    
    /*
     方法2：排序加双下标：先将数组元素按序转成结构体存入结构体数组中，然后对结构体元素排序， 再由两端往中间逼近 target.
     - 时间复杂度: O(N)- 空间复杂度: O(N)
     Runtime: 4 ms, faster than 99.71% of C online submissions for Two Sum.
     
     参考链接：https://blog.csdn.net/hang404/article/details/84764531
     
    int begin = 0, end = numsSize - 1;
    int* two_nums = NULL;
    struct node* nodes = (struct node*)malloc(numsSize * sizeof(struct node));
    // init nodes
    for(int i = 0; i < numsSize; ++i) {
        nodes[i].val = nums[i];
        nodes[i].index = i;
    }
    qsort(nodes, numsSize, sizeof(struct node), comp);
    while(begin < end) {
        if(nodes[begin].val + nodes[end].val == target) {
            *returnSize = 2;
            two_nums = (int*)malloc(sizeof(int) * 2);
            two_nums[0] = nodes[begin].index;
            two_nums[1] = nodes[end].index;
            free(nodes);
            return two_nums;
        }
        else if(nodes[begin].val + nodes[end].val > target)
            end--;
        else
            begin++;
    }
    free(nodes);
     
     */
   
    
    /*
     方法三：Hash法
     - 时间复杂度: O(N)- 空间复杂度: O(N)
     Runtime: 8 ms, faster than 95.74% of C online submissions for Two Sum.
     
     参考链接：https://blog.csdn.net/hang404/article/details/84764531
     */
    int i = 0, j = 0;
    int n = numsSize, index = 0;
    int* two_nums = NULL;
    struct nodeNew** hashTable = (struct nodeNew**)malloc(n * sizeof(struct nodeNew*));
    // init head node
    for(i = 0; i < n; i++)
        hashTable[i] = (struct nodeNew*)calloc(1, sizeof(struct nodeNew));
    for(i = 0; i < n; i++) {
        index = search(hashTable, target - nums[i], n);
        if(-1 == index)
            insert(hashTable, nums[i], i, n);
        else {
            *returnSize = 2;
            two_nums = (int*)malloc(sizeof(int) * 2);
            two_nums[0] = index;
            two_nums[1] = i;
            freeHashTable(hashTable, n);
            return two_nums;
        }
    }
    freeHashTable(hashTable, n);
    
    return two_nums;
}

int main()
{
    int nums[6] = {2,9,7,4,6,5};
    int target = 12;
    int returnSize;
    int *result = twoSum(nums,6,target,&returnSize);
    for (int i = 0; i<returnSize; i++) {
        printf("%d\n",result[i]);
    }
    //总结 方法2运行时间最短，效率最高。
}
