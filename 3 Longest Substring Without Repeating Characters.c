#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int lengthOfLongestSubstring(char * s){
    //Runtime: 0 ms, faster than 100.00% of C online submissions for Longest Substring Without Repeating Characters.

    //字符哈希表 用来判断该字符是否已经出现过 已出现过的字符其值作为索引取出的value=1   
    char * flag = (char*)calloc(256,sizeof(char));
    char * left = s;
    char * right = s;
    int len = strlen(s);
    int index = 0; int maxLen = 0, curLen = 0;
    if (0 == len || 1 == len) {
        return len;
    }

    while (right < s + len) {
        index = (int)(*right);
        if (1 == flag[index]) {
            // 出现一个已存在字符
            while (*left != *right) {
                // 将移出滑动窗口的字符重置为未出现过
                index = (int)(*left);
                flag[index] = 0;
                // 更新当前滑动窗口的长度
                curLen--;
                // 右移滑动窗口的起始位置
                left++;
            }
            // 将滑动窗口的起始点移到被重复字符的后一位
            left++;
        }else {
            // 未重复字符 更新滑动窗口长度
            curLen++;
            // 标记为已出现
            flag[index] = 1;
        }
        if (curLen > maxLen) {
            // 记录最长的滑动窗口长度
            maxLen = curLen;
        }
        // 右移滑动窗口的结束点
        right++;
    }
    return maxLen;
}

int main()
{
	char string[] = "adwdfdgdfdwaafsdgr";
	int length = lengthOfLongestSubstring(string);
	printf("%d\n",length);
	return 0;
}
