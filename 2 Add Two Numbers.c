#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

/*
 战绩可查 :https://leetcode.com/submissions/detail/237286819/
 
 Runtime: 8 ms, faster than 98.46% of C online submissions for Add Two Numbers.
 
 */


struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode *head = NULL;
    struct ListNode *curNode = NULL;
    //记录上一个节点的和是否有进位
    int addNum = 0;
    //每个节点当前位的和
    int sum = 0;
    
    while (l1!=NULL || l2!=NULL || addNum==1) {
        
        struct ListNode *node = (struct ListNode *)malloc(sizeof(struct ListNode));
        node->val = 0;
        node->next = NULL;
        
        if (l1!=NULL&&l2!=NULL) {
            //两个链表长度都覆盖到的节点
            sum = l1->val + l2->val;
            sum += addNum;
            int val = sum%10;
            node->val = val;
            
            l1 = l1->next;
            l2 = l2->next;
            
        }else if (l1!=NULL) {
            
            sum = l1->val;
            sum += addNum;
            int val = sum%10;
            node->val = val;
            
            l1 = l1->next;
            
        }else if (l2!=NULL) {
            
            sum = l2->val;
            sum += addNum;
            int val = sum%10;
            node->val = val;
            
            l2 = l2->next;
            
        }else {//两个链表都遍历结束但尾节点相加还有进位
            
            node->val = 1;
            addNum = 0;
            sum = 0;
        }
        
        addNum = sum>=10 ? 1 : 0;
        
        if(head==NULL){
            head = node;
        }else{
            curNode->next = node;
        }
        curNode = node;
        
    }
    
    return head;
}

int main()
{
    //初始化两个测试链表 [6->7->8->9->NULL] 与 [1->2->3->4->5->NULL]
    struct ListNode *curNode = NULL;
    int position = 1;
    int listLength = 9;
    
    struct ListNode *head1 = NULL;
    int number1 = 0;
    while (listLength>5) {
        struct ListNode *node = (struct ListNode *)malloc(sizeof(struct ListNode));
        node->val = listLength;
        node->next = NULL;
        if(head1==NULL){
            head1 = node;
        }else{
            curNode->next = node;
        }
        curNode = node;
        number1 += listLength*position;
        position*=10;
        listLength--;
    }
    printf("第一个数是：%d\n",number1);
    
    position = 1;
    struct ListNode *head2 = NULL;
    int number2 = 0;
    while (listLength>0) {
        struct ListNode *node = (struct ListNode *)malloc(sizeof(struct ListNode));
        node->val = listLength;
        node->next = NULL;
        if(head2==NULL){
            head2 = node;
        }else{
            curNode->next = node;
        }
        curNode = node;
        number2 += listLength*position;
        position*=10;
        listLength--;
    }
    printf("第二个数是：%d\n",number2);
    
    position = 1;
    struct ListNode *addList = addTwoNumbers(head1,head2);
    int sum = 0;
    while (addList!=NULL) {
        sum += addList->val*position;
        position*=10;
        addList = addList->next;
    }
    printf("两数之和是：%d\n",sum);
    return 0;
}
