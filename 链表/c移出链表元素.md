### 题目
移出链表元素

### 题意
删除链表中等于给定值 val 的所有节点。

示例:

输入: 1->2->6->3->4->5->6, val = 6

输出: 1->2->3->4->5

~~~ c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* removeElements(struct ListNode* head, int val){
    struct ListNode* prev=head;
    while(head!=NULL&&head->val==val) {
        head=head->next;
    }
    while(prev!=NULL){
        if(prev->next!=NULL && prev->next->val==val) prev->next=prev->next->next;
        else prev=prev->next;
    }
    return head;
      
}
~~~
