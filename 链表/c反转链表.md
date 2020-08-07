### 题目
反转链表

### 题意
反转一个单链表。

示例:

输入: 1->2->3->4->5->NULL

输出: 5->4->3->2->1->NULL
~~~ c
struct ListNode* reverseList(struct ListNode* head)
{
	if(head==NULL||head->next==NULL)		//空链表或者只有一个节点的链表 
	{
		return head;
	}
	struct ListNode* p=head->next,*q=head->next->next,*t;	//q从第3个结点开始 ，t为q的下一个结点，防止断链
	p->next=head;
	head->next=NULL;	//将链表的前两个结点反转，为后面在头部逐个添加结点做准备
	while(q)
	{
		t=q->next;	//t指向q的下一个结点
		q->next=p;	//q连上p
		p=q;	//p指向其前一个结点（向前移动一位）
		q=t;	//q向后移动
	}
	return p;
 } 
~~~
