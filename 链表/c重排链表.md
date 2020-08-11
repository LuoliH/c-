### 题目
重排链表

### 题意
给定一个单链表 L：L0→L1→…→Ln-1→Ln ，

将其重新排列后变为： L0→Ln→L1→Ln-1→L2→Ln-2→…

你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。

示例 1:

给定链表 1->2->3->4, 重新排列为 1->4->2->3.

示例 2:

给定链表 1->2->3->4->5, 重新排列为 1->5->2->4->3.

~~~ c 
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
//计算链表的长度
int num_size(struct ListNode*head){
    if(!head)   return 0;
    return num_size(head->next)+1;
}
//反转链表函数
struct ListNode* reverseList(struct ListNode* head){
    struct ListNode *cur = NULL, *pre = head;
    while(pre != NULL){
        struct ListNode *t = pre->next;
        pre ->next = cur;
        cur = pre;
        pre = t;
    }
    return cur;
}
void reorderList(struct ListNode* head){
    if(!head)   return NULL;
    int n = num_size(head),j=(n+1)/2-1;
    struct ListNode*p=head,*head2=NULL;
    while(j--)  p = p->next;        //找到分割位置
    head2 = reverseList(p->next);   //第二段链表
    p->next = NULL;
    p=head;
//将第二段插入第一段链表
    while(head2){
        struct ListNode*Next = p->next,*temp = head2->next;
        p->next = head2;
        head2->next = Next;
        head2 = temp;
        p=Next;
    }
}
~~~
