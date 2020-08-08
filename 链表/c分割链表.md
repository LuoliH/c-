### 题目
分割链表

### 题意

编写程序以 x 为基准分割链表，使得所有小于 x 的节点排在大于或等于 x 的节点之前。如果链表中包含 x，x 只需出现在小于 x 的元素之后(如下所示)。分割元素 x 只需处于“右半部分”即可，
其不需要被置于左右两部分之间。
输入

[1,4,3,2,5,2]
3

输出

[1,2,2,4,3,5] （对）

预期结果

[2,2,1,5,3,4] （对）

只要小于目标数的整数在左边大于目标数的整数在右边就行

~~~ c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* partition(struct ListNode* head, int x){
	if(head==NULL)
	return head;
	if(head->next==NULL)
	return head;  
	struct ListNode* h1 = (struct ListNode*)malloc(sizeof(struct ListNode)), *t1 = h1;
	struct ListNode* h2 = (struct ListNode*)malloc(sizeof(struct ListNode)), *t2 = h2;
	t1->next = NULL; 
	t2->next = NULL;
	while(head!=NULL)
	{
		if(head->val<x)
		{
			t1->next=head;
			t1=t1->next;
		}
		else
		{
		  t2->next=head;
		  t2=t2->next;	
		}
		head=head->next;
	}
	t1->next=h2->next;
	t2->next=NULL;
	return h1->next;
}
~~~
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
