### 题目
奇偶链表

### 题意
给定一个单链表，把所有的奇数节点和偶数节点分别排在一起。请注意，这里的奇数节点和偶数节点指的是节点编号的奇偶性，而不是节点的值的奇偶性。

请尝试使用原地算法完成。你的算法的空间复杂度应为 O(1)，时间复杂度应为 O(nodes)，nodes 为节点总数。

示例 1:

输入: 1->2->3->4->5->NULL

输出: 1->3->5->2->4->NULL

示例 2:

输入: 2->1->3->5->6->4->7->NULL 

输出: 2->3->6->7->1->5->4->NULL

说明:

应当保持奇数节点和偶数节点的相对顺序。

链表的第一个节点视为奇数节点，第二个节点视为偶数节点，以此类推。

~~~ c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */



//这题比较简单
//直接通过修改指针把链表拆分成 奇数位置链表 和 偶数位置链表， 然后把偶数链表头接到奇数链表尾即可
struct ListNode* oddEvenList(struct ListNode* head){
    if(head ==NULL || head->next==NULL) return head;
    struct ListNode* evenHead=head->next;  //记录偶数位置链表的表头，用于最后奇偶相连
    struct ListNode* odd=head;            //奇数位置指针
    struct ListNode* even=odd->next;      //偶数位置指针
    while(even!=NULL && even->next!=NULL)
    {
        odd->next=odd->next->next;         //指向后面第二个结点，即把奇数和偶数分开了
        even->next=even->next->next;
        odd=odd->next;
        even=odd->next;
    }
    odd->next=evenHead;
    return head;
}
~~~
