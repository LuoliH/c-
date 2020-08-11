### 题目
两数相加

### 题意
给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。

如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。

您可以假设除了数字 0 之外，这两个数都不会以 0 开头。

示例：

输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)

输出：7 -> 0 -> 8

原因：342 + 465 = 807

~~~ c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{
	int c=0;
	struct ListNode* head=(struct ListNode *)malloc(sizeof(struct ListNode)),*cur=head,*del=head;
	 //head虚拟头结点地址,cur当前节点地址,del用于删除虚拟头结点
	while(l1!=NULL||l2!=NULL||c)
    {
        cur->next=(struct ListNode *)malloc(sizeof(struct ListNode));
        cur=cur->next;
        l1=l1!=NULL?(c+=l1->val,l1->next):l1;
        l2=l2!=NULL?(c+=l2->val,l2->next):l2;
        cur->val=c%10;
        c=c/10;
    }
    cur->next=NULL;
    head=head->next;
    free(del);
    return head;
}
~~~
