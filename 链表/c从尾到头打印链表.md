### 题目
从尾到头打印链表

### 题意
输入一个链表的头节点，从尾到头反过来返回每个节点的值（用数组返回）。

示例 1：

输入：head = [1,3,2]

输出：[2,3,1]

限制：

0 <= 链表长度 <= 10000

~~~ c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* reversePrint(struct ListNode* head, int* returnSize)
{
	int num=0;
	int i;
	struct ListNode* p=head;
	if(head==NULL){
        *returnSize=0;
        return NULL;
    }
	while(p!=NULL)
	{
		p=p->next;
		num++;
	}
	p=head;
	int *res=(int *)malloc(sizeof(int)*num);
	for(i=0;i<num;i++)
	{
		res[num-i-1]= p->val;
		p=p->next;
	}
	*returnSize=num;
	return res;
}
~~~
